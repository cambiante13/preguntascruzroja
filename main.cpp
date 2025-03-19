/*
PREGUNTAS CASO DE ESTUDIO

1. Las clases que identificamos en el caso de estudio son la clase donante Donor y la de la base de datos BloodDatabase. Si consideramos que las clases representan objetos más pequeños y manejables, en el caso de la clase Donor sería el donante individual a quien representa. Encontramos que el programa se encuentra dividido en el main, ya que a diferencia del resto, en este solo se usan los métodos ya definidos y se corre el programa en sí.
2. Consideramos que la respuesta es verdadera ya que efectivamente al utilizar las clases el código se hace menos complejo y extenso de manera innecesaria, permitiéndonos acceder a él e identificar los errores de manera más sencilla al igual que la solución de los mismos sin terminar por afectar el resto de código.
3. Nuevamente, consideramos que la afirmación es verdadera ya que las clases al ser individuales entre sí permiten su modificación sin afectar a las otras clases, de igual forma, promueve el trabajo en equipo pues esto mismo permite que los desarrolladores trabajen simultáneamente en diferentes clases sin que se afecten entre sí.
4. Los códigos que utilizamos nuevamente fueron el getline cuando necesitábamos recibir la respuesta en el formato de string. El displayprovinces igualmente a la hora de realizar el mismo proceso con los tipos de sangre de los pacientes, así como los códigos subyacentes de los que dependen estos para funcionar.
5. Es una afirmación verdadera, ya que como se mencionó anteriormente, las clases mediante la herencia pueden usarse para reutilizarse tanto en el mismo programa como en proyectos diferentes, incluso con modificaciones de las mismas, es decir, clases derivadas de otras clases para no repetir un proceso que ya se hizo previamente y como nos dice la afirmación, consiguiendo reducir el esfuerzo de desarrollo.
6. Si, ya que al tratarse de una base de datos se debe de ocultar la información confidencial que evite cualquier tipo de contratiempos futuros.
7. Consideramos que hay una consistencia clara en el código, ya que sigue un mismo modelo entre sus partes, reutilización de las clases y que al ser uniforme nos permite una mejor comprensión del código para su lectura y modificación al igual que para el desarrollo de los puntos propuestos.
8. Las nuevas funcionalidades que añadimos a la aplicación fueron el historial de donaciones, que se realizó con ayuda del profesor. De igual manera se adicionó el displaybloodtype como derivado de displayprovinces que permitía a los usuarios ver los tipos de sangre a manera de lista.
9. El código es bastante comprensible, ya que está organizado según sus funcionalidades y está escrito de manera coherente que permite su comprensión, a pesar de ser un lenguaje nuevo al que nos estamos adentrando.
10. Consideramos que la dificultad en el caso de actualizar y mejorar el código depende de casos específicos. A la hora de encontrar bugs es algo complejo debido a lograr encontrarlo, otros casos como el de añadir la lista de sangre eran un poco más sencillos al ser más intuitivos, sin embargo consideramos que no se debe a que el código en sí esté mal sino más bien a la poca experiencia y conocimiento que tenemos actualmente del lenguaje. 
11. Con conocimientos de la programación orientada a objetos y el lenguaje en cuestión, consideramos que el código está escrito de manera clara y que sus objetos a pesar de tener variaciones son lo suficientemente parecidos para considerarlos de una misma clase con similares características de la misma manera en que funciona en el mundo real.
12. Consideramos que sí, ya que es la finalidad de este tipo de programas. y que de haber un error que ocasione lo contrario debe arreglarse o incluso mejorarse para que sean los resultados más correctos, precisos y legibles dentro de lo posible.

 */
#include "BloodDatabase.h"
#include "Donor.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    std::string donorName;
    BloodDatabase database;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();

        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Historial donantes\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

        switch (choice) {
        case 1:
            database.getDonorDetails();
            database.writeDataToFile();
            break;
        case 2:
            database.searchAndDisplay();
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName);
            database.deleteDonor(donorName);
            BloodDatabase::waitForKeyPress();
            break;
        case 4:
            database.Display();
            break;
        case 5:
            std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
            return 0;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            BloodDatabase::waitForKeyPress();
            break;
        }
    }
}
