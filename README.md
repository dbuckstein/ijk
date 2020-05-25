# ijk
ijk: an open-source, cross-platform, light-weight, c-based rendering framework


## Project Guidelines
This section outlines the core guidelines, values and rules in the framework.

### Coding Standards
* The framework is programmed in C, with some parts in assembly.
* No C++ allowed in framework; forks with C++ will not be pulled.
* For graphics implementations, use cross-platform, C-based APIs/SDKs (e.g. Vulkan, OpenGL) and their respective shading languages or binary formats (SPIR-V, GLSL).
* Use data-oriented design and architecture.

### Repository Standards
* The main branch for versioning and releases is master.
* The main branch for development and release candidates is dev.
* Branches are named with a path format (e.g. dev/feature/subfeature) to indicate parent/child branch relationships.
* Branches may only merge with direct parent and direct child branches.
* Projects must treat warnings as errors; if there's any sort of issue, no matter how minor, fix it!


## To-Do
This section outlines known tasks to be completed and that have been completed.

### Framework Structure
#### Utilities
- [x] locate VS (Windows)
- [x] launch solution/workspace
#### Projects
- [x] SLN/WORKSPACE
- [x] APP: player
- [x] DLL: plugin
- [x] LIB: platform
- [x] LIB: math
- [x] LIB: core
- [ ] LIB: renderer (per SDK or integrate with platform)

### Code
#### General
- [x] core config
- [x] core macros
- [x] core types
- [x] core timer
- [x] core thread
- [x] core stream
- [x] core memory
- [ ] input devices
#### Math
- [ ] stats
- [ ] random
- [ ] sqrt
- [ ] interpolation
- [ ] trigonometry
- [ ] vector (flt, dbl, int)
- [ ] matrix (flt, dbl, int)
- [ ] quaternion
- [ ] dual quaternion
- [ ] managed vector
- [ ] transformation
- [ ] extension: basic blending
- [ ] extension: basic physics
- [ ] extension: geometry generation
#### Graphics
- [ ] test window in app
- [ ] Vulkan context in app
- [ ] basic geometry in app
