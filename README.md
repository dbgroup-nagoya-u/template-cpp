# Hello World

![Unit Tests](https://github.com/dbgroup-nagoya-u/template-cpp/workflows/Unit%20Tests/badge.svg?branch=main)

**Note**: set your repository URL to show CI status.

## Build

### Prerequisites

Describe setting steps for this repository.

```bash
sudo apt update && sudo apt install -y build-essential cmake
```

### Build Options

List build options.

- `BUILD_TESTS`: build unit tests if `on` (default: `off`).

### Build and Run Unit Tests

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=on ..
make -j
ctest -C Release
```
