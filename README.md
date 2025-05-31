# CostumeQuest-Decomp
This is a decomp of the Steam release of [Costume Quest](https://store.steampowered.com/app/115100/Costume_Quest/). Progress is likely to be really slow, as I'm one person and still learning about reverse engineering. The goal of this decompilation is to be able to put together a full source code for Costume Quest that is functionally matching. This decomp is taking a hooking approach. This is where a DLL is patched into Costume Quest's import table. The DLL will then slowly be updated to replace more functions until all of them are replaced.

## Key Notes
- The C++98 standard is assumed to be used. C++03 is the latest version before the game was released in 2011, but seems unsupported by MSVC.

- The Steamworks SDK is used in this game, but the exact version is unknown. Version 1.16 is assumed as it is the last version that released before the game. You must provide it yourself in ``project_root/steamworks_sdk_116`` to build.

- The Costume Quest game files are expected to be placed in ``project_root/costume_quest``. The official costume quest executable is launched and then injected with the decompiled DLL which hooks the game's functions. You also need [Ultimate-ASI-Loader's](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases/tag/v8.2.0) ``dinput8.dll`` in the same folder.

- Double Fine Productions seems to have used an engine with the prefix ``Seed``. There is quite a few classes recovered from Ghidra with that prefix. For example: ``SeedApp``, ``SeedPlayerData``, ``SeedRules``, ``SeedSession``, ``SeedSessionManager``, and ``SeedSetupData``. These classes seem to possible present some aspects of a game engine.

## SHA256
```
Cq.exe D9E1EE3E7E78AE80B85F51B941B4D27BEB7A205312507452CC8718AEB2BB46CF
```

## Building
```ps
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A Win32 -T host=x86
cd ../
cmake --build build
```