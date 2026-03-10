# Nmap++

![Build](https://github.com/Laurent-Mercier/NmapPlusPlus/actions/workflows/build.yml/badge.svg)

A lightweight port scanner written in C++, inspired by Nmap.  

---

## Features

- TCP Connect Scan
- Configurable port ranges (e.g. `-p 1-1024`, `-p 80,443`)
- Multi-threaded scanning
- DNS resolution
- Banner grabbing *(coming soon)*
- SYN Scan *(coming soon)*

---

## Requirements

- C++17 or later
- CMake 3.15+
- Linux

---

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

---

## Usage

```bash
./build/nmappp <target> [options]

Options:
  -p <ports>       Port range or list (e.g. 1-1024 or 80,443)
  -sT              TCP Connect scan (default)
  -sS              SYN scan (requires root)
  --timeout <ms>   Timeout in milliseconds (default: 500)
  -v               Verbose output
```

---

## Example

```bash
./build/nmappp 192.168.1.1 -p 1-1024
```

---

## Disclaimer

This tool is intended for educational purposes only.  
Only use it on systems you own or have explicit permission to scan.

---

## License

[AGPL-3.0](LICENSE)
