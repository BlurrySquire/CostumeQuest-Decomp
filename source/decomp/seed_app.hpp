#pragma once

#include <cstdint>

#include <Windows.h>

uintptr_t VAtoRVA(uintptr_t address);

struct SeedApp_vtable {
	SeedApp* (__thiscall *FUN_004024a0)(SeedApp* instance, bool shouldDelete) = (SeedApp* (__thiscall *)(SeedApp*, bool))VAtoRVA(0x4024a0);
	int (__fastcall *FUN_004030f0)(SeedApp* instance) = (int (__fastcall *)(SeedApp*))VAtoRVA(0x4030f0);
	void (__fastcall *FUN_00406f60)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x406f60);
	void (__fastcall *FUN_00407020)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x407020);
	char (__fastcall *FUN_004073f0)(SeedApp* instance) = (char (__fastcall *)(SeedApp*))VAtoRVA(0x4073f0);
	void* field05_0x14;
	void* field06_0x18;
	void* field07_0x1c;
	void* field08_0x20;
	void* field09_0x24;
	void* field10_0x28;
	void* field11_0x2c;
	void* field12_0x30;
	void (__stdcall *FUN_00560220)(SeedApp* instance, int nCmdShow) = (void (__stdcall *)(SeedApp*, int))VAtoRVA(0x560220);
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