# Technology Stack

## Programming Language
- **C++**: Modern C++ with STL support
- **Standard**: C++11 or later (uses std::vector, std::string)
- **Compiler**: MSVC (Microsoft Visual C++) v143

## Build System
- **IDE**: Visual Studio 2022 (indicated by vc143 toolset)
- **Project Type**: Visual C++ Console Application
- **Solution File**: MishloachManot.sln
- **Project File**: MishloachManot.vcxproj
- **Platform**: x64 (64-bit Windows)
- **Configuration**: Debug build

## Core Dependencies

### Standard Library Components
- `<iostream>` - Console I/O operations
- `<string>` - String handling (std::string)
- `<vector>` - Dynamic arrays (std::vector)

### Project Headers
- `Mishloach.h` - Main package management
- `Product.h` - Product and Kashrut enum
- `Address.h` - Address data structure
- `Gift.h` - Extended gift functionality

## Development Commands

### Build
```bash
# Open solution in Visual Studio
MishloachManot.sln

# Build from Visual Studio
Build → Build Solution (Ctrl+Shift+B)

# Or use MSBuild from command line
msbuild MishloachManot.sln /p:Configuration=Debug /p:Platform=x64
```

### Run
```bash
# Execute from Visual Studio
Debug → Start Without Debugging (Ctrl+F5)

# Or run directly
x64\Debug\MishloachManot.exe
```

### Clean
```bash
# From Visual Studio
Build → Clean Solution

# Or use MSBuild
msbuild MishloachManot.sln /t:Clean
```

## Build Artifacts

### Object Files (x64/Debug/)
- Address.obj
- Gift.obj
- Mishloach.obj
- MishloachManot.obj
- Product.obj

### Debug Information
- vc143.pdb - Program database for debugging
- vc143.idb - Incremental build state
- MishloachManot.ilk - Incremental linker file

### Executable
- x64/Debug/MishloachManot.exe - Main application

## Compiler Features Used
- **Pragma directives**: `#pragma once` for header guards
- **Namespaces**: `using namespace std`
- **Enumerations**: Type-safe enums (Kashrut, GiftSize)
- **Virtual functions**: Polymorphic behavior support
- **Friend functions**: Operator overloading
- **Static members**: Shared class data
- **Inline functions**: Getter methods in headers

## Platform Requirements
- **OS**: Windows (x64)
- **Visual Studio**: 2019 or later (v142/v143 toolset)
- **Runtime**: MSVC Runtime Libraries (Debug)
- **.NET**: Not required (native C++ only)

## File Encoding
- **Line Endings**: CRLF (Windows style - \r\n)
- **Character Set**: Supports Unicode (Hebrew characters in paths)
