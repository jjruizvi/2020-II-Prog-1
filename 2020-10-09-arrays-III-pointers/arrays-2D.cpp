#include <iostream>

const int M = 5; // rows
const int N = 4; // columns

void fill(double data[][N], const int sizex, const int sizey);
void print(double data[][N], const int sizex, const int sizey);

int main(int argc , char **argv)
{
    // declarar variables y matriz
    double matrix [M][N] {{0.0}};
    print(matrix, M, N);
    // llenar
    fill(matrix, M, N);
    print(matrix, M, N);
    
    
    // transponer

    // imprimir

    return 0;
}

void fill(double data[][N], const int sizex, const int sizey)
{
    for (int ix = 0; ix < sizex; ++ix) {
        for (int iy = 0; iy < sizey; ++iy) {
            data[ix][iy] = ix*sizey + iy;
        }
    }
}

void print(double data[][N], const int sizex, const int sizey)
{
    for (int ix = 0; ix < sizex; ++ix) {
        for (int iy = 0; iy < sizey; ++iy) {
            std::cout << data[ix][iy] << "  ";
        }
        std::cout << "\n";
    }
}
