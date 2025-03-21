#ifndef DONOR_H
#define DONOR_H

#include <string>
#include <stdexcept>  
#include <algorithm>  

class Donor {
private:
    //Estos son los atributos que estaban publicos y se movieron a privados, pues no habia un correcto encapsulamiento
    int donorId, district;
    std::string name, address, bloodType, number;

public:
    //Esta es la interfaz publica que se anadio mediante Setters y Getters de manera que nos permiten interactuar con los atributos privados de donor respetando un correcto encapsulamiento.
    // Estos son los Getters anadidos para tomar los valores de los tributos privados de donor
    int getDonorId() const { return donorId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getBloodType() const { return bloodType; } 
    std::string getNumber() const { return number; }       
    int getDistrict() const { return district; }

    // Estos son Setters anadidos para cambiar los valores de las atributos privadas de donor
    void setDonorId(int id) { donorId = id; }
    void setName(const std::string& n) { name = n; }
    void setAddress(const std::string& addr) { address = addr; }
    void setBloodType(const std::string& blood, bool validate = true); 
    void setNumber(const std::string& num, bool validate = true);       
    void setDistrict(int dist) { district = dist; }

    void donorDetails() const; 
    static Donor parseLine(const std::string& line);  
};

#endif 