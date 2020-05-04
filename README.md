# ijk
ijk: an open-source, cross-platform, light-weight, c-based rendering framework


## Project Guidelines
This section outlines the core guidelines, values and rules in the framework.

### Coding Standards
* The framework is programmed in C, with some parts in assembly.
* No C++ allowed in framework. Forks with C++ will not be pulled.
* For graphics implementations, use cross-platform, C-based APIs/SDKs (e.g. Vulkan, OpenGL) and their respective shading languages or binary formats (SPIR-V, GLSL).
* Use data-oriented design and architecture.

### Repository Standards
* The main branch for versioning and releases is master.
* The main branch for development and release candidates is dev.
* Branches are named with a path format (e.g. dev/feature/subfeature) to indicate parent/child branch relationships.
* Branches may only merge with direct parent and direct child branches.


## To-Do
This section outlines known tasks to be completed and that have been completed.

### Framework Structure
#### Utilities
- [ ] locate VS (Windows)
- [ ] launch solution/workspace
#### Projects
- [ ] SLN/WORKSPACE
- [ ] APP: player
- [ ] LIB: player platform
- [ ] DLL: plugin
- [ ] LIB: math
- [ ] LIB: core
- [ ] LIB: renderer (per SDK)

### Code
#### General
- [ ] core utilities
- [ ] core integer types
- [ ] core float types
- [ ] core macros
#### Math
- [ ] stats
- [ ] random
- [ ] sqrt
- [ ] interpolation
- [ ] trigonometry
- [ ] vector
- [ ] matrix
- [ ] quaternion
- [ ] dual quaternion
- [ ] transformation
#### Graphics
- [ ] test window in app
- [ ] Vulkan context in app
- [ ] basic geometry in app
