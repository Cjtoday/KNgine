#ifndef __K_IWINDOWMANAGER_HPP__
#define __K_IWINDOWMANAGER_HPP__



class K_Window;
typedef unsigned int K_WindowHandle;
struct K_WindowSettings{};
class K_IWindowManager
{
public:
	K_IWindowManager();
	virtual ~K_IWindowManager();


	virtual K_Window* createWindow(const K_WindowSettings* settings) = 0;
	virtual void updateWindowSettings(const K_WindowSettings* newSettings) = 0;

	
private:



};



#endif // __K_IWINDOWMANAGER_HPP__
