#include <iostream>

const int M = 5; // rows
const int N = 4; // columns

void fill(double data[][N], const int sizex, const int sizey);
void print(double data[][N], const int sizex, const int sizey);
void print(double data[][M], const int sizex, const int sizey);
void transpose(double data[][N], double dataT[][M], const int sizex, const int sizey);

int main(int argc , char **argv)
{
    // declarar variables y matriz
    double matrix [M][N] {{0.0}};

    // llenar
    fill(matrix, M, N);

    // transponer
    double matrixT [N][M] {{0.0}};
    transpose(matrix, matrixT, M, N);

    // imprimir
    print(matrix, M, N);
    print(matrixT, N, M);

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

void print(double data[][M], const int sizex, const int sizey)
{
    for (int ix = 0; ix < sizex; ++ix) {
        for (int iy = 0; iy < sizey; ++iy) {
            std::cout << data[ix][iy] << "  ";
        }
        std::cout << "\n";
    }
}

void transpose(double data[][N], double dataT[][M], const int sizex, const int sizey)
{
   for (int ix = 0; ix < sizex; ++ix) {
       for (int iy = 0; iy < sizey; ++iy) {
           dataT[iy][ix] = data[ix][iy];
       }
    }
}
