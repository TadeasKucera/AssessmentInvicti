# Login Simulation (C++)

This C++ project is my homework for Invicti job interview. The aim is to simulate a login via HTTP POST request to [http://testphp.vulnweb.com/login.php](http://testphp.vulnweb.com/login.php). I selected the [CPR](https://github.com/libcpr/cpr) library for this purpose.

## Project Structure

- `main.cpp`: The main source file containing the logic.
- `CMakeLists.txt`: CMake configuration file.

## Requirements

- A C++17 compatible compiler
- [CPR library](https://github.com/libcpr/cpr) installed
- [CMake](https://cmake.org/) 3.10 or newer

You can install CPR via your preferred method:
- With [vcpkg](https://github.com/microsoft/vcpkg)
- With [conan](https://conan.io/)
- From source
- Or link it manually to the path where you locally installed it

## Building the Project

In the root directory, run:

```sh
cmake -B build -S .
cmake --build build
```

[!NOTE]
If you're using `vcpkg`, you can add the toolchain file like this:

```sh
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
```

## Running the Program

After building, run the executable (path may vary based on your platform and configuration):
```sh
./build/assignment.exe
```

This will:

    Send a POST request with sample credentials.

    Save the HTML response to response.html.

    Open the response in your default browser and if it is not set, you will be prompted to select a new default browser.

Instead of the login page, we send the request to [http://testphp.vulnweb.com/userinfo.php](http://testphp.vulnweb.com/userinfo.php), because that is the page, that the login button sends the login request to:

```html
<form name="loginform" method="post" action="userinfo.php">
```
