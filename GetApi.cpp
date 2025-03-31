#include "GetApi.h"
#include <iostream>
#include <string>
#include "PeticionCurl.h"
using namespace std;
GetApi::GetApi() {
       cout<<"instanciado"<<endl;
}

string GetApi::apiverificarNumero(std::string phone){

       cout <<"Peticion TELEFONICA"<<endl;
       PeticionCurl peticion1;
       peticion1.peticionC("3001620310");
       string respuesta="hola";
return respuesta;
}




