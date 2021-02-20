# C++ template

![Unit Tests](https://github.com/dbgroup-nagoya-u/repo-name/workflows/Unit%20Tests/badge.svg?branch=main)

**Note**: set your repository URL to show CI status.

## Build

### Prerequisites

Describe setting steps for this repository.

```bash
sudo apt update && sudo apt install -y build-essential cmake
```

### Build Options

List build options.

**Note**: if you implement a library, add your library name to `BUILD_TESTS` such as `LIB_NAME_BUILD_TESTS` (in `CMakeList.txt`, `.vscode/cmake-variants.yaml`, and `.github/workflows/unit_tests.yaml`).

- `BUILD_TESTS`: build unit tests for this repository if `on` (default: `off`).

### Build and Run Unit Tests

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=on ..
make -j
ctest -C Release
```
