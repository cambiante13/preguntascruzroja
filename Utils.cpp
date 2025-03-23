#include "Utils.h"
#include <iostream>
#include <cctype>

// Elimina espacios en blanco al inicio y final de una cadena
std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Valida si una cadena es un número válido
bool Utils::isValidNumber(const std::string& input) {
    return std::all_of(input.begin(), input.end(), ::isdigit);
}

// Convierte una cadena en un número entero, si se cumple que es un numero valido
int Utils::convertToInt(const std::string& input) {
    try {
        return std::stoi(input);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("La entrada contiene caracteres no numéricos");
    } catch (const std::out_of_range&) {
        throw std::out_of_range("Entrada fuera de rango");
    }
}

// Solicita y valida un tipo de sangre válido
std::string Utils::getValidatedBloodType(const std::string& prompt) {
    const std::vector<std::string> validBloodTypes = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-", "a+", "a-", "b+", "b-", "ab+", "ab-", "o+", "o-" 
    };
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::find(validBloodTypes.begin(), validBloodTypes.end(), input) != validBloodTypes.end()) {
            return input; 
        } else {
            std::cout << "Tipo de sangre no válido. Los tipos válidos son: A+, A-, B+, B-, AB+, AB-, O+, O-." << std::endl;
        }
    }
}