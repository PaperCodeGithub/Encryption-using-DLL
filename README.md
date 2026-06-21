# C++ Dynamic Run-time DLL Linking
This project demonstrates how to use **Explicit (Run-time) Linking** in C++ to load a Dynamic-Link Library (DLL) directly into memory, locate specific functions, use them, and safely unload them without relying on implicit compile-time linking.

## Features
* **Explicit Memory Management:** Uses the Windows API (`LoadLibraryA`, `GetProcAddress`, `FreeLibrary`) to manually control the DLL lifecycle.
* **In-Place Modification:** The DLL modifies the host program's memory directly via pointers, requiring zero data duplication.
* **Graceful Fallbacks:** The host executable handles missing DLLs safely without crashing on startup.

## File Structure
```text

├── main.cpp       # The Host Application that loads the DLL
├── cipher.cpp     # The DLL source code containing the logic
├── cipher.h       # The header file defining the exported functions
└── README.md      # This file
```

## Prerequisites
- A Windows environment.
- A C++ compiler (either MinGW/GCC or Microsoft Visual C++).

## Compilation & Build Instructions
1. Open your terminal in the project directory.
2. Compile the DLL:
```
g++ -shared -o Cipher.dll cipher.cpp -D CIPHER_EXPORTS
```
3. Compile the Host Application:
```
g++ -o main.exe main.cpp
```
Ensure that `Cipher.dll` and `main.exe` are in the same folder
