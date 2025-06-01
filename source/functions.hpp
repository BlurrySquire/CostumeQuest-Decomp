#pragma once

#include <Windows.h>

uintptr_t VAtoRVA(uintptr_t address);

int WINAPI hooked_WinMain(HINSTANCE, HINSTANCE, LPSTR, int);