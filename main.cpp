#include <iostream>
#include <string>
#include <windows.h>

typedef void (*CipherFunction)(char*, int);

int main() {
    std::cout << "--- Secret Message Terminal ---" << std::endl;

    HMODULE hCipherDLL = LoadLibraryA("Cipher.dll");

    if (hCipherDLL == NULL) {
        std::cerr << "[ERROR] Could not locate Cipher.dll. Make sure it is in the same folder!" << std::endl;
        return 1;
    }

    CipherFunction encryptText = (CipherFunction) GetProcAddress(hCipherDLL, "Encrypt");
    CipherFunction decryptText = (CipherFunction) GetProcAddress(hCipherDLL, "Decrypt");

    if (!encryptText || !decryptText) {
        std::cerr << "[ERROR] Could not find the required functions inside the DLL." << std::endl;
        FreeLibrary(hCipherDLL);
        return 1;
    }

    std::string userInput;
    int secretKey = 5;

    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, userInput);
    
    encryptText(&userInput[0], secretKey);
    std::cout << std::endl << "Encrypted Message: " << userInput << std::endl << std::endl;

    decryptText(&userInput[0], secretKey);
    std::cout << "Decrypted Message: " << userInput << std::endl << std::endl;

    FreeLibrary(hCipherDLL);
    std::cout << "-------------------------------" << std::endl << std::endl;

    system("pause");

    return 0;
}