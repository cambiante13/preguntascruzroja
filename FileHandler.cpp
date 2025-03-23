#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <limits>

// Constructor que inicializa FileHandler con el nombre del archivo de datos
FileHandler::FileHandler(const std::string& fileName) : fileName(fileName) {}

// Escribe los datos de un donante en el archivo
void FileHandler::writeDataToFile(const Donor& donor) const {
    std::ofstream outfile(fileName, std::ios::app);
    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }
    outfile << donor.getDonorId() << ",    " << donor.getName() << ",    "
            << donor.getAddress() << ",    " << donor.getDistrict() << ",    "
            << donor.getBloodType() << ",    " << donor.getNumber() << std::endl;
    outfile.close();
}

// Busca donantes según los criterios departamento, dirección y tipo de sangre
std::vector<Donor> FileHandler::searchAndDisplay(int provinceName, const std::string& addressFilter, const std::string& bloodTypeFilter) const {
    std::ifstream inFile(fileName);
    std::vector<Donor> donors;
    std::string line;

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return donors;
    }

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match =
            d.getDistrict() == provinceName &&
            (addressFilter.empty() ||
             d.getAddress().find(addressFilter) != std::string::npos) &&
            (bloodTypeFilter.empty() || d.getBloodType() == bloodTypeFilter);

        if (match) {
            donors.push_back(d);
        }
    }

    inFile.close();
    return donors;
}

// Elimina un donante por nombre y pide confirmación antes de eliminarlo
void FileHandler::deleteDonor(const std::string& donorName) const {
    std::ifstream inFile(fileName);
    std::ofstream tempFile("temp.txt");

    if (!inFile) {
        std::cerr << "Error al abrir el archivo " << fileName << std::endl;
        return;
    }

    if (!tempFile) {
        std::cerr << "Error al crear el archivo temporal" << std::endl;
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.getName() == donorName) {
            found = true;
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Dirección: " << d.getAddress() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Número de móvil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
            std::cout << "¿Está seguro de que desea eliminar al donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (sureChoice == 's' || sureChoice == 'S') {
                continue;
            }
        }

        tempFile << d.getDonorId() << ",    " << d.getName() << ",    "
                 << d.getAddress() << ",    " << d.getDistrict() << ",    "
                 << d.getBloodType() << ",    " << d.getNumber() << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    if (std::rename("temp.txt", fileName.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    if (!found) {
        std::cout << "No se encontró ningún donante con el nombre " << donorName << std::endl;
    }
}

// Muestra todos los donantes registrados en el archivo
void FileHandler::displayAllDonors() const {
    std::ifstream inFile(fileName);
    std::vector<Donor> donors;
    std::string line;

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        donors.push_back(d);
    }

    for (const auto& d : donors) {
        std::cout << "Nombre: " << d.getName() << std::endl;
        std::cout << "Dirección: " << d.getAddress() << std::endl;
        std::cout << "Departamento: " << d.getDistrict() << std::endl;
        std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
        std::cout << "Número de móvil: " << d.getNumber() << std::endl;
        std::cout << std::endl;
    }

    inFile.close();
}