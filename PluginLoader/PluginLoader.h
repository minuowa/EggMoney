#ifndef PluginLoader_h__
#define PluginLoader_h__

#include <windows.h>
#include <assert.h>
extern "C"
{
    typedef int ( * Plugin_Init ) ( HWND );
    typedef bool ( * Plugin_Update ) ();
    typedef void ( * Plugin_ShutDown ) ();
}
class PluginLoader
{
public:
    Plugin_Init mInitFunc;
    Plugin_Update mUpdateFunc;
    Plugin_ShutDown mShutDownFunc;
    HMODULE mModule;

    PluginLoader()
        : mInitFunc ( nullptr )
        , mUpdateFunc ( nullptr )
        , mShutDownFunc ( nullptr )
        , mModule ( 0 )
    {

    }
    ~PluginLoader()
    {
        this->free();
    }
    void free()
    {
        if ( mModule )
        {
            //FreeLibrary ( mModule );
            mModule = 0;
        }
    }
    bool loadFromDll ( const char* dll )
    {
        mModule  = LoadLibraryA ( dll ); //¶¯Ì¬¼ÓÔØDll
        if ( !mModule )
        {
            assert ( mModule );
            return false;
        }
        mInitFunc = ( Plugin_Init ) GetProcAddress ( mModule, "Plugin_Init" );
        mUpdateFunc = ( Plugin_Update ) GetProcAddress ( mModule, "Plugin_Update" );
        mShutDownFunc = ( Plugin_ShutDown ) GetProcAddress ( mModule, "Plugin_ShutDown" );
        if ( !mInitFunc )
        {
            assert ( mInitFunc );
            return false;
        }
        if ( !mUpdateFunc )
        {
            assert ( mUpdateFunc );
            return false;
        }
        if ( !mShutDownFunc )
        {
            assert ( mShutDownFunc );
            return false;
        }
        return true;
    }
};

#endif // PluginLoader_h__
