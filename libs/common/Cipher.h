//
// Created by Husein Jusic on 05.09.24.
//

#ifndef CRYPT_CIPHER_H
#define CRYPT_CIPHER_H

#include <string>

class Cipher {
public:
    virtual std::string encrypt(std::string text) = 0;
    virtual std::string decrypt(std::string text) = 0;
};

#endif //CRYPT_CIPHER_H
