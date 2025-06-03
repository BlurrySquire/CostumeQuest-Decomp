#pragma once

#include <cstdint>

#include <steam/steam_api.h>

uintptr_t VAtoRVA(uintptr_t address);

struct SeedApp;

namespace Global {
	bool& steam_init = *(bool*)VAtoRVA(0xa8f860);
	ISteamRemoteStorage*& steam_storage = *(ISteamRemoteStorage**)VAtoRVA(0xa8f86c);
	
	uint32_t& DAT_00a8f868 = *(uint32_t*)VAtoRVA(0xa8f868);

	void (*PTR_00a8ff38)() = (void (*)())VAtoRVA(0xa8ff38);

	SeedApp*& AppInstance = *(SeedApp**)VAtoRVA(0xa8f81c);

	uint32_t& UINT_00a9e7b4 = *(uint32_t*)VAtoRVA(0xa9e7b4);
	uint32_t& UINT_00a9e7ac = *(uint32_t*)VAtoRVA(0xa9e7ac);
	uint32_t& UINT_00a9e7b0 = *(uint32_t*)VAtoRVA(0xa9e7b0);
}