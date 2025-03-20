
#include "BloodDatabase.h"
#include "Donor.h" //
#include "Utils.h" //
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <map> // Esta es la libreria nueva anadida al trabajo
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

void BloodDatabase::displayBloodTypes() {
  std::cout << "Tipos de sangre:\n";
  std::cout << " A+\n";
  std::cout << " A-\n";
  std::cout << " B+\n";
  std::cout << " B-\n";
  std::cout << " AB+\n";
  std::cout << " AB-\n";
  std::cout << " O+\n";
  std::cout << " O-\n";
}

void BloodDatabase::displayProvinces() {
  std::cout << "Elige el departamento:\n";
  std::cout << "1. Putumayo\n";
  std::cout << "2. Cauca\n";
  std::cout << "3. Valle del Cauca\n";
  std::cout << "4. Amazonas\n";
  std::cout << "5. Risaralda\n";
  std::cout << "6. Antioquia\n";
  std::cout << "7. Norte de Santander\n";
  std::cout << "8. Choco\n";
  std::cout << "9. Arauca\n";
  std::cout << "0. Guainia\n";
}

void BloodDatabase::clearConsole() {
#ifdef _WIN32
  system("cls");
#else
#endif
}

void BloodDatabase::waitForKeyPress() {
  std::cout << "Presiona cualquier tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

int BloodDatabase::getValidatedInput(const std::string &prompt) {
  int value;
  std::string input;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);
    try {
      if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
        throw std::invalid_argument(
            "La entrada contiene caracteres no numéricos");
      }
      value = std::stoi(input);
      break; // si la conversión es exitosa, salir del bucle
    } catch (const std::invalid_argument &e) {
      std::cout << "Entrada no válida: " << e.what()
                << ". Por favor ingrese un número válido." << std::endl;
    } catch (const std::out_of_range &) {
      std::cout << "Entrada fuera de rango. Por favor ingrese un número válido."
                << std::endl;
    }
  }
  return value;
}

void BloodDatabase::getDonorDetails() {
  clearConsole();
  std::cout << "Ingrese los detalles del donante\n";

  Donor newDonor;
  newDonor.setDonorId(getValidatedInput("Id: "));

  std::cout << "Nombre: ";
  std::string name;
  std::getline(std::cin, name);
  newDonor.setName(name);

  std::cout << "Dirección: ";
  std::string address;
  std::getline(std::cin, address);
  newDonor.setAddress(address);

  displayProvinces();
  newDonor.setDistrict(getValidatedInput("departamento (ingrese el número correspondiente): "));

  // Muestra la lista de los tpos de sangre antes de pedir la entrada
  displayBloodTypes();
  std::string bloodType = Utils::getValidatedBloodType("Tipo de sangre: ");
  newDonor.setBloodType(bloodType, false);

  // Pide el numero de telefono y valida el mismo mediante el metodo de utils
  std::cout << "Número: ";
  std::string number;
  std::getline(std::cin, number);
  newDonor.setNumber(Utils::getValidatedPhoneNumber(number), false); // Validar el número

  donors.push_back(newDonor);
}


void BloodDatabase::writeDataToFile() {
  std::ofstream outfile(fileName, std::ios::app);

  if (!outfile) {
    std::cout << "Error al abrir el archivo para escribir." << std::endl;
    return;
  }

  Donor newDonor = donors.back();
  outfile << newDonor.getDonorId() << ",    " << newDonor.getName() << ",    "
          << newDonor.getAddress() << ",    " << newDonor.getDistrict()
          << ",    " << newDonor.getBloodType() << ",    "
          << newDonor.getNumber() << std::endl;

  outfile.close();
}

void BloodDatabase::searchAndDisplay() const {
  clearConsole();
  displayProvinces();
  int provinceName =
      getValidatedInput("Ingrese el número de la departamento: ");

  std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
  std::string addressFilter;
  std::getline(std::cin, addressFilter);

  displayBloodTypes();
  std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
  std::string bloodTypeFilter;
  std::getline(std::cin, bloodTypeFilter);

  std::ifstream inFile(fileName);

  if (!inFile) {
    std::cout << "Error al abrir el archivo para leer." << std::endl;
    return;
  }

  std::vector<Donor> donors;
  std::string line;
  bool found = false;

  while (std::getline(inFile, line)) {
    Donor d = Donor::parseLine(line);
    bool match =
        d.getDistrict() == provinceName &&
        (addressFilter.empty() ||
         d.getAddress().find(addressFilter) != std::string::npos) &&
        (bloodTypeFilter.empty() || d.getBloodType() == bloodTypeFilter);

    if (match) {
      donors.push_back(d);
      found = true;
    }
  }

  if (!found) {
    std::cout << "No se encontraron personas de la departamento "
              << provinceName;
    if (!addressFilter.empty()) {
      std::cout << " con dirección que contiene '" << addressFilter << "'";
    }
    if (!bloodTypeFilter.empty()) {
      std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
    }
    std::cout << "." << std::endl;
  } else {
    std::cout << "Personas de la departamento " << provinceName;
    if (!addressFilter.empty()) {
      std::cout << " con dirección que contiene '" << addressFilter << "'";
    }
    if (!bloodTypeFilter.empty()) {
      std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
    }
    std::cout << ":" << std::endl;
    for (const auto &d : donors) {
      std::cout << "Nombre: " << d.getName() << std::endl;
      std::cout << "Dirección: " << d.getAddress() << std::endl;
      std::cout << "departamento: " << d.getDistrict() << std::endl;
      std::cout << "Ingrese el tipo de sangre: " << d.getBloodType() << std::endl;
      std::cout << "Número de móvil: " << d.getNumber() << std::endl;
      std::cout << std::endl;
    }
  }

  inFile.close();
  waitForKeyPress();
}

void BloodDatabase::deleteDonor(const std::string &donorName) {
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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // descartar cualquier entrada extra

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
    std::cout << "No se encontró ningún donante con el nombre " << donorName
              << std::endl;
  }
}

void BloodDatabase::Display() const {
  clearConsole();
  std::ifstream inFile(fileName);

  if (!inFile) {
    std::cout << "Error al abrir el archivo para leer." << std::endl;
    return;
  }

  std::vector<Donor> donors;
  std::string line;

  while (std::getline(inFile, line)) {
    Donor d = Donor::parseLine(line);
    donors.push_back(d);
  }

  for (const auto& d : donors) {
    std::cout << "Nombre: " << d.getName() << std::endl;
    std::cout << "Dirección: " << d.getAddress() << std::endl;
    std::cout << "departamento: " << d.getDistrict() << std::endl;
    std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
    std::cout << "Número de móvil: " << d.getNumber() << std::endl;
    std::cout << std::endl;
  }


  inFile.close();
  waitForKeyPress();
}

// De aqui pabajo es lo que agregue

std::map<std::string, double> BloodDatabase::getBloodTypePercentages() const {
  std::map<std::string, int> bloodTypeCounts;
  for (const auto &donor : donors) {
    bloodTypeCounts[donor.getBloodType()]++;
  }

  std::map<std::string, double> percentages;
  int totalDonors = donors.size();
  for (const auto &count : bloodTypeCounts) {
    percentages[count.first] =
        (static_cast<double>(count.second) / totalDonors * 100);
  }

  return percentages;
}

std::string BloodDatabase::getMostCommonBloodType() const {
  std::map<std::string, int> bloodTypeCounts;
  for (const auto &donor : donors) {
    bloodTypeCounts[donor.getBloodType()]++;
  }

  auto max = std::max_element(
      bloodTypeCounts.begin(), bloodTypeCounts.end(),
      [](const std::pair<std::string, int> &a,
         const std::pair<std::string, int> &b) { return a.second < b.second; });

  return max->first;
}