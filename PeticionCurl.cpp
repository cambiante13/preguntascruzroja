#include "PeticionCurl.h" 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <curl/curl.h> 
#include "nlohmann/json.hpp" 
#include <sstream> 
#include <string>
using namespace std;

std::string PeticionCurl::PedirCurl() {
    CURL *hnd = curl_easy_init();
    std::stringstream url;
    std::string phone = "573001620310";  // Definir el número antes de usarlo
    url << "https://phone-validator-api.p.rapidapi.com/valid?phone=" << phone;
    std::string urlStr = url.str();
    curl_easy_setopt(hnd, CURLOPT_URL, urlStr.c_str());

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-key: e1a56d8691msh2a9fef915503ef4p1d3d41jsn0f491cf35358");
    headers = curl_slist_append(headers, "x-rapidapi-host: phone-validator-api.p.rapidapi.com");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    std::string responseString;
    FILE* fp = fopen("/tmp/phone_response.txt", "wb");
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);

    CURLcode ret = curl_easy_perform(hnd);

    if (ret == CURLE_OK) {
        fclose(fp);
        fp = fopen("/tmp/phone_response.txt", "r");
        if (fp) {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                responseString += buffer;
            }
            fclose(fp);
        }
    } else {
        std::cerr << "Error en la solicitud CURL: " << curl_easy_strerror(ret) << std::endl;
    }
    cout << responseString << endl;
    curl_slist_free_all(headers);
    curl_easy_cleanup(hnd);

    return responseString;  // Retornamos la respuesta
}