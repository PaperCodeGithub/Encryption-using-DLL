#include "Cipher.h"
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE; 
}

void Encrypt(char* message, int shiftKey) {
    for (int i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] + shiftKey;
    }
}

void Decrypt(char* message, int shiftKey) {
    for (int i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] - shiftKey;
    }
}