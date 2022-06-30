# cg22-u10
Repository for the programming exercise on practice sheet 10 of the computer graphics module at Freie Universität Berlin

## HOW TO BUILD (Linux)

### Prerequisits

- gcc
- cmake
- conan

### Commands

```bash
conan install . --install-folder cmake-build-release --build=missing
```

```bash
cmake -G "Unix Makefile" .
```

```bash
cmake --build .
```
