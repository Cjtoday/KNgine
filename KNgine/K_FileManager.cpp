#include "K_FileManager.hpp"
#include "K_WinFileHandler.hpp"


bool K_FileManager::_initilized = false;
K_FileManager* K_FileManager::_singleInstance = nullptr;

K_FileManager::K_FileManager()
{
//TODO: ADD IFDEF FOR PLATFORM SHIT
	_fileHandler = new K_WinFileHandler();
}

K_FileManager::~K_FileManager()
{
	delete _fileHandler;
}

K_FileManager& K_FileManager::instance()
{
	if (!_initilized)
	{
		_singleInstance = new K_FileManager();
		_singleInstance->initilize();
	}

	return *_singleInstance;
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
