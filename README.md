# StringEncryptor

Este proyecto contiene una clase simple `StringEncryptor` que implementa un algoritmo básico de cifrado simétrico para cadenas de texto.

---

## Descripción del algoritmo

El cifrado se realiza en dos pasos:

1. **XOR** entre cada carácter del texto original y un carácter correspondiente de la clave, repitiendo la clave si el texto es más largo.
2. **Desplazamiento**: al resultado del XOR se le suma el valor ASCII del mismo carácter de la clave, módulo 256, para rotar el byte resultante.

Para desencriptar, se aplica el proceso inverso:

1. Se resta el valor ASCII de la clave (módulo 256).
2. Se aplica XOR nuevamente con el mismo carácter de la clave.

Este esquema garantiza que:

- El texto original puede recuperarse correctamente.
- El texto cifrado no es legible directamente y no es simplemente una inversión o desplazamiento.

---

## Archivos

- `StringEncryptor.h`: Declaración de la clase.
- `StringEncryptor.cpp`: Implementación del cifrado y descifrado.
- `main.cpp`: Ejemplo de uso con impresión del texto cifrado en hexadecimal.

---

## Uso

```cpp
#include <iostream>
#include "StringEncryptor.h"

int main() {
    StringEncryptor encryptor;
    encryptor.SetKey("miClaveSecreta");

    std::string original = "Hola, Baby";
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


Original:  Hola, Baby
Encrypted: <bytes en hexadecimal>
Decrypted: Hola, Baby
