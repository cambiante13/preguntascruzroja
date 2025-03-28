#include "GetApi.h" 
#include "PeticionCurl.h"
#include <sys/types.h> 
#include <sys/socket.h> 
#include <curl/curl.h> 
#include "nlohmann/json.hpp" 
#include <sstream> 
#include <string>
using namespace std;

string GetApi::verificarNumero(string numero){

     std::string phone="3001620310";
    // Inicializa una sesión de CURL y asigna el manejador a la variable 'hnd'
    PeticionCurl::PedirCurl
        nlohmann::json jsonResponse = nlohmann::json::parse(responseString);

                // Acceder a los datos del JSON
                std::cout << "IMC: " << jsonResponse["isValid"] << std::endl;
         return 0;       
       // return responseString;



}
