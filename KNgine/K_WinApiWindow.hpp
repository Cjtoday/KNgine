#ifndef __K_WINAPIWINDOW_HPP__
#define __K_WINAPIWINDOW_HPP__


#include "K_WindowConfig.hpp"
#include <Windows.h>



class K_WinApiWindow
{
public:
	K_WinApiWindow();
	~K_WinApiWindow();

	virtual void createWindow(K_WindowConfig& config);
	virtual void showDefaultWindow();
	virtual void showWindow();
	virtual void hideWindow();
	virtual void maximizeWindow();
	virtual void minimizeWindow();
	virtual void restoreWindow();


private:
	
	static LRESULT CALLBACK msgProxy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT msgHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	inline static K_WinApiWindow* getObjectFromWindow(HWND hwnd)
	{
		return (K_WinApiWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	}

	virtual const HDC* getWindowsDeviceContext();

	virtual void createPixelFormatDescriptor();

	PIXELFORMATDESCRIPTOR _pixelFormatDescriptor;
	HDC			_hDeviceContext;
	HWND		_hWindow;
	HINSTANCE	_hInstance;

};

#endif // __K_WINAPIWINDOW_HPP__
