// SecuGenWrapper.h
#pragma once

#ifdef SECUGENWRAPPER_EXPORTS
#define SECUGENWRAPPER_API __declspec(dllexport)
#else
#define SECUGENWRAPPER_API __declspec(dllimport)
#endif

#include <windows.h>

extern "C" {
    // Initialize the device
    SECUGENWRAPPER_API int InitializeDevice();
    
    // Get device information
    SECUGENWRAPPER_API int GetDeviceInfo(int* width, int* height);
    
    // Capture fingerprint
    SECUGENWRAPPER_API int CaptureFingerprint(unsigned char* buffer, int buffer_size);
    
    // Get image quality
    SECUGENWRAPPER_API int GetImageQuality(unsigned char* buffer, int width, int height, DWORD* quality);
    
    // Cleanup resources
    SECUGENWRAPPER_API void CleanupDevice();
}