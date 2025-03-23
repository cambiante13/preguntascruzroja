#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "Donor.h"

// Clase FileHandler que gestiona la lectura y escritura de datos de donantes en un archivo
class FileHandler {
private:
    std::string fileName; // Nombre del archivo donde se almacenan los datos

public:
    // Constructor: Inicializa FileHandler con el nombre del archivo de datos
    FileHandler(const std::string& fileName);

    // Escribe los datos de un donante en el archivo
    void writeDataToFile(const Donor& donor) const;

    // Busca los donantes que coincidan con los criterios de búsqueda
    std::vector<Donor> searchAndDisplay(int provinceName, const std::string& addressFilter, const std::string& bloodTypeFilter) const;

    // Elimina un donante por nombre y pide la confirmación antes de eliminarlo
    void deleteDonor(const std::string& donorName) const;

    // Muestra todos los donantes registrados en el archivo
    void displayAllDonors() const;
};

#endif