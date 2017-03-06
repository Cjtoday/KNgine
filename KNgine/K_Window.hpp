#ifndef __K_WINDOW_HPP__
#define __K_WINDOW_HPP__

#include "K_WindowConfig.hpp"
#include "K_Keys.hpp"

class K_Window
{
public:
	K_Window(){};
	virtual ~K_Window() = 0;

	typedef void(*K_InputCallback)(K_Window*, K_KeyCode, unsigned int);


	static K_Window* createWindow(K_WindowConfig& config);
	virtual void showDefaultWindow() = 0;
	virtual void showWindow() = 0;
	virtual void hideWindow() = 0;
	virtual void maximizeWindow() = 0;
	virtual void minimizeWindow() = 0;
	virtual void restoreWindow() = 0;
	virtual void close() = 0;
	virtual bool shouldClose() = 0;

	virtual void setInputCallback(K_InputCallback callback);

private:
	virtual void initilizeKeyMapping() = 0;

	K_InputCallback _inputCallback;
	K_KeyMapping _keyMapping;
	bool _shouldClose;


};


#endif // __K_WINDOW_HPP__
