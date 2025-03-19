#ifndef DONOR_H
#define DONOR_H

#include <string>
#include <stdexcept>  // Para std::invalid_argument
#include <algorithm>  // Para std::all_of
//Cambie la linea 10 y 11 a privado pq estaba en publico, puse getters y setters para acceder a lo que esta en priv y puse verificaciones para el tipo de sangre y telefono.
class Donor {
private:
    int donorId, district;
    std::string name, address, bloodType, number;

public:
    // Estos son Getters
    int getDonorId() const { return donorId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getBloodType() const { return bloodType; }
    std::string getNumber() const { return number; }
    int getDistrict() const { return district; }

    // Estos son Setters
    void setDonorId(int id) { donorId = id; }
    void setName(const std::string& n) { name = n; }
    void setAddress(const std::string& addr) { address = addr; }
    void setBloodType(const std::string& blood);
    void setNumber(const std::string& num);
    void setDistrict(int dist) { district = dist; }

    void donorDetails() const; 
    static Donor parseLine(const std::string& line);  
};

#endif // DONOR_H
