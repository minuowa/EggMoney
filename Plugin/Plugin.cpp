// Plugin.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "XBase.h"
#include "GGameDemoHeader.h"
#include "Content.h"
#include "ContentPlugin.h"
extern "C"
{
    Plugin_API int Plugin_Init ( HWND mainWnd )
    {
		Content::Game.registerPlugin(new ContentPlugin());
        return Content::Game.init ( mainWnd );
    }
    Plugin_API bool Plugin_Update()
    {
        return Content::Game.loop ( );
    }
    Plugin_API void Plugin_ShutDown()
    {
		Content::Game.unregisterPlugin("ContentPlugin");
		return Content::Game.shutDown ( );
    }
}


