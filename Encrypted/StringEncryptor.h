//
//  StringEncryptor.h
//  Encrypted
//
//  Created by Eb on 11/07/25.
//

#ifndef STRINGENCRYPTOR_H
#define STRINGENCRYPTOR_H

#include <string>

class StringEncryptor {
public:
    void SetKey(const std::string &key);
    std::string Encrypt(const std::string &str) const;
    std::string Decrypt(const std::string &str) const;

private:
    std::string mKey = "default";
};

#endif // STRINGENCRYPTOR_H
