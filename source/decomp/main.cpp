#include <Windows.h>

#include <cstdint>

#include <steam/steam_api.h>

#include "../functions.hpp"

bool* steam_init = (bool*)VAtoRVA(0xa8f860);
ISteamRemoteStorage** steam_storage = (ISteamRemoteStorage**)VAtoRVA(0xa8f86c);
uint32_t* DAT_00a8f868 = (uint32_t*)VAtoRVA(0xa8f868);

void (*PTR_00a8ff38)() = (void (*)())VAtoRVA(0xa8ff38);

uint32_t (*FUN_00711c20)() = (uint32_t (*)())VAtoRVA(0x711c20);
uint32_t (*MemoryAllocator)(uint32_t, int, uint32_t) = (uint32_t (*)(uint32_t, int, uint32_t))VAtoRVA(0x0711a60);
uint32_t (*FUN_00401b80)() = (uint32_t (*)())VAtoRVA(0x401b80);
uint32_t (*FUN_0070b020)(uint32_t, uint32_t) = (uint32_t (*)(uint32_t, uint32_t))VAtoRVA(0x70b020);

int WINAPI hooked_WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    uint32_t local_8 = 0xffffffff;

    if (!SteamAPI_RestartAppIfNecessary(0x1c19c) && (*steam_init = SteamAPI_Init(), *steam_init)) {
        *steam_storage = SteamRemoteStorage();
        FUN_00711c20();
        uint32_t iVar3 = MemoryAllocator(0x50, 0x10, 3);
        if (iVar3 == 0) {
            if (PTR_00a8ff38 != nullptr) {
                (*PTR_00a8ff38)();
            }
            *DAT_00a8f868 = 0;
        }
        else {
            *DAT_00a8f868 = FUN_00401b80();
        }

        int total_bytes;
        int available_bytes;

        (*steam_storage)->GetFileCount();
        (*steam_storage)->GetQuota(&total_bytes, &available_bytes);

        ISteamApps* steam_apps = SteamApps();
        if (steam_apps->BIsSubscribed()) {
            local_8 = 0;
            int iVar3 = FUN_0070b020(0x338, 4);
        }

        // Just to make sure the function reaches the end.
        // This will be gone when the function is complete.
        MessageBoxA(NULL, "We reached the end of WinMain!", "CostumeQuest-Decomp", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}