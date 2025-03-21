/*
CASO DE ESTUDIO CRUZ ROJA - MEJORA DE ENCAPSULAMIENTO Y PRUEBAS UNITARIAS

Este es un trabajo realizado en la clase de Fundamentos de Porgramacion Orientada a Objetos a cargo de Victor Bucheli quien es autor del presente archivo.

Las personas implicadas en la solcion del taller son:

- Valentina Montezuma Gonzalez (202242059) (valentina.montezuma@correounivalle.edu.co)
-
-
-

El trabajo tiene como fin hacer un analisis y optimizacion del codigo, mejorando su encapsulamiento, haciendo reutilizacion de codigo y aplicando algunas funciones nuevas como lo es el uso de una API para la validacion de numeros telefonicos.
En el entregable se encuentra todo de manera mas detallada.

Ultima vez modificado: 20/03/25
 */
#include "BloodDatabase.h"
#include "Donor.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    std::string donorName;
    BloodDatabase database;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();

        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Historial donantes\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

        switch (choice) {
        case 1:
            database.getDonorDetails();
            database.writeDataToFile();
            break;
        case 2:
            database.searchAndDisplay();
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName);
            database.deleteDonor(donorName);
            BloodDatabase::waitForKeyPress();
            break;
        case 4:
            database.Display();
            break;
        case 5:
            std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
            return 0;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            BloodDatabase::waitForKeyPress();
            break;
        }
    }
}
