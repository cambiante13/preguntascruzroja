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
    cout<<"digite el numero con indicativo"<<endl;
    cin>>this->telefono;    
    // Inicializa una sesión de CURL y asigna el manejador a la variable 'hnd'
    PeticionCurl peticion1;
    peticion1.PedirCurl(numero);
    return "correcto";
}
