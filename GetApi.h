

#ifndef GETAPI_H
#define GETAPI_H
#include <string>
#include <iostream>
  
class GetApi(){
    private:
        std::string telefono;
    public:
        std::string verificarNumero(std::string telefono)const;//se encargara de hacer la peticion a la api de validar numero telefonico
        

}

#endif // GETAPI_H
