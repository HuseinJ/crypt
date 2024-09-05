//
// Created by Husein Jusic on 06.09.24.
//

#ifndef CRYPT_CAESARCIPHER_H
#define CRYPT_CAESARCIPHER_H

#include "libs/common/Cipher.h"

class CaesarCipher : public Cipher {
public:
    explicit CaesarCipher(int shift) : shift_(shift) {}
    std::string encrypt(std::string text) override;
    std::string decrypt(std::string text) override;
private:
    int shift_;
};

#endif //CRYPT_CAESARCIPHER_H
