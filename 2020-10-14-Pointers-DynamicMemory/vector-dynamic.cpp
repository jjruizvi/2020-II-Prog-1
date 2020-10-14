#include <iostream>
#include <vector>

typedef std::vector<int> data_t;


int main(int argc, char **argv)
{
    const int N = 81000000; // memory size: N*4 -> max 2048000 
    data_t data(N);
    std::cout << data[0] << std::endl;

    // crear un nuevo bloque de tamanho N/2
    // copiar los N/2 elementos viejos en el nuevo bloque
    // liberar la memoria del viejo bloque
    data.resize(N/2);

    data.reserve(1000);
    data.push_back(1);
    data.push_back(10);
    // ... 998
    data.push_back(20);
    // pedir nueva memoria // 2*1000 = 2000
    // copiar los datos viejos en la nueva memoria
    // liberar la memoria vieja
    data.push_back(30);

    data.size(); // cuantos datos tengo guardados
    data.capacity();
    
    return 0;
}

