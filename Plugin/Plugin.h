#ifndef Plugin_h__
#define Plugin_h__

extern "C"
{
	Plugin_API int Plugin_Init(HWND mainWnd);
	Plugin_API bool Plugin_Update();
	Plugin_API void Plugin_ShutDown();
}

#endif // Plugin_h__

