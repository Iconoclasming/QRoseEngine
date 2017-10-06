# QRoseEngine
A C++ cross-platform 3D game engine under development. It's inspired by
[Entity-Component-System](http://entity-systems.wikidot.com) pattern.

# Build
QRose Engine can be built on Windows (tested: Windows 7, Windows 8.1, Windows 10) and Linux
(tested: Linux Mint 18 64-bit).

You will need [cmake](https://cmake.org) - at least 3.5 version. For build under Linux you will
also need some additional libraries, as described in dedicated section below.

## Windows
CMake must be installed. Visual Studio 2015 and Visual Studio 2017 are supported.

To build on Windows using Visual Studio 2015:
1. Clone the repository
1. Create "build" directory in the root of cloned repository
1. Navigate to "build" directory
1. Execute: `cmake ..`
1. Open generated Visual Studio solution with your VS and build project "BUILD_ALL"

To build on Windows using Visual Studio 2017:
1. Clone the repository
1. Open the root directory of repository in Visual Studio 2017 by hitting `File -> Open -> Folder`
1. Right click on file `CMakeLists.txt` in the root of directory in Visual Studio and select
`Build`

## Linux
Linux Mint 18 64-bit was only tested. CMake is required to build the engine. Also, following
packages must be installed:
* g++
* libx11-dev
* xorg-dev
* libglu1-mesa-dev
* uuid-dev

To build QRose Engine:
1. Clone repository
1. Create "build" directory in the root of cloned repository
1. Navigate to "build" directory
1. Execute:
```
cmake ..
make
```
