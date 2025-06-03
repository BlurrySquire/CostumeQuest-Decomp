#pragma once

#include <Windows.h>

#include <cstdint>

int WINAPI hooked_WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

uint32_t __cdecl hooked_FUN_00711c20();