//
// Created by Husein Jusic on 05.09.24.
//
#ifndef CRYPT_CRYPT_H
#define CRYPT_CRYPT_H

#include <iostream>
#include "libs/common/Cipher.h"
#include "libs/caesar/CaesarCipher.h"


int main(int argc, char** argv) {
    std::string toEncrypt = "test";
    Cipher* cipher = new CaesarCipher(1);

    auto encryptedText = cipher->encrypt(toEncrypt);

    std::cout << "encrypted: " << encryptedText << std::endl;
    std::cout << "decrypted: " << cipher->decrypt(encryptedText) << std::endl;
}

#endif //CRYPT_CRYPT_H