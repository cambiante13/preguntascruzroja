#include "Utils.h"
#include <iostream>
#include <cctype>

/*
Esta es la clase nueva anadida al codigo, donde se movio el metodo Trim anteriormente en la clase donor, para poder usarse de manera mas general.
De igual manera se movio getValidatedInput para usarse en mas partes del programa y a su vez se reutilizo parte de su estructura para crear el 
getValidatedBloodTypes y el getValidatedPhoneNumber.
*/


//Metodo anteriormente perteneciente a donor que permite eliminar vacios tanto al inicio como al final de una cadena
std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

//Metodo anteriormente perteneciente a Bloodatabase 
int Utils::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break; // si la conversión es exitosa, salir del bucle
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}


//Nuevo metodo anadido que permite validar el tipo de sangre
std::string Utils::getValidatedBloodType(const std::string& prompt) {
    const std::vector<std::string> validBloodTypes = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"
    };
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::find(validBloodTypes.begin(), validBloodTypes.end(), input) != validBloodTypes.end()) {
            return input; // Si el tipo de sangre es válido, retornarlo
        } else {
            std::cout << "Tipo de sangre no válido. Los tipos válidos son: A+, A-, B+, B-, AB+, AB-, O+, O-." << std::endl;
        }
    }
}


//Nuevo metodo anadido que permite validar el tipo de telefono [Cambiarlo por la API]
std::string Utils::getValidatedPhoneNumber(const std::string& number) {
    if (number.length() == 10 && std::all_of(number.begin(), number.end(), ::isdigit)) {
        return number; // Si el número de teléfono es válido, retornarlo
    } else {
        throw std::invalid_argument("Número de teléfono no válido. Debe tener exactamente 10 dígitos.");
    }
}
