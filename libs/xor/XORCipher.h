//
// Created by Husein Jusic on 06.09.24.
//

#ifndef CRYPT_XORCIPHER_H
#define CRYPT_XORCIPHER_H

#include "libs/common/Cipher.h"

class XORCipher : public Cipher {
public:
    explicit XORCipher(std::string key) : key(key) {}
    std::string encrypt(std::string text) override;
    std::string decrypt(std::string text) override;
private:
    std::string key;
};

#endif //CRYPT_XORCIPHER_H
