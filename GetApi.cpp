#include "GetApi.h" 
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
    CURL *hnd = curl_easy_init();
    // Usar std::stringstream para construir la URL dinámicamente
    std::stringstream url; // Crea un objeto stringstream para construir la URL
    // Inserta el telefono en la url
    url << "https://phone-validator-api.p.rapidapi.com/valid?phone="+phone;

    // Convierte el contenido del stringstream a un std::string
    std::string urlStr = url.str();
    // Convierte el std::string a un C-string y configura la URL para la solicitud CURL
    curl_easy_setopt(hnd, CURLOPT_URL, urlStr.c_str());

    // Inicializa un puntero a una lista de encabezados para la solicitud HTTP
    struct curl_slist *headers = NULL;
    // Añade el encabezado de la clave de API a la lista de encabezados
    headers = curl_slist_append(headers, "x-rapidapi-key: e1a56d8691msh2a9fef915503ef4p1d3d41jsn0f491cf35358");
    // Añade el encabezado del host a la lista de encabezados
    headers = curl_slist_append(headers, "x-rapidapi-host: phone-validator-api.p.rapidapi.com");
    // Configura la solicitud CURL para usar los encabezados definidos
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

// Aquí creamos un std::string para almacenar el resultado
        std::string responseString;
        std::string tempBuffer;

        // Capturar la salida estándar y redirigirla al string
        FILE* fp = fopen("/tmp/phone_response.txt", "wb"); // Archivo temporal
        curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);    // Escribe la salida al archivo


    // Realiza la solicitud CURL
    CURLcode ret = curl_easy_perform(hnd);

     // Si la solicitud es exitosa, leemos el archivo temporal a un std::string
        if (ret == CURLE_OK) {
            fclose(fp);  // Cerramos el archivo
            fp = fopen("/tmp/phone_response.txt", "r"); // Lo abrimos para leer
            if (fp) {
                char buffer[1024]; // Buffer temporal para leer
                while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                    responseString += buffer; // Acumulamos en responseString
                }
                fclose(fp);
                std::cout<<"dio:"<<responseString;
            }
        } else {
            std::cerr << "Error en la solicitud CURL: " << curl_easy_strerror(ret) << std::endl;
        }

        // Limpia los recursos
        curl_slist_free_all(headers);
        curl_easy_cleanup(hnd);
        nlohmann::json jsonResponse = nlohmann::json::parse(responseString);

                // Acceder a los datos del JSON
                std::cout << "IMC: " << jsonResponse["isValid"] << std::endl;
         return 0;       
       // return responseString;



}
