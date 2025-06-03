#include <Windows.h>

#include <cstdint>

#include <steam/steam_api.h>

#include "globals.hpp"
#include "seed_app.hpp"

uint32_t (*FUN_00711c20)() = (uint32_t (*)())VAtoRVA(0x711c20);
uint32_t (*MemoryAllocator)(uint32_t, int, uint32_t) = (uint32_t (*)(uint32_t, int, uint32_t))VAtoRVA(0x0711a60);
uint32_t (*FUN_00401b80)() = (uint32_t (*)())VAtoRVA(0x401b80);
uint32_t (*FUN_0070b020)(uint32_t, uint32_t) = (uint32_t (*)(uint32_t, uint32_t))VAtoRVA(0x70b020);
void (*FUN_00719310)() = (void (*)())VAtoRVA(0x719310);

uint32_t __cdecl hooked_FUN_00711c20() {
    if ((Global::UINT_00a9e7b4 & 1) == 0) {
        Global::UINT_00a9e7b4 = Global::UINT_00a9e7b4 | 1;
        Global::UINT_00a9e7ac = (uint32_t)&Global::UINT_00a9e7b0;
        return 0xa9e7b0;
    }

    return Global::UINT_00a9e7ac;
}

int WINAPI hooked_WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    uint32_t local_8 = 0xffffffff;

    if (!SteamAPI_RestartAppIfNecessary(0x1c19c) && (Global::steam_init = SteamAPI_Init(), Global::steam_init)) {
        Global::steam_storage = SteamRemoteStorage();
        FUN_00711c20();
        uint32_t iVar3 = MemoryAllocator(0x50, 0x10, 3);
        if (iVar3 == 0) {
            if (Global::PTR_00a8ff38 != nullptr) {
                Global::PTR_00a8ff38();
            }
            Global::DAT_00a8f868 = 0;
        }
        else {
            Global::DAT_00a8f868 = FUN_00401b80();
        }

        int total_bytes;
        int available_bytes;

        Global::steam_storage->GetFileCount();
        Global::steam_storage->GetQuota(&total_bytes, &available_bytes);

        ISteamApps* steam_apps = SteamApps();
        if (steam_apps->BIsSubscribed()) {
            local_8 = 0;
            int iVar3 = FUN_0070b020(0x338, 4);
            if (iVar3 == 0) {
                Global::AppInstance = 0x0;
            }
            else {
                Global::AppInstance = SeedApp_ctor();
            }
            Global::AppInstance->vtable->FUN_00560220(Global::AppInstance, nCmdShow, lpCmdLine);
            FUN_00719310();

            if (Global::AppInstance != nullptr) {
                Global::AppInstance->vtable->FUN_004024a0((SeedApp_vtable*)Global::AppInstance->vtable->FUN_004024a0);
            }
            Global::AppInstance = nullptr;
            local_8 = 0xffffffff;

            SteamAPI_Shutdown();
        }
    }

    return 0;
}