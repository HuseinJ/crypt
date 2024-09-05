//
// Created by Husein Jusic on 05.09.24.
//

#include "libs/common/Cipher.h"

class CaesarCipher : public Cipher {
public:
    CaesarCipher(int shift) : shift_(shift) {}

    std::string encrypt(std::string text) override {
        std::string result = text;
        for (char& c : result) {
            if (isalpha(c)) {
                char offset = islower(c) ? 'a' : 'A';  // Handle both lowercase and uppercase letters
                c = (c - offset + shift_) % 26 + offset;
            }
        }
        return result;
    }

    // Implement the decrypt method
    std::string decrypt(std::string text) override {
        std::string result = text;
        for (char& c : result) {
            if (isalpha(c)) {
                char offset = islower(c) ? 'a' : 'A';  // Handle both lowercase and uppercase letters
                c = (c - offset - shift_ + 26) % 26 + offset;  // Add 26 to avoid negative modulo
            }
        }
        return result;
    }

private:
    int shift_;
};