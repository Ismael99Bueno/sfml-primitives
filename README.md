# sfml-primitives

sfml-primitives is a simple C++ library providing line primitive implementations for the SFML library. It features encapsulations in classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines, which draw a line resembling a spring.

## Features

- Line primitive implementations for SFML
- Classes for flat lines, flat line strips, thick lines, thick line strips, and spring lines
- Easy integration with existing SFML projects

## Dependencies

sfml-primitives depends on the following libraries:

- [SFML](https://github.com/ismawno/SFML)
- [glm](https://github.com/g-truc/glm)
- [debug-tools](https://github.com/ismawno/debug-tools)
- [container-view](https://github.com/ismawno/container-view)

The script [fetch_dependencies.py](https://github.com/ismawno/sfml-primitives/scripts/fetch_dependencies.py) automatically adds all the dependencies as git submodules, provided that the user has already created their own repository and included the current project as a git submodule (or at least downloaded it into the repository). To ensure all runs smoothly once the script has been executed, do not rename the folders containing the various dependencies. All external dependencies, those not created by the same author, will be added as submodules within a folder called [vendor](https://github.com/ismawno/sfml-primitives/vendor).

Once all dependencies have been fetched using [fetch_dependencies.py](https://github.com/ismawno/sfml-primitives/scripts/fetch_dependencies.py), execute the [generate_build_files.py](https://github.com/ismawno/sfml-primitives/scripts/generate_build_files.py) script to automatically build SFML from source as a shared library. Make sure to run [generate_build_files.py](https://github.com/ismawno/sfml-primitives/scripts/generate_build_files.py) after fetching all the dependencies to ensure a proper setup.


## Building and Usage

1. Ensure you have `premake5` and `make` installed on your system. `premake5` is used to generate the build files, and `make` is used to compile the project.
2. Create your own repository and include the current project as a git submodule (or at least download it into the repository).
3. Run the [fetch_dependencies.py](https://github.com/ismawno/sfml-primitives/scripts/fetch_dependencies.py) script located in the [scripts](https://github.com/ismawno/sfml-primitives/scripts) folder to automatically add all the dependencies as git submodules.
4. Execute the [generate_build_files.py](https://github.com/ismawno/sfml-primitives/scripts/generate_build_files.py) script located in the [scripts](https://github.com/ismawno/sfml-primitives/scripts) folder to automatically build [SFML](https://github.com/ismawno/SFML) from source as a shared library.
5. Create an entry point project with a `premake5` file, where the `main.cpp` will be located. Link all libraries and specify the kind of the executable as `ConsoleApp`. Don't forget to specify the different configurations for the project.
6. Create a `premake5` file at the root of the repository describing the `premake` workspace and including all dependency projects.
7. Build the entire project by running the `make` command in your terminal. You can specify the configuration by using `make config=the_configuration`.
8. To use sfml-primitives, include any of the primitive headers.

## License

sfml-primitives is licensed under the MIT License. See LICENSE for more information.
