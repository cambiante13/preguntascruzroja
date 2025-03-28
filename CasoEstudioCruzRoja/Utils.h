#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>

// Clase de utiles, hace validaciones y manipula cadenas

class Utils {
public:
    // Elimina espacios en blanco al inicio y final de una cadena
    static std::string trim(const std::string& str);

    // Valida si una cadena es un número válido
    static bool isValidNumber(const std::string& input);

    // Convierte una cadena en un número entero
    static int convertToInt(const std::string& input);

    // Solicita y valida un tipo de sangre válido
    static std::string getValidatedBloodType(const std::string& prompt);
};

#endif