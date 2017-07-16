#ifndef __K_FILEMANAGER_H__
#define __K_FILEMANAGER_H__


#include "K_FileHandler.hpp"
#include "K_Config.hpp"
#include "K_VertexBuffer.hpp"

#include<vector>
#include <string>
#include <memory>


class K_FileManager;
typedef std::shared_ptr<K_FileManager> K_FileManagerPtr;


class K_FileManager
{
public:

	static K_FileManagerPtr instance();
	~K_FileManager();

	void readTextToString(const char* fileName, std::string& textData);
	void writeTextBufferToFile(const char* fileName, const std::string& textData);
	
	void readBinaryToBuffer(const char* fileName,  std::vector<unsigned char>& dataBuffer);
	void writeBinaryToBuffer(const char* fileName, const std::vector<unsigned char>& dataBuffer);

	void getDirectoryContents(std::vector<std::string>& outDirContents, std::string directory);

	std::string removeFileExtension(std::string filename);
	std::string removeFilePath(std::string filepath);
	std::string removeFilePathAndExtension(std::string filepath);

	K_VertexBuffer decodeObjFileToVertexBuffer(const std::string& objFile);
	
private:

	static bool _initilized;
	static K_FileManagerPtr _singleInstance;

	K_FileHandler* _fileHandler;

	K_FileManager();
	void initilize();
};



#endif // __K_FILEMANAGER_H__

