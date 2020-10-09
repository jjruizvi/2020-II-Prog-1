#include <iostream>
#include <vector>

typedef std::vector<double> DataT; 

void fill(DataT & data, const int sizex, const int sizey);
void print(const DataT & data, const int sizex, const int sizey);
void transpose(DataT & data, DataT & dataT, const int sizex, const int sizey);

int main(int argc , char **argv)
{
    const int M = 5; // rows
    const int N = 4; // columns

    // declarar variables y matriz
    DataT matrix(M*N, 0.0);

    // llenar
    fill(matrix, M, N);

    // transponer
    DataT matrixT(N*M, 0.0);
    transpose(matrix, matrixT, M, N);

    // imprimir
    print(matrix, M, N);
    print(matrixT, N, M);

    return 0;
}

void fill(DataT & data, const int sizex, const int sizey)
{
    for (int ix = 0; ix < sizex; ++ix) {
        for (int iy = 0; iy < sizey; ++iy) {
            // data[ix][iy] = ix*sizey + iy;
            data[ix*sizey + iy] = ix*sizey + iy;
        }
    }
}

void print(const DataT & data, const int sizex, const int sizey)
{
    for (int ix = 0; ix < sizex; ++ix) {
        for (int iy = 0; iy < sizey; ++iy) {
            std::cout << data[ix*sizey + iy] << "  ";
        }
        std::cout << "\n";
    }
}

void transpose(DataT & data, DataT & dataT, const int sizex, const int sizey)
{
   for (int ix = 0; ix < sizex; ++ix) {
       for (int iy = 0; iy < sizey; ++iy) {
           dataT[iy*sizex + ix] = data[ix*sizey + iy];
       }
    }
}
