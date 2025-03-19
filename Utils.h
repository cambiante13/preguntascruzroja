#ifndef UTILS_H
#define UTILS_H
//Clase nueva ya que trim no era necesario poner en Donor pues se necesita en otras clases asi que le hice una
#include <string> 
#include <algorithm>

class Utils {
public:
    static std::string trim(const std::string& str);
};

#endif 