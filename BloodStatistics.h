#ifndef BLOODSTATISTICS_H
#define BLOODSTATISTICS_H

#include <iostream>
#include <map>
#include <string>
#include "DonorManager.h"

class BloodStatistics {
private:
    DonorManager& donorManager;  // Referencia a DonorManager para acceder a los datos

public:
    BloodStatistics(DonorManager& manager); // Constructor

    void statisticsPopulation() const;  // Datos fijos de Colombia
    void statisticsBloodtype() const;   // Tipo de sangre más común en Colombia
    std::string databasePopulation() const; // Tipo de sangre más común en la base de datos (dinámico)
    void databaseBloodtype() const; // Distribución de tipos de sangre en la base de datos (dinámico)
};

#endif // BLOODSTATISTICS_H
