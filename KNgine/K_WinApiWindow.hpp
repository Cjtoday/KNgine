#ifndef __K_WINAPIWINDOW_HPP__
#define __K_WINAPIWINDOW_HPP__


#include "K_WindowConfig.hpp"
#include "K_Keys.hpp"
#include <Windows.h>



class K_WinApiWindow
{
public:
	~K_WinApiWindow();

	typedef void(*K_InputCallback)(K_WinApiWindow*, K_KeyCode, unsigned int);


	static K_WinApiWindow* createWindow(K_WindowConfig& config);
	virtual void showDefaultWindow();
	virtual void showWindow();
	virtual void hideWindow();
	virtual void maximizeWindow();
	virtual void minimizeWindow();
	virtual void restoreWindow();
	virtual void close();
	virtual bool shouldClose();
	virtual void swapBuffers();

	virtual void setInputCallback(K_InputCallback callback);

	

private:

	K_WinApiWindow();
	
	static LRESULT CALLBACK msgProxy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT msgHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void initilizeKeyMapping();
	virtual K_KeyCode mapKeyCode(unsigned long vkCode, unsigned long lParam );

	const HDC* getWindowsDeviceContext();

	void createPixelFormatDescriptor();
	void setWindowHandle(HWND hwnd);
	HINSTANCE getWindowInstance();

	PIXELFORMATDESCRIPTOR _pixelFormatDescriptor;
	HDC			_hDeviceContext;
	HWND		_hWindow;
	HINSTANCE	_hInstance;
	HGLRC		_hGlRenderContext;

	K_InputCallback _inputCallback;
	K_KeyMapping _keyMapping;
	bool _shouldClose;

};


#endif // __K_WINAPIWINDOW_HPP__
