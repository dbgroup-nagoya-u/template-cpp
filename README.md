# Hello World

![Ubuntu-20.04](https://github.com/dbgroup-nagoya-u/template-cpp/workflows/Ubuntu-20.04/badge.svg?branch=main)

**Note**: set your repository URL to show CI status.

## Build

### Prerequisites

Describe setting steps for this repository.

```bash
sudo apt update && sudo apt install -y build-essential cmake
cd <path_to_your_workspace>
git clone --recursive git@github.com:dbgroup-nagoya-u/template-cpp.git
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

## Usage

The following command displays available CLI options:

```bash
./hello_world --helpshort
```
