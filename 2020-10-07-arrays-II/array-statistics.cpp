#include <iostream>
#include <algorithm>
#include <numeric>

double statistics1(const double data[], int size);

int main(int argc, char **argv)
{
    // array declaration
    int N = 99; 
    double array [N] {0.0};

    // array filling
    fillarray(data, size); // numeros aleatorios 
    //double x = -19.8765;
    //std::fill(array, array+N, x);
    std::iota(array, array+N, 1); // (1 + 2 + 3 + 4 + .. + N)/N = N(N+1)/2N = (N+1)/2
    
    // processing
    double result = statistics1(array, N);
    std::cout << result << std::endl;

    return 0;
}

double statistics1(const double data[], int size)
{
    double mean = 0.0;

    for(int ii = 0; ii < size; ++ii) {
        mean += data[ii];
    }
    
    return mean/size;
}
