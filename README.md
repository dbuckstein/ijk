# ijk
ijk: an open-source, cross-platform, light-weight, c-based rendering framework


## Project Guidelines
This section outlines the core guidelines, values and rules in the framework.

### Coding Standards
* The framework is programmed in C, using strictly data structures, free functions and data-oriented design/architecture.
* Some parts of the framework may be written in assembly for speed.
* No C++ is allowed in framework, with the exception of strictly non-member operators for mathematical purposes. Commits from forks with C++ syntax will not be pulled.
* All headers must be C++ friendly for consumption only. Use (extern "C" {...}) in case a user's C++ file consumes a framework header. Also use typedefs to allow C++ structure naming conventions to be used in C (e.g. typedef struct StructureName StructureName;).
* For graphics implementations, use cross-platform, C-based APIs/SDKs (e.g. Vulkan, OpenGL) and their respective shading languages or binary formats (GLSL, SPIR-V).
* All functions must be documented before implementation. Comment interfaces/prototypes with brief descriptions, member/parameter names and descriptions and validation notes, and possible return cases denoting success, warnings or failures.

### Repository Standards
* The main branch for versioning and releases is 'master'.
* The main branch for development and release candidates is 'dev/ijk'.
* Branches are named with a path format (e.g. dev/feature/subfeature) to indicate parent/child branch relationships.
* Branches may only merge with direct parent and direct child branches.
* Projects must treat warnings as errors; if there is any sort of issue, no matter how minor, fix it!


## To-Do
This section outlines known tasks to be completed and that have been completed.

### Framework Structure
#### Utilities
- [x] locate VS (Windows)
- [x] launch solution/workspace (Windows)
#### Windows Projects
- [x] SLN/WORKSPACE
- [x] APP: player - application entry and loading plugins
- [x] DLL: plugin - extensions for player
- [x] LIB: platform - platform-specific operations
- [x] LIB: math - standalone collection of math utilities
- [x] LIB: base - standalone collection of base utilities
- [ ] LIB: renderer - all graphics (per SDK or integrate with platform library)
- [ ] APP: testing - unit testing framework (standalone or integrate with player application)

### Code
#### General
- [x] core config
- [x] core macros
- [x] core types
- [x] core timer
- [x] core thread
- [x] core stream
- [ ] core memory - implemented basics, primary functions not complete
- [x] basic input
- [ ] gamepad input - implemented xinput for Windows
#### Math
- [ ] stats (flt, dbl, int)
- [ ] random (flt, dbl, int)
- [ ] sqrt (flt, dbl)
- [ ] interpolation (flt, dbl)
- [ ] trigonometry (flt, dbl)
- [ ] vector (flt, dbl, int)
- [ ] matrix (flt, dbl, int)
- [ ] quaternion (flt, dbl)
- [ ] dual quaternion (flt, dbl)
- [ ] extension: managed vector (flt, dbl)
- [ ] extension: managed transformation (flt, dbl)
- [ ] extension: geometry generation (flt)
- [ ] extension: basic physics (flt)
- [ ] extension: basic blending (flt)
#### Graphics
- [ ] test window in app
- [ ] Vulkan context in app
- [ ] basic geometry in app
