#ifndef __K_FILEMANAGER_H__
#define __K_FILEMANAGER_H__

#include<vector>
#include <string>

#include "K_IFileHandler.hpp"
#include "K_Config.hpp"


class K_FileManager
{
public:

	static K_FileManager& instance();
	~K_FileManager();

	void readTextToString(const char* fileName, std::string& textData);
	void writeTextBufferToFile(const char* fileName, const std::string& textData);
	
	void readBinaryToBuffer(const char* fileName,  std::vector<unsigned char>& dataBuffer);
	void writeBinaryToBuffer(const char* fileName, const std::vector<unsigned char>& dataBuffer);
	
private:

	static bool _initilized;
	static K_FileManager* _singleInstance;

	K_IFileHandler* _fileHandler;

	K_FileManager();
	void initilize();


};


#endif // __K_FILEMANAGER_H__
