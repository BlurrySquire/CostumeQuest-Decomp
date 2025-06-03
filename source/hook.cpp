#include <Windows.h>

#include "functions.hpp"

uintptr_t VAtoRVA(uintptr_t address);
void HookFunction(void* target, void* hook);

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		HookFunction((void*)VAtoRVA(((uintptr_t)0x402180)), hooked_WinMain);
        HookFunction((void*)VAtoRVA(((uintptr_t)0x711c20)), hooked_FUN_00711c20);

		MessageBoxA(NULL, "Functions have been hooked.", "CostumeQuest-Decomp", MB_OK | MB_ICONINFORMATION);
	}

	return TRUE;
}

uintptr_t VAtoRVA(uintptr_t address) {
    return (address - 0x400000) + (uintptr_t)GetModuleHandle(nullptr);
}

void HookFunction(void* target, void* hook) {
    DWORD oldProtect;
    VirtualProtect(target, 5, PAGE_EXECUTE_READWRITE, &oldProtect);

    uintptr_t relAddr = (uintptr_t)hook - (uintptr_t)target - 5;
    unsigned char patch[5] = {
		0xE9,
        (unsigned char)(relAddr & 0xFF),
        (unsigned char)((relAddr >> 8) & 0xFF),
		(unsigned char)((relAddr >> 16) & 0xFF),
		(unsigned char)((relAddr >> 24) & 0xFF)
    };

    memcpy(target, patch, 5);
    VirtualProtect(target, 5, oldProtect, &oldProtect);
}