#ifndef PETICIONCURL_H
#define PETICIONCURL_H
#include <string>
#include <iostream>
  
class PeticionCurl {
public:
    PeticionCurl();
    std::string Peticion();  // Cambiamos a string para devolver la respuesta
};

#endif // PETICIONCURL_H