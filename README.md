# ijk
ijk: an open-source, cross-platform, light-weight, c-based rendering framework \
By Daniel S. Buckstein


## Project Guidelines
This section outlines the core guidelines, values and rules in the framework.

### Coding Standards
* The framework is programmed in C, using strictly data structures, free functions and data-oriented design/architecture.
* Some parts of the framework may be written in assembly for speed.
* No C++ is allowed in framework, with the exception of strictly non-member operators for mathematical purposes. Commits from forks with C++ syntax will not be pulled.
* All headers must be C++ friendly for consumption only. Use (extern "C" {...}) in case a user's C++ file consumes a framework header. Also use typedefs to allow C++ structure naming conventions to be used in C (e.g. typedef struct StructureName StructureName;).
* For graphics implementations, use cross-platform, C-based APIs/SDKs (e.g. Vulkan, OpenGL) and their respective shading languages and/or binary formats (GLSL, SPIR-V).
* All functions must be documented before implementation. Comment interfaces/prototypes with brief descriptions, member/parameter names and descriptions and validation notes, and possible return cases denoting success, warnings or failures.
* All functions should return integer types, with the exception of math functions which primarily operate on real (float or double) numbers, or real-based (vector) numbers.
* Standard C includes should appear first in source files, if ever, to prevent framework from potentially overwriting standard data types.

### Repository Standards
* The main branch for versioning and releases is 'master', no development allowed on this branch.
* The main branch for development, organization and setting up release candidates is 'dev/ijk'.
* Branches are named with a path format (e.g. dev/feature/subfeature) to indicate parent/child branch relationships.
* Branches may only merge with direct parent and direct child branches.
* Projects must treat warnings as errors; if there is any sort of issue, no matter how minor, fix it!
* Commits must include a brief description of what was accomplished or is being worked on, as well as a list of changes to affected files; use brief tags to summarize change details for each specific file (e.g. MOD/MODIFIED, ADD/ADDED, DEL/DELETED, REN/RENAMED, BUG for emergent issues or FIX for solved issues).


## To-Do
This section outlines known tasks to be completed and that have been completed.

### Framework Structure
#### Utilities
- [x] locate VS (Windows)
- [ ] locate VS robust (Windows)
- [x] launch solution (Windows)
- [ ] reset Intellisense (Windows)
- [ ] launch workspace (Mac OS)
- [ ] permanent path set
- [ ] build libraries for closed SDK
#### Framework Projects
- [x] Visual Studio SOLUTION
- [ ] Xcode WORKSPACE
- [x] APP: player - application entry and loading plugins
- [x] DLL: plugin - extensions for player
- [x] LIB: platform - platform-specific operations
- [x] LIB: math - standalone collection of math utilities
- [x] LIB: base - standalone collection of base utilities
- [ ] LIB: renderer - all graphics (per SDK or integrate with platform library)
- [ ] APP: testing - unit testing framework (standalone or integrate with player application)

### Code
#### Base
- [x] core config
- [x] core macros
- [x] core types
- [x] core timer
- [x] core thread
- [x] core stream
- [ ] core memory - implemented basics, primary functions not complete
- [x] basic input
- [ ] gamepad input - implemented xinput for Windows, need cross-platform support
- [ ] data structures and algorithms (lists, trees, graphs, uni/bi-dir, wt/unwt, traverse flag, etc.)
#### Math
- [x] sqrt (flt, dbl, real)
- [x] stats (flt, dbl, real, int)
- [x] random (flt, dbl, real, int)
- [x] interpolation (flt, real, dbl)
- [x] trigonometry (flt, real, dbl)
- [x] vector (flt, dbl, real, int, uint, bool)
- [x] matrix (flt, dbl, real)
- [x] quaternion & dual quaternion (flt, dbl, real)
- [ ] ext: basic physics; shapes, hulls, rays, tests (flt)
- [ ] ext: basic geometry; procedural, loaders (obj, mat, skin) (flt)
- [ ] ext: basic animation; poses, blend ops, timers, loaders (htr, clip, blend) (flt)
#### Player
- [ ] test console in app
- [ ] test window in app
- [ ] sample OpenGL context in app
- [ ] sample Vulkan context in app
#### Platform
- [x] Windows Visual Studio framework
- [ ] Mac OS Xcode framework
- [ ] console interface, decouple from app
- [ ] window interface, user-friendly menus
- [ ] programmer-friendly menu system
- [ ] OpenGL context and renderer source
- [ ] Vulkan context and renderer source
- [ ] platform-agnostic, renderer-agnostic renderer interface
- [ ] Visual Studio hotbuild utility and interface
- [ ] Xcode hotbuild utility and interface
#### Plugin
- [ ] hotbuild hooks
- [ ] basic platform-agnostic, renderer-agnostic app
