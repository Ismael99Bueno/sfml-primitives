# sfml-primitives

sfml-primitives is a simple C++ library providing line primitive implementations for the SFML library. It features encapsulations in classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines, which draw a line resembling a spring.

## Features

- Line primitive implementations for SFML
- Classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines
- Easy integration with existing SFML projects

## Dependencies

sfml-primitives depends on the following libraries:

- [SFML](https://github.com/Ismael99Bueno/SFML): Simple and Fast Multimedia Library
- [vec-2D](https://github.com/Ismael99Bueno/vec-2D): a 2D vector implementation with usual operations
- [debug-tools](https://github.com/Ismael99Bueno/debug-tools): a set of tools for debugging
- [vector-view](https://github.com/Ismael99Bueno/vector-view): a header-only library for modifying the contents of a std::vector without letting the user modify its size

## Building and Usage

1. Build SFML from the [author's fork](https://github.com/Ismael99Bueno/SFML) using CMake. The SFML folder must be located in a `vendor` folder at the root of your workspace.
2. Reference the [SFML documentation](https://www.sfml-dev.org/tutorials/) for instructions on building the SFML library from source.
3. Build sfml-primitives using premake5 as a static library, with all other dependencies as premake5 projects.
4. Include all required dependencies as git submodules in your project.
5. Create a premake5 workspace with a user-implemented entry point that uses the sfml-primitives library.
6. Build the workspace with premake5 to create an executable.

## License

sfml-primitives is licensed under the MIT License. See LICENSE for more information.
