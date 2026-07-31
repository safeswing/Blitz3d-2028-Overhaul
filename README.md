Scroll down for mod!

## Blitz3D open source release.

You will need to install Microsoft Visual Studio. Any recent version should be OK, tested with community editions 2017 and 2022. 

When selecting components to install, select "Desktop development with C++", "MFC and ATL support" and "ASP.NET and web development".

### To build with cmake

* Do something like this in the root blitz3d source directory:

``` bash
mkdir cmake-build
cd cmake-build
cmake -G "Visual Studio 17 2022" -A Win32 -DCMAKE_BUILD_TYPE=RelMinSize ..
cmake --build .
```

* Build results should appear in the _release directory - look for Blitz3D.exe there and run it!
 

### To build with Visual Studio

* Open blitz3d.dsw in Visual Studio.

* Select release config and rebuild the entire solution.

* Build results should appear in the _release directory - look for Blitz3D.exe there and run it!
 
* You can also try building the debug version, although this hasn't been well tested.


### Too lazy to build?

* Grab the prebuilt version from https://blitzresearch.itch.io/


### FMOD dll required!

* This version of blitz3D uses the dynamic version of the fmod audio lib. When redistributing executables built with Blitz3D you will need to include the fmod.dll file found in the _runtime/bin directory with your programs. This should be placed in the same directory as your program's executable.

--------------------------
Blitz3d 2027
You will need to install Microsoft Visual Studio, as the original one says 2017,2022 should be fine. and 2026 (tested by me)
Make sure to download MSVC ATL and MFC v14.51 if it is visual studio community 2026 it should come installed default but double check. and follow original ones too



