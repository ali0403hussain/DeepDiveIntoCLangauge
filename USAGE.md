# 📦 How to Use This Repository

This guide walks you through setting up and running the **Deep Dive into C** project on **Windows**, using **MSYS2**, **CMake**, **GCC**, and **Visual Studio Code**.

---

## 🛠 MSYS2 Setup for CMake Build on Windows

MSYS2 is a software distribution and environment for building native Windows applications. It comes with:
- MinGW-w64 toolchain (GCC)
- Package manager (`pacman`)
- Tools like Bash, Git, CMake, Make, etc.

> 🔗 [More info on MSYS2](https://www.msys2.org/)  
> 💡 Reference: [Stack Overflow – MSYS2 & MinGW setup](https://stackoverflow.com/questions/30069830/how-can-i-install-mingw-w64-and-msys2/30071634)

---

## ✅ Installation Steps

### 1. Download and Install MSYS2

- Visit: https://www.msys2.org/
- Download the installer
- Install it (default path is `C:\msys64`)

---

### 2. Start MSYS2 Terminal

- Open `mingw32.exe` from the MSYS2 start menu (for 32-bit development)

---

### 3. Update the System

You must run updates twice:

```bash
pacman -Syuu
```
If prompted to close the terminal during the process, do so and then re-open it and run pacman -Syuu again.

### 4. Install Toolchain and Tools
Install the GCC compiler, Make, CMake, and Doxygen
```bash
pacman -S mingw-w64-i686-toolchain mingw-w64-i686-gcc mingw-w64-i686-make mingw-w64-i686-cmake mingw-w64-i686-doxygen
```
✅ Choose "Yes" to all prompts when installing packages.

### 5. Add MSYS2 to Windows PATH
To make MSYS2 tools accessible globally:
- Open System Properties
- Right-click Start → System
- Click Advanced system settings
- Go to Environment Variables
- Under System Variables, select Path → click Edit
- Add the following:
    C:\msys64\mingw32\bin

### 6. Rename mingw32-make to make
Some build tools expect make.exe. In your MSYS2 terminal:
```bash
cd /mingw32/bin
cp mingw32-make.exe make.exe
```

💻 Setting Up the Project in VSCode
### 1. Clone the Repository
```bash
git clone https://github.com/your-username/deep-dive-into-c.git
cd deep-dive-into-c
code .
```
Make sure you open the folder, not just individual files.

### 2. Install Required VSCode Extensions
Install these extensions:
✅ C/C++ (Microsoft)
✅ CMake Tools
✅ CMake
✅ MemoryView

### 3. Select CMake Kit and Build
- Open Command Palette: Ctrl + Shift + P
- Run CMake: Select a Kit
- Choose: GCC for MSYS2 (32-bit) or similar
- Open Command Palette: Ctrl + Shift + P
- Cmake:Build

🐞 Debugging in VSCode (Optional)
### 1. Create launch.json
Go to Run & Debug panel → Click "create a launch.json file"

Choose C++ (GDB/LLDB)

### 2. Example Configuration
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug C Program",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/your_program_name.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "gdb",
      "miDebuggerPath": "gdb"
    }
  ]
}
```
