//
// Created by Husein Jusic on 05.09.24.
//
#include "libs/caesar/CaesarCipher.h"

std::string CaesarCipher::encrypt(std::string text)  {
    std::string result = text;
        for (char& c : result) {
            if (isalpha(c)) {
                char offset = islower(c) ? 'a' : 'A';  // Handle both lowercase and uppercase letters
                c = (c - offset + shift_) % 26 + offset;
            }
        }
        return result;
}

std::string CaesarCipher::decrypt(std::string text)  {
    std::string result = text;
        for (char& c : result) {
            if (isalpha(c)) {
                char offset = islower(c) ? 'a' : 'A';  // Handle both lowercase and uppercase letters
                c = (c - offset - shift_ + 26) % 26 + offset;  // Add 26 to avoid negative modulo
            }
        }
        return result;
}