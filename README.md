# Blitz3D 2028 Overhaul
It focuses on being more modern and overhauling like some UI changes, bit64, viewport, error consoles (RL) and more!
Currently being developed. and is in Beta yet. however, first stable version will be released in 2027/2028 as the project is big and many major changes.
scroll down if you wanna build it right now. note that its still in development.





### Requirements
You will need **Microsoft Visual Studio** (tested with Community Editions 2017, 2022, and 2026).

When installing Visual Studio, select the following workloads and components:
* **Workload:** "Desktop development with C++"
* **Individual Components:**
  * For **VS 2022**: `v143 MSVC C++ MFC and ATL` note that it is not specially said exactly like this, as long it is v143 and MSVC MFC/ATL
  * For **VS 2026**: `MSVC C++ MFC and ATL v14.51` note that it is not specially said exactly like this, as long it is v14.51 and MSVC MFC/ATL

---

1. make sure blitzide is the startup project
2. set up env path in blitzide example mine by using clone repository in visual studio

BLITZPATH=C:\Users\Safeswing\source\repos\Blitz3d-2028-Overhaul\_release
$(LocalDebuggerEnvironment)
**in blitzide properties to configuration properties to debugging**

<img width="599" height="527" alt="image" src="https://github.com/user-attachments/assets/3d2d319e-ae04-4ccf-9d21-933479a20ddc" />

3.
  

---

### Building with CMake

Run the following commands in the root directory of the Blitz3D source:

**For Visual Studio 2026:**
```bash
mkdir cmake-build
cd cmake-build
cmake -G "Visual Studio 18 2026" -A Win32 -DCMAKE_BUILD_TYPE=RelMinSize ..
cmake --build .
```
**For Visual Studio 2022**
```bash
mkdir cmake-build
cd cmake-build
cmake -G "Visual Studio 17 2022" -A Win32 -DCMAKE_BUILD_TYPE=RelMinSize ..
cmake --build .
```
---

Building directly in Visual Studio

```bash
    Open blitz3d.slnx/sln (or blitz3d.dsw) in Visual Studio.

    Select the Release configuration. make sure it is Win32 platform

    Rebuild the entire solution.

    Build results will appear in the _release directory.
```

Prebuilt Releases
```bash
    Prebuilt binaries: Coming Soon!

    Legacy prebuilt versions: Available on itch.io.
```

---

FMOD DLL Required

This version of Blitz3D uses the dynamic version of the FMOD audio library. When redistributing executables built with Blitz3D, you must include fmod.dll (found in the _runtime/bin directory) in the same directory as your application's executable.
Below is Original README

--------------------------










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


