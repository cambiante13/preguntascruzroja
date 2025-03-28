/*
**********************************************************************************
CASO DE ESTUDIO: SISTEMA DE GESTIÓN DE DONANTES DE SANGRE - CRUZ ROJA
**********************************************************************************
Este proyecto fue desarrollado como parte del curso de Fundamentos de Programación
Orientada a Objetos, a cargo del profesor Victor Bucheli. Nuestro objetivo
principal es mejorar el encapsulamiento, la reutilización de código y la claridad
del diseño, aplicando buenas prácticas de programación orientada a objetos de acuerdo a lo visto en clase.

Tambien implementamos nuevas funcionalidades, como la validación de números
telefónicos mediante una API y la optimización del manejo de archivos para
almacenar y recuperar datos de donantes.


**********************************************************************************
AUTOR DEL ARCHIVO: Victor Bucheli
**********************************************************************************
Resolucion de caso de estudio hecha por:

- Valentina Montezuma Gonzalez - valentina.montezuma@correounivalle.edu.co - CODE(2242058)
- Julian Meneses Moncada - meneses.julian@correounivalle.edu.co- CODE(2042970)
- Joan Sebastian Rivera - rivera.joan@correounivalle.edu.co- CODE(2222936)
- Nombre - Correo Electrónico - CODE()

================================================================================
DESCRIPCIÓN DEL PROYECTO:
================================================================================
El sistema permite registrar, buscar, eliminar y visualizar donantes de sangre.
Los datos se almacenan en un archivo de texto para persistencia. Se implementaron
clases como Donor, DonorManager, FleHandler y UserInterface para lograr
un diseño modular y mantenible.

Descripcion precisa en el entregable del taller.

================================================================================
FECHA DE ÚLTIMA MODIFICACIÓN: 22/03/25
================================================================================
*/

#include "DonorManager.h"
#include "UserInterface.h"
#include "FileHandler.h"
#include "Donor.h"
#include <iostream>
#include <limits>
#include <string>
#include "GetApi.h"
#include "PeticionCurl.h"
using namespace std;

//Funcion principal del programa
int main() {
    std::string donorName;
    DonorManager donorManager("data.txt");
    UserInterface ui;
    int choice;
    GetApi prueba1;

    while (true) {
        ui.clearConsole();

        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        //ESTE ES EL MENU DEL USUARIO CON SUS DIFERENTES OPCIONES A TOMAR

        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Historial donantes\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            donorManager.getDonorDetails();
            break;
        case 2:
            donorManager.searchAndDisplay();
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName);
            donorManager.deleteDonor(donorName);
            ui.waitForKeyPress();
            break;
        case 4:
            donorManager.displayAllDonors();
            break;
        case 5:
            std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
            return 0;
            break;
        case 6:
            prueba1.verificarNumero("3202699215");
            break;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            ui.waitForKeyPress();
            break;
        }
    }
}
