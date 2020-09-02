#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string fullname;
    std::cout << "Hola, escribe tu nombre, por favor:\n";
    std::getline(std::cin, fullname); // lee toda la linea, incluidos espacios
    //std::cin >> fullname;
    std::cout << "Hola, " << fullname << std::endl;

    return 0;
}
