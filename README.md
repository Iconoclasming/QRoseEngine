# QRoseEngine
A C++ cross-platform 3D game engine under development.

# Build
QRose Engine can be build on Windows (tested: Windows 7, Windows 8.1) and Linux (tested: Linux Mint 18).
## Windows
Visual Studio 2015 and CMake must be installed.
<ol>
<li>Clone repository</li>
<li>Create "build" directory in the root of cloned repository</li>
<li>Navigate to "build" directory</li>
<li>Execute:<br/><code>cmake ..</code></li>
<li>Open generated Visual Studio solution with your VS2015 and build project "BUILD_ALL"</li>
</ol>
## Linux
Linux Mint 18 was only tested. CMake is required to build the engine. Also, following packages must be installed:
<ul>
<li>g++</li>
<li>libx11-dev</li>
<li>xorg-dev</li>
<li>libglu1-mesa-dev</li>
<li>uuid-dev</li>
</ul>
To build QRose Engine:
<ol>
<li>Clone repository</li>
<li>Create "build" directory in the root of cloned repository</li>
<li>Navigate to "build" directory</li>
<li>Execute:<br/><code>cmake ..</code><br/><code>make</code></li>
</ol>
