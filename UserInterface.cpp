#include "UserInterface.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

// Clase UserInterface que gestiona la interacción con el usuario, mostrando mensajes y solicitando entradas
void UserInterface::displayBloodTypes() const {
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

// Muestra una lista de departamentos para que el usuario elija uno
void UserInterface::displayProvinces() const {
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

// Limpia la consola
void UserInterface::clearConsole() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Espera a que el usuario presione una tecla para continuar
void UserInterface::waitForKeyPress() const {
    std::cout << "Presiona cualquier tecla para continuar...";
    //std::cin.ignore();
    std::cin.get();
}

// Solicita una entrada numérica al usuario
int UserInterface::getValidatedInput(const std::string& prompt) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (Utils::isValidNumber(input)) {
            try {
                return Utils::convertToInt(input);
            } catch (const std::invalid_argument& e) {
                std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
            }
        } else {
            std::cout << "Entrada no válida. Por favor ingrese un número válido." << std::endl;
        }
    }
}