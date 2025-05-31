#include <Windows.h>

int WINAPI hooked_WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBoxA(NULL, "This is WinMain.", "CostumeQuest-Decomp", MB_OK | MB_ICONINFORMATION);

    return 0;
}

