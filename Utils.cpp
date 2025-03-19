#include "Utils.h"
#include <string>  // Para std::string
#include <algorithm>  // Para std::find_first_not_of y pa  std::find_last_not_of

std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}