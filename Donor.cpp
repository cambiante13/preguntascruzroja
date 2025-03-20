#include "Donor.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <vector>

void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); d.setDonorId(std::stoi(Utils::trim(token)));
    getline(ss, token, ','); d.setName(Utils::trim(token));
    getline(ss, token, ','); d.setAddress(Utils::trim(token));
    getline(ss, token, ','); d.setDistrict(std::stoi(Utils::trim(token)));
    getline(ss, token, ','); d.setBloodType(Utils::trim(token), false); 
    getline(ss, token, ','); d.setNumber(Utils::trim(token), false);   

    return d;
}

void Donor::setBloodType(const std::string& blood, bool validate) {
    if (validate) {
        // Usa el método de Utils para validar y obtener un tipo de sangre válido
        bloodType = Utils::getValidatedBloodType("Ingrese el tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-): ");
    } else {
        // Asigna directamente el valor (sin validar)
        bloodType = blood;
    }
}

void Donor::setNumber(const std::string& num, bool validate) {
    if (validate) {
        // Usa el método de Utils para validar y obtener un número de teléfono válido
        number = Utils::getValidatedPhoneNumber("Ingrese el número de teléfono (10 dígitos): ");
    } else {
        // Asigna directamente el valor (sin validarlo)
        number = num;
    }
}
