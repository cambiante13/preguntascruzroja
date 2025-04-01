#include "GetApi.h"
#include <iostream>
#include <string>
#include "PeticionCurl.h"
#include "FileHandler.h"
using namespace std;
GetApi::GetApi() {
       cout<<"instanciado"<<endl;
}

string GetApi::apiverificarNumero(std::string phone){

       cout <<"Peticion TELEFONICA"<<endl;
       PeticionCurl peticion1;
       //en esta parte vamos a recibir la respuesta filtrada y haremos respuesta logica para pasarsela al main como valido o no valido
       FileHandler respuesta1;
       string es_valido=respuesta1.JSON(peticion1.peticionC(phone));
return es_valido;
}




