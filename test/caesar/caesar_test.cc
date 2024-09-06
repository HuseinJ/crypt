#include <gtest/gtest.h>
#include "libs/caesar/CaesarCipher.h"

/*
 * basic encription and decription tests
 */
TEST(CaesarCipherTest, EncryptBasicTest) {
CaesarCipher cipher(3);  // Shift by 3

EXPECT_EQ(cipher.encrypt("HELLO"), "KHOOR");
EXPECT_EQ(cipher.encrypt("hello"), "khoor");
EXPECT_EQ(cipher.encrypt("World"), "Zruog");
}

TEST(CaesarCipherTest, DecryptBasicTest) {
CaesarCipher cipher(3);  // Shift by 3

EXPECT_EQ(cipher.decrypt("KHOOR"), "HELLO");
EXPECT_EQ(cipher.decrypt("khoor"), "hello");
EXPECT_EQ(cipher.decrypt("Zruog"), "World");
}

/*
 * edge case tests
 */

TEST(CaesarCipherTest, EncryptWrapAroundTest) {
CaesarCipher cipher(3);  // Shift by 3

EXPECT_EQ(cipher.encrypt("XYZ"), "ABC");
EXPECT_EQ(cipher.encrypt("xyz"), "abc");
}

TEST(CaesarCipherTest, DecryptWrapAroundTest) {
CaesarCipher cipher(3);  // Shift by 3

EXPECT_EQ(cipher.decrypt("ABC"), "XYZ");
EXPECT_EQ(cipher.decrypt("abc"), "xyz");
}

TEST(CaesarCipherTest, EncryptDecryptNonAlphaTest) {
CaesarCipher cipher(5);  // Shift by 5

EXPECT_EQ(cipher.encrypt("Hello, World! 123"), "Mjqqt, Btwqi! 123");
EXPECT_EQ(cipher.decrypt("Mjqqt, Btwqi! 123"), "Hello, World! 123");
}

TEST(CaesarCipherTest, NoShiftTest) {
CaesarCipher cipher(0);  // No shift

EXPECT_EQ(cipher.encrypt("HELLO"), "HELLO");
EXPECT_EQ(cipher.decrypt("HELLO"), "HELLO");
}

TEST(CaesarCipherTest, NegativeShiftTest) {
CaesarCipher cipher(-3);

EXPECT_EQ(cipher.encrypt("HELLO"), "EBIIL");
EXPECT_EQ(cipher.decrypt("EBIIL"), "HELLO");
}