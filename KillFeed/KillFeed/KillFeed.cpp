#include "KillFeed.h"
#include "KillFeedConfig.h"
#include "KillFeedCommands.h"
#include "KillFeedHooks.h"
#pragma comment(lib, "ArkApi.lib")

void Init()
{
	Log::Get().Init("KillFeed");
	InitConfig();
	InitCommands();
	InitHooks();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		RemoveCommands();
		RemoveHooks();
		break;
	}
	return TRUE;
}