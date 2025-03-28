#ifndef DONOR_H
#define DONOR_H

#include <string>
#include <stdexcept>  
#include <algorithm>  

//Esta clase representa a un donante de sangre con atributos como ID, nombre, dirección, distrito, tipo de sangre y número de contacto
class Donor {
private:
    // Atributos privados para garantizar encapsulamiento
    int donorId, district;
    std::string name, address, bloodType, number;

public:
    // Getters: Métodos para obtener los valores de los atributos privados
    int getDonorId() const { return donorId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getBloodType() const { return bloodType; } 
    std::string getNumber() const { return number; }       
    int getDistrict() const { return district; }

    // Setters: Métodos para modificar los valores de los atributos privados
    void setDonorId(int id) { donorId = id; }
    void setName(const std::string& n) { name = n; }
    void setAddress(const std::string& addr) { address = addr; }
    void setBloodType(const std::string& blood, bool validate = true); // Asigna tipo de sangre (opcionalmente valida)
    void setNumber(const std::string& num, bool validate = true); // Asigna número de contacto (validate no implementado)
    void setDistrict(int dist) { district = dist; }

    // Muestra los detalles del donante (nombre, distrito y tipo de sangre)
    void donorDetails() const; 

    // Convierte una línea de texto en un objeto Donor
    static Donor parseLine(const std::string& line);  
};

#endif