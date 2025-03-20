//Clase nueva ya que trim no era necesario poner en Donor pues se necesita en otras clases asi que le hice una
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>

class Utils {
public:
    //No hay datos privados debido que la asbtraccion de la funcion no lo requiere y aun asi cumple el encapsulamiento, no hay datos delicados

    static std::string trim(const std::string& str); //Metodo anteriormente de la clase DOnor
    static int getValidatedInput(const std::string& prompt); //Metodo anteriormente de BloodDatabase
    static std::string getValidatedBloodType(const std::string& prompt); //Metodo nuevo de validacion de tipo de ssangre
    static std::string getValidatedPhoneNumber(const std::string& prompt); //Metodo nuevo de validacion de telefono[A cambiar por API]
};

#endif