#include <Windows.h>

// FUN_00711a60
unsigned int MemoryAllocator(int param_1, unsigned int param_2, int param_3) {
	unsigned int* pointer = (unsigned int*)0x28389f00;

	if (param_2 < 2) {
		param_2 = 1;
	}

	int value = param_2 + 4;
	int* allocated = (int *)malloc(value + param_1);
	if (allocated == NULL) {
		return 0;
	}

	unsigned int uVar2 = (int)allocated + param_2 + 3 & ~(param_2 - 1);
	*(char*)(uVar2 - 3) = (char)uVar2;
	*(int*)(uVar2 - 1) = param_3;
	param_1 = (int)value;
	*(int*)(uVar2 - 2) = param_1;
	*(char*)(uVar2 - 4) = (char)param_2;
	*(char*)allocated = (char)param_2;
	int* puVar1 = (int*)0x28389f00;

	InterlockedExchangeAdd((LONG *)(0x28389f00 + param_3 * 0x18 + 4), 1);
	InterlockedExchangeAdd((LONG *)(puVar1 + param_3 * 0x18 + 8), param_2 + 4);
	InterlockedExchangeAdd((LONG *)(puVar1 + param_3 * 0x18 + 0xc), value);
	
	return uVar2;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	return 0;
}