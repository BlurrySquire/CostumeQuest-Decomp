#pragma once

#include <cstdint>

#include <Windows.h>

uintptr_t VAtoRVA(uintptr_t address);

struct SeedApp_vtable;

struct SeedApp {
	SeedApp_vtable* vtable;
};

struct SeedApp_vtable {
	SeedApp* (__thiscall *FUN_004024a0)(SeedApp* instance, bool shouldDelete) = (SeedApp* (__thiscall *)(SeedApp*, bool))VAtoRVA(0x4024a0);
	int (__fastcall *FUN_004030f0)(SeedApp* instance) = (int (__fastcall *)(SeedApp*))VAtoRVA(0x4030f0);
	void (__fastcall *FUN_00406f60)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x406f60);
	void (__fastcall *FUN_00407020)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x407020);
	char (__fastcall *FUN_004073f0)(SeedApp* instance) = (char (__fastcall *)(SeedApp*))VAtoRVA(0x4073f0);
	void (__fastcall *thunk_FUN_00561fe0)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x561fe0); 
	void (__fastcall *FUN_00562090)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x562090);
	void (__thiscall *FUN_004ea700_a)(SeedApp* instance) = (void (__thiscall *)(SeedApp*))VAtoRVA(0x4ea700);
	void (__thiscall *FUN_004ea700_b)(SeedApp* instance) = FUN_004ea700_a;
	void (__thiscall *FUN_004ea700_c)(SeedApp* instance) = FUN_004ea700_a;
	void (__thiscall *FUN_004ea700_d)(SeedApp* instance) = FUN_004ea700_a;
	void (__fastcall *FUN_0071aad0)(SeedApp* instance) = (void (__fastcall *)(SeedApp*))VAtoRVA(0x71aad0);
	uint32_t (__thiscall *FUN_00561ce0)(SeedApp* instance, uint32 param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) = (uint32_t (__thiscall *)(SeedApp*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))VAtoRVA(0x561ce0);
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

SeedApp* (*SeedApp_ctor)() = (SeedApp* (*)())VAtoRVA(0x402360);