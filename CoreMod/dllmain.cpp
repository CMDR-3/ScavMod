#include "Windows.h"
#include "ScavMod/ScavMod.h"

#pragma comment(lib, "scavlib.lib")

using namespace ScavMod;

/* Skeleton entry point because nothing we're going to be doing is related to outside of the game. */
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

class CoreMod : public IModDevice
{
    void OnInit() override
    {
        Logger::Log("Hello, World!");
    }

    void OnRenderUpdate() override
    {

    }
};

extern "C" SVEXPORT IModDevice * LoadMod()
{
    return new CoreMod();
}