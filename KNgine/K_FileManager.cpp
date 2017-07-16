#include "K_FileManager.hpp"
#include "K_WinFileHandler.hpp"
#include "K_Error.hpp"


bool K_FileManager::_initilized = false;
K_FileManagerPtr K_FileManager::_singleInstance;


K_FileManager::K_FileManager()
{
}


K_FileManager::~K_FileManager()
{
	if (_fileHandler)
	{
		delete _fileHandler;
	}
}


K_FileManagerPtr K_FileManager::instance()
{
	if (!_initilized)
	{
		_singleInstance.reset(new K_FileManager());
		_singleInstance->initilize();
	}

	return _singleInstance;
}



void K_FileManager::initilize()
{
	_fileHandler = new K_WinFileHandler();
	_initilized = true;
}



void K_FileManager::readTextToString(const char* fileName, std::string & textData)
{
	_fileHandler->readTextToString(fileName, textData);
}


void K_FileManager::writeTextBufferToFile(const char* fileName, const std::string & textData)
{
	_fileHandler->writeTextBufferToFile(fileName, textData);
}


void K_FileManager::readBinaryToBuffer(const char* fileName, std::vector<unsigned char>& dataBuffer)
{
	_fileHandler->readBinaryToBuffer(fileName, dataBuffer);
}


void K_FileManager::writeBinaryToBuffer(const char* fileName, const std::vector<unsigned char>& dataBuffer)
{
	_fileHandler->writeBinaryToBuffer(fileName, dataBuffer);
}


void K_FileManager::getDirectoryContents(std::vector<std::string>& outDirContents, std::string directory)
{
	_fileHandler->getDirectoryContents(outDirContents, directory);
}


std::string K_FileManager::removeFileExtension(std::string filename)
{
	size_t lastindex = filename.find_last_of(".");
	return filename.substr(0, lastindex);
}


std::string K_FileManager::removeFilePath(std::string filepath)
{
	size_t lastindex = filepath.find_last_of("/");
	return filepath.substr(lastindex+1, filepath.size());
}


std::string K_FileManager::removeFilePathAndExtension(std::string filepath)
{
	return removeFileExtension(removeFilePath(filepath));
}


K_VertexBuffer K_FileManager::decodeObjFileToVertexBuffer(const std::string& objFile)
{
	K_VertexBuffer newVertexBuffer;
	std::vector<K_Position> positions;
	std::vector<K_UV> uvs;
	std::vector<K_Normal> normals;

	char* contextBuffer = NULL;
	char* line = NULL;

	unsigned int bufferSize = objFile.size() + 1;
	char* buffer = new char[bufferSize];
	memcpy(buffer, objFile.c_str(), bufferSize);

	char lineHeader[3];
	lineHeader[2] = '\0';

	line = strtok_s(buffer, "\n", &contextBuffer);
	do
	{
		//printf("%s\n", line);
		memcpy(lineHeader, &line[0], 2);
		if (strcmp(lineHeader, "v ") == 0 )
		{
			K_Position pos = {};
			sscanf_s(line, "v %f %f %f", &pos._x, &pos._y, &pos._z);
			positions.push_back(pos);
		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			K_UV uv = {};
			sscanf_s(line, "vt %f %f", &uv._u, &uv._v);
			uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0)
		{
			K_Normal normal = {};
			sscanf_s(line, "vn %f %f %f", &normal._x, &normal._y, &normal._z);
			normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f ") == 0)
		{
			unsigned int vertexIndex[3];
			unsigned int uvIndex[3];
			unsigned int normalIndex[3];
		
			int matches = sscanf_s(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9)
			{
				printf("%d", matches);
				K_Error fileParseError("Error Parsing .obj content", "invalid f format");
				K_Error::dump();
			}
			//create the vertex and add it to the vertex buffer;
			K_Vertex vert1 = {};
			K_Vertex vert2 = {};
			K_Vertex vert3 = {};
			
			//set the positions
			vert1._position = positions[vertexIndex[0] - 1];
			vert2._position = positions[vertexIndex[1] - 1];
			vert3._position = positions[vertexIndex[2] - 1];

			//set the uvs
			vert1._uv = uvs[uvIndex[0] - 1];
			vert2._uv = uvs[uvIndex[1] - 1];
			vert3._uv = uvs[uvIndex[2] - 1];

			//set the normals
			vert1._normal = normals[normalIndex[0] - 1];
			vert2._normal = normals[normalIndex[1] - 1];
			vert3._normal = normals[normalIndex[2] - 1];

			newVertexBuffer.addVertex(vert1);
			newVertexBuffer.addVertex(vert2);
			newVertexBuffer.addVertex(vert3);
		}
	} while ((line = strtok_s(NULL, "\n", &contextBuffer)) != NULL);

	free(buffer);
	return newVertexBuffer;

}
