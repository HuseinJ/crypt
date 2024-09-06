#ifndef CRYPT_CRYPT_H
#define CRYPT_CRYPT_H

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "libs/common/Cipher.h"
#include "libs/caesar/CaesarCipher.h"
#include "libs/xor/XORCipher.h"

// Function to display usage
void printUsage() {
    std::cout << "Usage: \n";
    std::cout << "  crypt -c <cipher> -s <params> <text>\n\n";
    std::cout << "Ciphers available:\n";
    std::cout << "  caesar          Use Caesar cipher with specified shift (e.g., 1, 2, 3, etc.)\n";
    std::cout << "  xor             Use XOR cipher with a specified key (e.g., 'mykey')\n";
}

// Function to create the cipher based on user input
std::unique_ptr<Cipher> createCipher(const std::string& cipherName, const std::string& param) {
    if (cipherName == "caesar") {
        // Convert the parameter to an integer for Caesar cipher
        int shift = std::stoi(param);
        return std::make_unique<CaesarCipher>(shift);
    } else if (cipherName == "xor")  {
        // Use the string as the key for XOR cipher
        return std::make_unique<XORCipher>(param);
    } else {
        throw std::invalid_argument("Unknown cipher type: " + cipherName);
    }
}

// Function to parse command-line arguments
void parseArguments(int argc, char** argv, std::string& cipherName, std::string& param, std::string& text) {
    if (argc < 6) {
        printUsage();
        exit(1);
    }

    // Parse flags and arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-c") {
            if (i + 1 < argc) {
                cipherName = argv[++i];
            } else {
                std::cerr << "Error: -c option requires a cipher type.\n";
                exit(1);
            }
        } else if (arg == "-s") {
            if (i + 1 < argc) {
                param = argv[++i];
            } else {
                std::cerr << "Error: -s option requires a parameter value.\n";
                exit(1);
            }
        } else {
            text = arg;
        }
    }

    // Validate input
    if (cipherName.empty()) {
        std::cerr << "Error: No cipher specified with -c option.\n";
        printUsage();
        exit(1);
    }

    if (param.empty()) {
        std::cerr << "Error: No parameter provided with -s option.\n";
        printUsage();
        exit(1);
    }

    if (text.empty()) {
        std::cerr << "Error: No text provided for encryption/decryption.\n";
        printUsage();
        exit(1);
    }
}

int main(int argc, char** argv) {
    std::string cipherName;
    std::string param;  // Can be an integer (for Caesar) or a string (for XOR)
    std::string text;

    // Parse the command-line arguments
    parseArguments(argc, argv, cipherName, param, text);

    try {
        // Create the cipher dynamically based on the user's input
        std::unique_ptr<Cipher> cipher = createCipher(cipherName, param);

        // Encrypt and decrypt the text
        std::string encryptedText = cipher->encrypt(text);
        std::string decryptedText = cipher->decrypt(encryptedText);

        // Display results
        std::cout << "Original:   " << text << std::endl;
        std::cout << "Encrypted:  " << encryptedText << std::endl;
        std::cout << "Decrypted:  " << decryptedText << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#endif //CRYPT_CRYPT_H
