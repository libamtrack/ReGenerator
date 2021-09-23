## Description

This folder contains test C code for R package generator.

## Compilation and build

### Windows

1. Check if you have CMake installed in version at least 3.20. If not, install it. You can also add it to path, to 
2. Go to `C_samples` directory.
3. In command line, exec command `cmake -S . -B build`. If it does not work, it might mean, that you need to specify generator. Check, which version of Visual Studio you have, and exec command `cmake -S . -B build -G <generator>` replacing `<generator>` with generator name specified in [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html). You do not have to install Visual Studio, its basic tools should be already installed.
4. Now exec command `cmake --build build`.
5. If step above does not work, you need to find path to `MSBuild.exe` file and exec command `MSBuild build/C_samples.sln`. If you do not want to add MSBuild to path, then you need to pass whole apth to it, not just `MSBuild`. For Visual Studio 2017 path to MSBuild is `C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin`.
6. As a result, there should be executable file named `C_samples.exe` in `build/Debug` directory.

### Linux

1. Check if you have GCC, CMake version at least 3.20 and make installed. If not, install them.
2. Go to `C_samples` directory.
3. Exec command `cmake -S . -B build`. This will prepare compilation files, like Makfile.
4. To build project, exec command `cmake --build build`. You can also go to `build` directory and exec `make all`.
5. As a result, there should be executable file named `C_samples` in build directory.

