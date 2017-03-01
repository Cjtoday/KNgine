#include "K_WinApiWindow.hpp"
#include "K_Error.hpp"



K_WinApiWindow::K_WinApiWindow()
{
	_hInstance = GetModuleHandle(NULL);

}

K_WinApiWindow::~K_WinApiWindow(){}

void K_WinApiWindow::createWindow(K_WindowConfig & config)
{
	//create and fillout the Window struct
	WNDCLASSEX wcex; 

	wcex.cbSize = sizeof(WNDCLASSEX);					//size of the WNDCLASSEX struct
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	//class styles
	wcex.lpfnWndProc = msgProxy;						//the window mesage handler
	wcex.cbClsExtra = 0;								//extra bytes allocated after window-class structure
	wcex.cbWndExtra = 0;								//extra bytes allocated after the window instance
	wcex.hInstance = GetModuleHandle(NULL);				//handle to instance that contains the window messag handler
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//handle to window class icon
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);			//handle to window class Cursor
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	//handle to bruch that paints the background
	wcex.lpszMenuName = NULL;							//resource name of class menu
	wcex.lpszClassName = config._className;				//name of the window
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);		//handle to window class small icon

	//register this window struct
	if (!RegisterClassEx(&wcex))
	{
		K_Error registerError("Registering new window", "Registration failed");
		K_Error::dump();
	}

	//create our window style
	DWORD windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_BORDER;

	//the window was registered, now create the actual window
	_hWindow = CreateWindow
	(
		config._className,		//name of the window class resource
		config._title,			//title of the window
		windowStyle,			//Window Style DWORD, or values together to creat style
		config._xCoord,			//Initial x coord
		config._yCoord,			//Initial y coord
		config._width,			//Initial window width
		config._height,			//Initial window height
		NULL,					//Parent window
		NULL,					//menu
		_hInstance,				//Instance of module associated with the window
		this					//I still have no idea how LPARAMS work or what they are
	);

	if (!_hWindow)
	{
		K_Error createWindowError("Create Window Error","CreateWindow failed" );
		K_Error::dump();
	}

}

void K_WinApiWindow::showDefaultWindow()
{
	ShowWindow(_hWindow, SW_SHOWDEFAULT);
	UpdateWindow(_hWindow);
}

void K_WinApiWindow::showWindow()
{
	ShowWindow(_hWindow, SW_SHOW);
	UpdateWindow(_hWindow);
}

void K_WinApiWindow::hideWindow()
{
	ShowWindow(_hWindow, SW_HIDE);
	UpdateWindow(_hWindow);
}

void K_WinApiWindow::maximizeWindow()
{
	ShowWindow(_hWindow, SW_MAXIMIZE);
	UpdateWindow(_hWindow);
}

void K_WinApiWindow::minimizeWindow()
{
	ShowWindow(_hWindow, SW_MINIMIZE);
	UpdateWindow(_hWindow);
}

void K_WinApiWindow::restoreWindow()
{
	ShowWindow(_hWindow, SW_RESTORE);
	UpdateWindow(_hWindow);
}

LRESULT K_WinApiWindow::msgProxy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	K_WinApiWindow* kWindow;

	LONG_PTR userData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
	if (userData)
	{
		kWindow = reinterpret_cast<K_WinApiWindow*>(userData);
		return kWindow->msgHandler(hWnd, message, wParam, lParam);
	}

	if (message == WM_NCCREATE)
	{
		LPCREATESTRUCT createStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		LPVOID lpCreateParam = createStruct->lpCreateParams;
		kWindow = reinterpret_cast<K_WinApiWindow*>(lpCreateParam);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(kWindow));
		
		return kWindow->msgHandler(hWnd, message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT K_WinApiWindow::msgHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		_hWindow = hWnd;
		_hDeviceContext = GetDC(hWnd);

		createPixelFormatDescriptor();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

const HDC * K_WinApiWindow::getWindowsDeviceContext()
{
	return &_hDeviceContext;
}

void K_WinApiWindow::createPixelFormatDescriptor()
{
	/*
	PFD_DRAW_TO_WINDOW: the buffer can draw to a window
	PFD_SUPPORT_OPENGL: the buffer supports OpenGL drawing
	PFD_DOUBLEBUFFER: The buffer is double-buffered. This flag and PFD_SUPPORT_GDI are mutually exclusive in the current generic implementation.

	*/
	DWORD pixelBufferFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

	_pixelFormatDescriptor =
	{
		sizeof(PIXELFORMATDESCRIPTOR),		//size of the PIXELFORMATDESCRIPTOR struct
		1,									//version of this PIXELFORMATDESCRIPTOR
		pixelBufferFlags,					//flags to specify the pixel buffer
		PFD_TYPE_RGBA,						//specifies the type of pixel data.
		32,									//specifies the number of color bitplanes in each color buffer
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,					//Number of bits for the depthbuffer
		8,					//number of bits for the stencilbuffer
		0,					//Number of Aux buffers in the framebuffer
		PFD_MAIN_PLANE,		//Ignored. Was used in legacy OpenGL
		0,
		0, 0, 0
	};

	int winPixelFormat = ChoosePixelFormat(_hDeviceContext, &_pixelFormatDescriptor);	//attempt to match an appropriate pixel format supported by a device context
	SetPixelFormat(_hDeviceContext, winPixelFormat, &_pixelFormatDescriptor);			
}
