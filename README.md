# CostumeQuest-Decomp
This is a decomp of the Steam release of [Costume Quest](https://store.steampowered.com/app/115100/Costume_Quest/). Progress is likely to be really slow, as I'm one person and still learning about reverse engineering. The goal of this decompilation is to be able to put together a full source code for Costume Quest that is functionally matching. Why choose only functional matching? The game was compiled with Visual C++ 2008, which can only be obtained by an offical CD or a backup on the internet. Going with a modern compiler simplifies the build process for everyone. I also need helpers, I'm a busy person so doing this myself will take a long time.

## Key Notes
- The C++03 standard is assumed to be used. It is the latest version before the game was released in 2011.

- The Steamworks SDK is used in this game, but the exact version is unknown. Version 1.16 is assumed as it is the last version that released before the game. You must provide it yourself in ``project_root/steamworks_sdk_116`` to build.

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