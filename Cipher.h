#pragma once

#ifdef CIPHER_EXPORTS
#define CIPHER_API __declspec(dllexport)
#else
#define CIPHER_API __declspec(dllimport)
#endif

// Exporting our two core functions
extern "C" CIPHER_API void Encrypt(char* message, int shiftKey);
extern "C" CIPHER_API void Decrypt(char* message, int shiftKey);