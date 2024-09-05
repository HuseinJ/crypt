//
// Created by Husein Jusic on 05.09.24.
//
#ifndef CRYPT_CRYPT_H
#define CRYPT_CRYPT_H

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "libs/common/Cipher.h"
#include "libs/caesar/CaesarCipher.h"

// Function to display usage
void printUsage() {
    std::cout << "Usage: \n";
    std::cout << "  crypt -c <cipher> -s <params> <text>\n\n";
    std::cout << "Ciphers available:\n";
    std::cout << "  caesar          Use Caesar cipher with specified shift (e.g., 1, 2, 3, etc.)\n";
}

// Function to create the cipher based on user input
std::unique_ptr<Cipher> createCipher(const std::string& cipherName, int shift) {
    if (cipherName == "caesar") {
        return std::make_unique<CaesarCipher>(shift);
    } else {
        throw std::invalid_argument("Unknown cipher type: " + cipherName);
    }
}

// Function to parse command-line arguments
void parseArguments(int argc, char** argv, std::string& cipherName, int& shift, std::string& text) {
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
        } else if (arg == "-p") {
            if (i + 1 < argc) {
                shift = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: -p option requires param value.\n";
                exit(1);
            }
        } else {
            text = arg;  // Assume the remaining argument is the text to encrypt/decrypt
        }
    }

    // Validate input
    if (cipherName.empty()) {
        std::cerr << "Error: No cipher specified with -c option.\n";
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
    int shift = 0;
    std::string text;

    // Parse the command-line arguments
    parseArguments(argc, argv, cipherName, shift, text);

    try {
        // Create the cipher dynamically based on the user's input
        std::unique_ptr<Cipher> cipher = createCipher(cipherName, shift);

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