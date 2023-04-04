# sfml-primitives

sfml-primitives is a simple C++ library providing line primitive implementations for the SFML library. It features encapsulations in classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines, which draw a line resembling a spring.

## Features

- Line primitive implementations for SFML
- Classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines
- Easy integration with existing SFML projects

## Dependencies

sfml-primitives depends on the following libraries:

- [SFML](https://github.com/Ismael99Bueno/SFML): Simple and Fast Multimedia Library
- [vec-2D](https://github.com/Ismael99Bueno/vec-2D): A 2D vector implementation with usual operations
- [debug-tools](https://github.com/Ismael99Bueno/debug-tools): A set of tools for debugging
- [vector-view](https://github.com/Ismael99Bueno/vector-view): A header-only library for modifying the contents of a std::vector without letting the user modify its size

There are two Python scripts located in the `scripts` folder: `fetch_dependencies.py` and `setup.py`. `fetch_dependencies.py` automatically adds all the dependencies as git submodules, provided that the user has already created their own repository and included the current project as a git submodule (or at least downloaded it into the repository). To ensure all runs smoothly once the script has been executed, do not rename the folders containing the various dependencies. All external dependencies, those not created by the same author, will be added as submodules within a folder called `vendor`.

Once all dependencies have been fetched using `fetch_dependencies.py`, execute the `setup.py` script to automatically build SFML from source as a shared library. Make sure to run `setup.py` after fetching all the dependencies to ensure a proper setup.


## Building and Usage

1. Ensure you have `premake5` and `make` installed on your system. `premake5` is used to generate the build files, and `make` is used to compile the project.
2. Create your own repository and include the current project as a git submodule (or at least download it into the repository).
3. Run the `fetch_dependencies.py` script located in the `scripts` folder to automatically add all the dependencies as git submodules.
4. Execute the `setup.py` script located in the `scripts` folder to automatically build [SFML](https://github.com/Ismael99Bueno/SFML) from source as a shared library.
5. Create an entry point project with a `premake5` file, where the `main.cpp` will be located. Link all libraries and specify the kind of the executable as `ConsoleApp`. Don't forget to specify the different configurations for the project.
6. Create a `premake5` file at the root of the repository describing the `premake` workspace and including all dependency projects.
7. Build the entire project by running the `make` command in your terminal. You can specify the configuration by using `make config=the_configuration`.
8. To use poly-physx-app, include the `app.hpp` header. Implement your custom app by inheriting from the `app` class.

## License

sfml-primitives is licensed under the MIT License. See LICENSE for more information.
