#include "encdec.h"
#include <iostream>
#include <string>

namespace security {
std::string encryptCaesar(std::string text, int x) {
    std::string ciphertext = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + x) % 26 + base;
        }
        ciphertext += c;
    }
    return ciphertext;
}

std::string decryptCaesar(std::string text, int x) {
    return encryptCaesar(text, 26 - x);
    }
}
