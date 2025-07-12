#include "StringEncryptor.h"

void StringEncryptor::SetKey(const std::string& key) {
    mKey = key.empty() ? "default" : key;
}

std::string StringEncryptor::Encrypt(const std::string &str) const {
    std::string result = str;
    size_t keyLen = mKey.size();

    for (size_t i = 0; i < str.size(); ++i) {
        // XOR con la clave
        char xorChar = str[i] ^ mKey[i % keyLen];

        // Desplazamiento: suma el valor ASCII de la clave modulo 256
        char shiftedChar = static_cast<char>((static_cast<unsigned char>(xorChar) + static_cast<unsigned char>(mKey[i % keyLen])) % 256);

        result[i] = shiftedChar;
    }
    return result;
}

std::string StringEncryptor::Decrypt(const std::string &str) const {
    std::string result = str;
    size_t keyLen = mKey.size();

    for (size_t i = 0; i < str.size(); ++i) {
        // Desplazamiento inverso
        char shiftedBack = static_cast<char>((256 + static_cast<unsigned char>(str[i]) - static_cast<unsigned char>(mKey[i % keyLen])) % 256);

        // XOR inverso
        char originalChar = shiftedBack ^ mKey[i % keyLen];

        result[i] = originalChar;
    }
    return result;
}
