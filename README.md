# CPONG

A version of pong written in C.

_macOS only._

## Prerequisites

### Requirements

- C compiler (clang)
- make

### macOS (with Homebrew)

```bash
# Install the compiler
xcode-select --install

# Install raylib
brew install raylib
```

## Building

Clone the repository and navigate to the project directory:

```bash
git clone https://github.com/uri86/cpong.git
cd cpong
```

Build the project:

```bash
make
```

## Running

Run the game:

```bash
make run
```

Or run the executable directly:

```bash
./build/cpong
```

## Controls

- **Left Player**: W (up), S (down)
- **Right Player**: Up Arrow (up), Down Arrow (down)
- **Reset Score**: R

## Cleaning

To clean build artifacts:

```bash
make clean
```
