#include <iostream>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void verifyPhoneNumber(const std::string& phone) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    std::string apiKey = "dc85ed7ffamsh86012158add4b94p1fefabjsnbcc789b8d6"; // Reemplázalo con tu clave API
    std::string ur = "http:/";
    std::string l = "/apilayer.net/api/validate?access_key=" + apiKey + "&number=" + phone;
    std::string url = ur + l;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            std::cout << "Respuesta de la API: " << readBuffer << std::endl;
        } else {
            std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
        }
    }
}

int main() {
    std::string phoneNumber;
    std::cout << "Ingresa el número de teléfono a verificar: ";
    std::cin >> phoneNumber;

    verifyPhoneNumber(phoneNumber);
    return 0;
}
