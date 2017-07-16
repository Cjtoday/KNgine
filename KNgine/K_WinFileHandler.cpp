#include "K_WinFileHandler.hpp"
#include "K_Error.hpp"

#include <stdio.h>
#include <windows.h>

K_WinFileHandler::K_WinFileHandler()
{
}



K_WinFileHandler::~K_WinFileHandler()
{
}



void K_WinFileHandler::readTextToString(const char * fileName, std::string & textData)
{


	FILE* fileHandle;
	char* buffer;
	long fileSize;

	fopen_s(&fileHandle, fileName, "rb");
if (!fileHandle)
{
	perror("Error");
	K_Error error1("Reading file to String", fileName);
	K_Error::dump();
}

fseek(fileHandle, 0, SEEK_END);
fileSize = ftell(fileHandle);
fseek(fileHandle, 0, SEEK_SET);

buffer = (char*)malloc(fileSize + 1);
if (!buffer)
{
	fclose(fileHandle);
	free(buffer);

	K_Error error2("Allocating memeory for file contents", fileName);
	K_Error::dump();
}



if (fread(buffer, fileSize, 1, fileHandle) != 1)
{
	fclose(fileHandle);
	free(buffer);

	K_Error error3("Reading file into buffer", fileName);
	K_Error::dump();
}

fclose(fileHandle);

textData.assign(buffer, buffer + fileSize);

free(buffer);
}



void K_WinFileHandler::writeTextBufferToFile(const char * fileName, const std::string & textData)
{
}



void K_WinFileHandler::readBinaryToBuffer(const char * fileName, std::vector<unsigned char>& dataBuffer)
{

	FILE* fileHandle;
	unsigned char* buffer;
	long fileSize;

	fopen_s(&fileHandle, fileName, "rb");
	K_Error error1("Reading file to byte buffer", fileName);
	if (!fileHandle)
	{
		perror("Error");
		K_Error::dump();
	}

	fseek(fileHandle, 0, SEEK_END);
	fileSize = ftell(fileHandle);
	fseek(fileHandle, 0, SEEK_SET);

	buffer = (unsigned char*)malloc(fileSize + 1);
	K_Error error2("Allocating memeory for file contents", fileName);
	if (!buffer)
	{
		K_Error::dump();
	}

	K_Error error3("Reading file into buffer", fileName);
	if (fread(buffer, fileSize, 1, fileHandle) != 1)
	{
		K_Error::dump();
	}

	fclose(fileHandle);

	dataBuffer.assign(buffer, buffer + fileSize);

	free(buffer);
}



void K_WinFileHandler::writeBinaryToBuffer(const char * fileName, const std::vector<unsigned char>& dataBuffer)
{

}


void K_WinFileHandler::getDirectoryContents(std::vector<std::string>& outDirContents, std::string directory)
{
	HANDLE dir;
	WIN32_FIND_DATA file_data;

	if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			const std::string file_name = file_data.cFileName;
			const std::string full_file_name = directory + "/" + file_name;
			const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

			if (file_name[0] != '.' && !is_directory)
			{
				outDirContents.push_back(full_file_name);
			}
		} while (FindNextFile(dir, &file_data));

	}
	FindClose(dir);
}

