# Hello World

[![Ubuntu-20.04](https://github.com/dbgroup-nagoya-u/template-cpp/actions/workflows/unit_tests.yaml/badge.svg)](https://github.com/dbgroup-nagoya-u/template-cpp/actions/workflows/unit_tests.yaml)

Note: you can get status badges from `Actions`-`<your_workflow_name>`-`...`-`Create status badge` in your repository.

- [Build](#build)
    - [Prerequisites](#prerequisites)
    - [Build Options](#build-options)
    - [Build and Run Unit Tests](#build-and-run-unit-tests)
- [Usage](#usage)

## Build

### Prerequisites

Describe setting steps for this repository.

```bash
sudo apt update && sudo apt install -y build-essential cmake libgflags-dev
cd <path_to_your_workspace>
git clone git@github.com:dbgroup-nagoya-u/template-cpp.git
```

Note: if your repository includes submodules, specify `--recurse-submodules` option.

```bash
git clone --recurse-submodules git@github.com:dbgroup-nagoya-u/template-cpp.git
```

### Build Options

Enumerate build options.

#### Build Options for Unit Testing

- `BUILD_TESTS`: build unit tests if `ON` (default: `OFF`).

### Build and Run Unit Tests

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON ..
make -j
ctest -C Release
```

## Usage

The following command displays available CLI options:

```bash
./hello_world --helpshort
```
