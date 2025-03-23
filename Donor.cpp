#include "Donor.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <vector>

// Muestra los detalles del donante: nombre, distrito y tipo de sangre
void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

// Convierte una línea de texto en un objeto Donor. Usa comas como separadores y asigna los valores a los atributos
Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); d.setDonorId(std::stoi(Utils::trim(token))); // ID
    getline(ss, token, ','); d.setName(Utils::trim(token)); // Nombre
    getline(ss, token, ','); d.setAddress(Utils::trim(token)); // Dirección
    getline(ss, token, ','); d.setDistrict(std::stoi(Utils::trim(token))); // Distrito
    getline(ss, token, ','); d.setBloodType(Utils::trim(token), false); // Tipo de sangre
    getline(ss, token, ','); d.setNumber(Utils::trim(token), false); // Número

    return d;
}

// Asigna el tipo de sangre. Si validate es true, valida el valor
void Donor::setBloodType(const std::string& blood, bool validate) {
    if (validate) {
        bloodType = Utils::getValidatedBloodType("Ingrese el tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-): ");
    } else {
        bloodType = blood; // Asignación directa
    }
}

// Asigna el número de contacto. (validate no está implementado)
void Donor::setNumber(const std::string& num, bool validate) {
    number = num; // Asignación directa
}