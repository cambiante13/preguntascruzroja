#include "GetApi.h" 
#include "PeticionCurl.h"
#include <sys/types.h> 
#include <sys/socket.h> 
#include <curl/curl.h> 
#include "nlohmann/json.hpp" 
#include <sstream> 
#include <string>
using namespace std;

string GetApi::verificarNumero(string numero) {
    PeticionCurl peticion;  // Crear objeto de PeticionCurl
    peticion.PedirCurl();   // Llamar al método

    // Aquí faltaba manejar la respuesta correctamente.
    // La respuesta de la API debería ser capturada de alguna forma.
    // Posiblemente deberíamos modificar PedirCurl() para que retorne un string con la respuesta.

    return "Solicitud enviada"; // Retorno provisional
}

