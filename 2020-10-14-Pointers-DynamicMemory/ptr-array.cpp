#include <iostream>

int main(int argc, char **argv)
{
    const int N = 5; 
    int data [N] {1, 2};
    int * ptr = nullptr;

    std::cout <<  data[0] << std::endl; // 1
    std::cout << &data[0] << std::endl; // direccion de memoria del primer elemento
    std::cout <<  data    << std::endl; // direccion del primer elemento
    std::cout << (data+1) << std::endl; // direccion de la segunda casilla
    std::cout << *(data+1)<< std::endl; // valor en la segunda casilla
    //std::cout << (data+N) << std::endl; // direccion de la ultima? casilla
    //std::cout << *(data+N)<< std::endl; // valor en la ultima? casilla

    std::cout << "prt -> " << ptr << std::endl;
    //ptr = &N;
    //std::cout << "prt -> " << ptr << std::endl;
    ptr = data;
    std::cout << "prt -> " << ptr << std::endl;
    std::cout << "*(prt+1): " << *(ptr+1) << std::endl;

    // data = &N; // ERROR: data no puede apuntar a otras direcciones de memoria

    return 0;
}
