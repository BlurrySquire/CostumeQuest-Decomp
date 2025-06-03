#pragma once

#include <cstdint>

#include <Windows.h>

uintptr_t VAtoRVA(uintptr_t address);

struct SeedApp_vtable {
	SeedApp_vtable* (__fastcall *FUN_004024a0)(SeedApp_vtable* param_1);
	void* field01_0x04;
	void* field02_0x08;
	void* field03_0x0c;
	void* field04_0x10;
	void* field05_0x14;
	void* field06_0x18;
	void* field07_0x1c;
	void* field08_0x20;
	void* field09_0x24;
	void* field10_0x28;
	void* field11_0x2c;
	void* field12_0x30;
	void (__thiscall *FUN_00560220)(SeedApp* instance, int nCmdShow, LPSTR lpCmdLine) = (void (__thiscall *)(SeedApp*, int, LPSTR))VAtoRVA(0x560220);
	void* field14_0x38;
	void* field15_0x38;
	void* field16_0x40;
	void* field17_0x44;
	void* field18_0x48;
	void* field19_0x4c;
	void* field20_0x50;
	void* field21_0x54;
	void* field22_0x58;
	void* field23_0x5c;
	void* field24_0x60;
	void* field25_0x64;
	void* field25_0x68;
	void* field26_0x6c;
	void* field27_0x70;
};

struct SeedApp {
	SeedApp_vtable* vtable;
};

SeedApp* (*SeedApp_ctor)() = (SeedApp* (*)())VAtoRVA(0x402360);