// SecuGenWrapper.cpp
#include "SecuGenWrapper.h"
#include "sgfplib.h"
#include <memory>
#define AUTO_DETECT 0xFFFFFFFF
#include <iostream>
using namespace std;

// Global variables
HSGFPM device = NULL;
int g_width = 0;
int g_height = 0;

SECUGENWRAPPER_API int InitializeDevice() {
    DWORD err;

    // Create the device handle
    err = SGFPM_Create(&device);
    if (err != SGFDX_ERROR_NONE)
        return err;
    
    cout << "Device Handle Created\n";
    // Initialize the device
    err = SGFPM_Init(device, SG_DEV_FDU05); // Automatically detect the device
    if (err != SGFDX_ERROR_NONE)
        return err;
    
    cout << "Device Initialize\n";
    // Open the device
    err = SGFPM_OpenDevice(device, AUTO_DETECT);
    if (err != SGFDX_ERROR_NONE)
        return err;

    cout << "Device Open\n";
    // Retrieve device information
    SGDeviceInfoParam deviceInfo;
    err = SGFPM_GetDeviceInfo(device, &deviceInfo);
    if (err != SGFDX_ERROR_NONE)
        return err;

    // Store width and height globally
    g_width = deviceInfo.ImageWidth;
    g_height = deviceInfo.ImageHeight;

    cout << "Device Info Retrived\n";

    return SGFDX_ERROR_NONE;
}

SECUGENWRAPPER_API int GetDeviceInfo(int* width, int* height) {
    if (device == NULL)
        return SGFDX_ERROR_FUNCTION_FAILED;
    
    *width = g_width;
    *height = g_height;
    return SGFDX_ERROR_NONE;
}

SECUGENWRAPPER_API int CaptureFingerprint(unsigned char* buffer, int buffer_size) {
    if (device == NULL || buffer == NULL)
        return SGFDX_ERROR_INVALID_PARAM;
    
    if (buffer_size < (g_width * g_height))
        return SGFDX_ERROR_INVALID_PARAM;
    return SGFPM_GetImage(device, buffer);
}

SECUGENWRAPPER_API int GetImageQuality(unsigned char* buffer, int width, int height, DWORD* quality) {
    if (device == NULL || buffer == NULL || quality == NULL)
        return SGFDX_ERROR_INVALID_PARAM;

    return SGFPM_GetImageQuality(device, width, height, buffer, quality);
}

SECUGENWRAPPER_API void CleanupDevice() {
    if (device != NULL) {
        SGFPM_CloseDevice(device);
        SGFPM_DestroyFunc(device);
        device = NULL;
    }
}