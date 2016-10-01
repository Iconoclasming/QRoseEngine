# QRoseEngine
A C++ cross-platform 3D game engine under development. It's inspired by <a href="http://entity-systems.wikidot.com">Entity-Component-System</a> pattern.

# Build
QRose Engine can be built on Windows (tested: Windows 7, Windows 8.1) and Linux (tested: Linux Mint 18 64-bit).
## Windows
Visual Studio 2015 and CMake must be installed. To build under Windows:
<ol>
<li>Clone repository</li>
<li>Create "build" directory in the root of cloned repository</li>
<li>Navigate to "build" directory</li>
<li>Execute:<br/><code>cmake ..</code></li>
<li>Open generated Visual Studio solution with your VS2015 and build project "BUILD_ALL"</li>
</ol>
## Linux
Linux Mint 18 64-bit was only tested. CMake is required to build the engine. Also, following packages must be installed:
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
