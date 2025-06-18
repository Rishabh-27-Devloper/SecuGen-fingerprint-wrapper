# SecuGenWrapper

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![CMake](https://img.shields.io/badge/CMake-Build%20System-orange)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![License: Custom](https://img.shields.io/badge/License-Custom-red)

A minimal C++ wrapper around the SecuGen fingerprint SDK, built for Windows using CMake. This project provides functions to initialize, capture, evaluate, and clean up the fingerprint device via a simplified C-style API.

---

## 📁 Project Structure

```
/your-project/
│
├── CMakeLists.txt          # CMake build configuration
├── src/
│   ├── SecuGenWrapper.cpp  # Core implementation
│   └── SecuGenWrapper.h    # Public API header
```

---

## 🔧 Build Instructions

### Requirements

* Windows OS
* CMake ≥ 3.15
* Visual Studio or any CMake-compatible compiler on Windows
* SecuGen SDK (make sure `sgfplib.h` and linked libraries are correctly set up)

### Steps

```bash
git clone https://github.com/Rishabh-27-Devloper/SecuGen-fingerprint-wrapper.git
cd SecuGenWrapper
mkdir build
cd build
cmake ..
cmake --build .
```

This will generate a DLL or executable depending on how you configure your CMake project.

---

## 🔍 Features

* 🔌 Device Initialization (`InitializeDevice`)
* 📀 Fetch Image Dimensions (`GetDeviceInfo`)
* 🕐️ Capture Fingerprint Image (`CaptureFingerprint`)
* 🎯 Evaluate Fingerprint Quality (`GetImageQuality`)
* 🧹 Cleanup Device Resources (`CleanupDevice`)

All methods are exposed via `extern "C"` for compatibility with C and other languages through FFI (e.g., Python ctypes, C#, etc.).

---

## 🧠 Usage Example (C/C++)

```cpp
#include "SecuGenWrapper.h"

int main() {
    InitializeDevice();

    int width, height;
    GetDeviceInfo(&width, &height);

    int bufferSize = width * height;
    unsigned char* buffer = new unsigned char[bufferSize];

    CaptureFingerprint(buffer, bufferSize);

    DWORD quality;
    GetImageQuality(buffer, width, height, &quality);

    CleanupDevice();
    delete[] buffer;
    return 0;
}
```

---

## 📝 Notes

* Ensure the SecuGen driver and SDK are properly installed.
* This wrapper is Windows-only due to use of `windows.h` and `__declspec`.

---

## 📜 License

Custom license (or specify GPL/MIT/BSD/etc. here if applicable).

---

## 🤝 Contributing

Feel free to fork and submit pull requests. Open issues for feature requests or bugs.

---

## 🧷 Acknowledgements

* [SecuGen Corporation](https://secugen.com/) — for the fingerprint SDK.
