# QRoseEngine
A C++ cross-platform 3D game engine under development. It's inspired by <a href="http://entity-systems.wikidot.com">Entity-Component-System</a> pattern.

# Build
QRose Engine can be built on Windows (tested: Windows 7, Windows 8.1) and Linux (tested: Linux Mint 18 64-bit).
## Windows
CMake must be installed. Visual Studio 2015 and Visual Studio 2017 RC are supported. 
To build on Windows using Visual Studio 2015:
<ol>
<li>Clone the repository</li>
<li>Create "build" directory in the root of cloned repository</li>
<li>Navigate to "build" directory</li>
<li>Execute:<br/><code>cmake ..</code></li>
<li>Open generated Visual Studio solution with your VS and build project "BUILD_ALL"</li>
</ol>
To build on Windows using Visual Studio 2017 RC:
<ol>
<li>Clone the repository</li>
<li>Open the root directory of repository in Visual Studio 2017 by hitting "File -> Open -> Folder"</li>
<li>Right click on file "CMakeLists.txt" in the root of directory in Visual Studio and select "Build"</li>
<li>After the build in "Output" window (make sure that "Show output from: CMake" is selected) will appear the string starting with 
"Build files have been written to:" - copy this path and paste it in the Explorer's address bar</li>
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
