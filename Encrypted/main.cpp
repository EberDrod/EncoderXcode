//
//  main.cpp
//  Encrypted
//
//  Created by Eb on 11/07/25.
//

#include <iostream>
#include "StringEncryptor.h"

int main() {
    StringEncryptor encryptor;
    encryptor.SetKey("miClaveSecreta");

    std::string original = "Hola, Dude";
    std::string encrypted = encryptor.Encrypt(original);
    std::string decrypted = encryptor.Decrypt(encrypted);

    std::cout << "Original:  " << original << std::endl;
    std::cout << "Encrypted: ";
    for (unsigned char c : encrypted) {
        std::cout << std::hex << static_cast<int>(c) << " ";
    }
    std::cout << std::endl;

    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
