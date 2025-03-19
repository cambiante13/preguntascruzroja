#include "Donor.h"
#include "Utils.h"
#include <iostream>
#include <sstream>

void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); d.setDonorId(std::stoi(Utils::trim(token)));  // 
    getline(ss, token, ','); d.setName(Utils::trim(token));  // 
    getline(ss, token, ','); d.setAddress(Utils::trim(token));  // 
    getline(ss, token, ','); d.setDistrict(std::stoi(Utils::trim(token)));  // 
    getline(ss, token, ','); d.setBloodType(Utils::trim(token));  // 
    getline(ss, token, ','); d.setNumber(Utils::trim(token));  // 

    return d;
}