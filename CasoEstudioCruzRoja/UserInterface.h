#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

// Clase UserInterface que gestiona la interacción con el usuario, mostrando mensajes y solicitando entradas
class UserInterface {
public:
    // Muestra una lista de tipos de sangre válidos
    void displayBloodTypes() const;

    // Muestra una lista de departamentos para que el usuario elija
    void displayProvinces() const;

    // Limpia la consola
    void clearConsole() const;

    // Espera a que el usuario presione una tecla para continuar
    void waitForKeyPress() const;

    // Solicita una entrada numérica al usuario
    int getValidatedInput(const std::string& prompt) const;
};

#endif