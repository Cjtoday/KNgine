#ifndef __K_FILEHANDLER_H__
#define __K_FILEHANDLER_H__


#include <string>
#include <vector>


class K_FileHandler
{

public:
	K_FileHandler() {};
	virtual ~K_FileHandler() {};

	virtual void readTextToString(const char* fileName, std::string& textData) = 0;
	virtual void writeTextBufferToFile(const char* fileName, const std::string& textData) = 0;

	virtual void readBinaryToBuffer(const char* fileName, std::vector<unsigned char>& dataBuffe) = 0;
	virtual void writeBinaryToBuffer(const char* fileName, const std::vector<unsigned char>& dataBuffer) = 0;

	virtual void getDirectoryContents(std::vector<std::string>& outDirContents, std::string directory) = 0;
};


#endif // __K_FILEMANAGER_H__

