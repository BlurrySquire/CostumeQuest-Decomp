# CostumeQuest-Decomp
This is a decomp of the Steam release of [Costume Quest](https://store.steampowered.com/app/115100/Costume_Quest/). Progress is likely to be really slow, as I know nothing about decomps.

## SHA256
```
Cq.exe D9E1EE3E7E78AE80B85F51B941B4D27BEB7A205312507452CC8718AEB2BB46CF
```

## Key Notes
- The compiler used is MSVC 9.X (Visual C++ 2008) because the binary imports ``MSVCP90.DLL`` and ``MSVCR90.DLL``. However, CMake with Visual Studio 2022 will be used for compiling, for ease of use.
- The Steamworks SDK is used in this game, but the exact version is unknown. Version 1.16 is assumed as it is the last version that released before the game. You must provide it yourself in ``project_root/steamworks_sdk_116`` to build.
- Even when this decomp is complete you still need various other games files to run the game.

## Building
```ps
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A Win32 -T host=x86
cd ../
cmake --build build
```