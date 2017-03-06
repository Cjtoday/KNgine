#include "K_WinApiWindow.hpp"
#include "K_Error.hpp"





K_WinApiWindow::K_WinApiWindow() : _shouldClose(false)
{
	_hInstance = GetModuleHandle(NULL);
	initilizeKeyMapping();

}

K_WinApiWindow::~K_WinApiWindow(){}

K_WinApiWindow* K_WinApiWindow::createWindow(K_WindowConfig & config)
{
	K_WinApiWindow* window = new K_WinApiWindow();
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
		K_Error registerError("K_Window Error", "Failed to register winapi window.");
		K_Error::dump();
	}

	//create our window style
	DWORD windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_BORDER | WS_MINIMIZEBOX;

	//the window was registered, now create the actual window
	
	HWND windowHandle = CreateWindow
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
		window->getWindowInstance(),				//Instance of module associated with the window
		window					//I still have no idea how LPARAMS work or what they are
	);

	if (!windowHandle)
	{
		K_Error createWindowError("K_Window Error","winapi CreateWindow failed" );
		K_Error::dump();
	}
	window->setWindowHandle(windowHandle);
	return window;
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

void K_WinApiWindow::close()
{
	PostMessage(_hWindow, WM_CLOSE, WPARAM(), LPARAM());
}

bool K_WinApiWindow::shouldClose()
{
	return _shouldClose;
}

void K_WinApiWindow::swapBuffers()
{
	if (!SwapBuffers(_hDeviceContext))
	{
		K_Error error("K_Window Error", "Error swapping window buffer");
	}
}

void K_WinApiWindow::setInputCallback(K_InputCallback callback)
{
	_inputCallback = callback;
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
	LRESULT result;
	switch (message)
	{
	case WM_SYSKEYDOWN:
	case WM_KEYDOWN:
		//printf("K_KeyCode: %lu %lu Down.\n", wParam, mapKeyCode(wParam, lParam));
		(*_inputCallback)(this, mapKeyCode(wParam, lParam), K_KEY_STATE_DOWN);
		result = 0;
		break;
	case WM_SYSKEYUP:
	case WM_KEYUP:
		//printf("K_KeyCode: %lu Up.\n", mapKeyCode(wParam, lParam));
		result = 0;
		break;
	case WM_CREATE:
		_hWindow = hWnd;
		_hDeviceContext = GetDC(hWnd);

		createPixelFormatDescriptor();
		result = 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		_shouldClose = true;
		result = 0;
		break;
	default:
		result = DefWindowProc(hWnd, message, wParam, lParam);
	}
	return result; 
}

void K_WinApiWindow::initilizeKeyMapping()
{
	_keyMapping =
	{
		{ 0x30, K_KEY_0 },
		{ 0x31, K_KEY_1 },
		{ 0x32, K_KEY_2 },
		{ 0x33, K_KEY_3 },
		{ 0x34, K_KEY_4 },
		{ 0x35, K_KEY_5 },
		{ 0x36, K_KEY_6 },
		{ 0x37, K_KEY_7 },
		{ 0x38, K_KEY_8 },
		{ 0x39, K_KEY_9 },
		{ 0x41, K_KEY_A },
		{ 0x42, K_KEY_B },
		{ 0x43, K_KEY_C },
		{ 0x44, K_KEY_D },
		{ 0x45, K_KEY_E },
		{ 0x46, K_KEY_F },
		{ 0x47, K_KEY_G },
		{ 0x48, K_KEY_H },
		{ 0x49, K_KEY_I },
		{ 0x4A, K_KEY_J },
		{ 0x4B, K_KEY_K },
		{ 0x4C, K_KEY_L },
		{ 0x4D, K_KEY_M },
		{ 0x4E, K_KEY_N },
		{ 0x4F, K_KEY_O },
		{ 0x50, K_KEY_P },
		{ 0x51, K_KEY_Q },
		{ 0x52, K_KEY_R },
		{ 0x53, K_KEY_S },
		{ 0x54, K_KEY_T },
		{ 0x55, K_KEY_U },
		{ 0x56, K_KEY_V },
		{ 0x57, K_KEY_W },
		{ 0x58, K_KEY_X },
		{ 0x59, K_KEY_Y },
		{ 0x5A, K_KEY_Z },
		{ VK_TAB	 , K_KEY_TAB	},
		{ VK_CAPITAL , K_KEY_CAPSLK },
		{ VK_LSHIFT	 , K_KEY_LSHIFT },
		{ VK_LCONTROL, K_KEY_LCTRL	},
		{ VK_LMENU   , K_KEY_LALT	},
		{ VK_SPACE   , K_KEY_SPACE	},
		{ VK_RMENU   , K_KEY_RALT	},
		{ VK_RCONTROL, K_KEY_RCTRL	},
		{ VK_RSHIFT  , K_KEY_RSHIFT },
		{ VK_RETURN  , K_KEY_ENTER  },
		{ VK_LEFT    , K_KEY_LEFT	},
		{ VK_RIGHT   , K_KEY_RIGHT	},
		{ VK_UP      , K_KEY_UP		},
		{ VK_DOWN    , K_KEY_DOWN	},
		{ VK_ESCAPE	 , K_KEY_ESCAPE }	
	};

}

K_KeyCode K_WinApiWindow::mapKeyCode(unsigned long systemCode, unsigned long lParam)
{
	unsigned long code;
	

	unsigned long newCode;
	unsigned long scancode = (lParam & 0x00ff0000) >> 16;
	unsigned long extended = (lParam & 0x10000000) != 0;

	switch (systemCode)
	{
	case VK_SHIFT:
		newCode = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
		break;
	case VK_CONTROL:
		newCode = extended ? VK_RCONTROL : VK_LCONTROL;
		break;
	case VK_MENU:
		newCode = extended ? VK_RMENU : VK_LMENU;
		break;
	default:
		newCode = systemCode;
		break;
	}

	auto iter = _keyMapping.find(newCode);
	if (iter == _keyMapping.end())
	{
		code = K_KEY_UNSUPPORTED;
	}
	else
	{
		code = iter->second;
	}
	return code;
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
	
	// create opengl reder context and set it as the current context
	_hGlRenderContext = wglCreateContext(_hDeviceContext);
	if (!wglMakeCurrent(_hDeviceContext, _hGlRenderContext))
	{
		K_Error makeCurrentError("K_Window Error", "Could not set openGL render context");
		K_Error::dump();
	}

}

void K_WinApiWindow::setWindowHandle(HWND hwnd)
{
	_hWindow = hwnd;
}

HINSTANCE K_WinApiWindow::getWindowInstance()
{
	return _hInstance;
}


