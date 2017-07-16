#ifndef __K_WINFILEHANDLER_H__
#define __K_WINFILEHANDLER_H__


#include "K_FileHandler.hpp"


class K_WinFileHandler : public K_FileHandler
{
public:

	K_WinFileHandler();
	~K_WinFileHandler();

	virtual void readTextToString(const char* fileName, std::string& textData);
	virtual void writeTextBufferToFile(const char* fileName, const std::string& textData);

	virtual void readBinaryToBuffer(const char* fileName, std::vector<unsigned char>& dataBuffe);
	virtual void writeBinaryToBuffer(const char* fileName, const std::vector<unsigned char>& dataBuffer);

	virtual void getDirectoryContents(std::vector<std::string>& outDirContents, std::string directory);
};


#endif // __K_WINFILEMANAGER_H__

