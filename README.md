# CMake Shared Library

This project can be used as a starting template to create a shared library (.dll on Windows / .so on Linux).

The notable features of this template are the following:
- `CMakePresets.json` to configure the build environment. CMake version 3.19 is required in order to support this functionality:
  - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-presets-vs?view=msvc-160) has added support since version 16.10
  - [CLion](https://www.jetbrains.com/help/clion/cmake-presets.html) has added support since version 2021.2
- install and export support;
- [GoogleTest](https://github.com/google/googletest) unit testing using `FetchContent` which downloads the external library automatically on configure;

## How to build

```
cmake --preset <preset-name> 
cmake --build --preset <preset-name>
cmake --build --preset <preset-name> -t <install-target-name>
```

```
cmake --preset msvc-x86-debug
cmake --build --preset msvc-x86-debug
cmake --build --preset msvc-x86-debug -t INSTALL
```
