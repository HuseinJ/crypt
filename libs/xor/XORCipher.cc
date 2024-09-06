
#include "XORCipher.h"

std::string XORCipher::encrypt(std::string text) {
    std::string result = text;

    for (size_t i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % key.size()];
    }

    return result;
}

std::string XORCipher::decrypt(std::string text) {
    return encrypt(text);
}


