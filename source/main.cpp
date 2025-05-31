#include <Windows.h>

#include <stdio.h>

uintptr_t VAtoRVA(uintptr_t moduleBase, uintptr_t address) {
    return (address - 0x400000) + moduleBase;
}

int WINAPI hooked_WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBoxA(NULL, "This is WinMain.", "CostumeQuest-Decomp", MB_OK | MB_ICONINFORMATION);

    return 0;
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

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		void* address = (void*)VAtoRVA((uintptr_t)GetModuleHandle(nullptr), 0x402180);
		HookFunction(address, hooked_WinMain);
		if (address == NULL) {
			MessageBoxA(NULL, "Couldn't hook to 'WinMain'.", "CostumeQuest-Decomp", MB_OK | MB_ICONERROR);
			return FALSE;
		}

		MessageBoxA(NULL, "Functions have been hooked.", "CostumeQuest-Decomp", MB_OK | MB_ICONINFORMATION);	
	}

	return TRUE;
}