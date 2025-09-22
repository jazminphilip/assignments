# Beginner-Friendly Guide: Installing a C++ Compiler

This guide will help you install a C++ compiler on **Windows, macOS, or Linux**.  
Follow the steps for your operating system. At the end, you’ll test your compiler with a simple program.

---

## Windows (MinGW-w64)

1. Go to the MinGW-w64 download page: [https://www.mingw-w64.org/downloads/](https://www.mingw-w64.org/downloads/)  
2. Download the **SourceForge installer**.  
3. During installation, select:  
   - Architecture = `x86_64`  
   - Threads = `posix`  
   - Exception = `seh`  
4. Install to:  C:\mingw64
5. Add `C:\mingw64\bin` to your **PATH** (via Environment Variables).  
6. Open **Command Prompt** and run:  

```bash
g++ --version
```

If you see a version number, you’re done!

## macOS

1. Open **Terminal**.

2. Run:

   ```
   xcode-select --install
   ```

3. Verify installation with:

   ```
   clang++ --version
   ```

You should see Apple Clang listed.

## Linux (Ubuntu/Debian)

1. Update packages:

   ```
   sudo apt update
   ```

2. Install compiler:

   ```
   sudo apt install g++
   ```

3. Verify installation:

   ```
   g++ --version
   ```

You should see GNU C++ version.

------

## Test Your Compiler

1. Create a file named **hello.cpp** with the following code:

   ```
   #include <iostream>
   using namespace std;
   
   int main() {
       cout << "Hello, C++!" << endl;
       return 0;
   }
   ```

2. Compile and run:

   ```
   g++ hello.cpp -o hello
   ./hello     # On Windows use: hello.exe
   ```

 Expected output:

```
Hello, C++!
```
