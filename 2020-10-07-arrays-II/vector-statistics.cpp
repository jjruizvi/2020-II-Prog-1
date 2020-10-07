#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

double statistics1(const std::vector<double> & data);
void fillarray(std::vector<double> & data);

int main(int argc, char **argv)
{
    const int N = 1000;
    // array declaration
    std::vector<double> array;
    array.resize(N);

    // array filling
    fillarray(array);
    
    // processing
    double result = statistics1(array);
    std::cout << result << std::endl;

    return 0;
}

void fillarray(std::vector<double> & data)
{
    // double x = -19.8765;
    // std::fill(data, data+size, x);
    // std::iota(data, data+size, 1); // (1 + 2 + 3 + 4 + .. + N)/N = N(N+1)/2N = (N+1)/2
    // numeros aleatorios
    const int SEED = 0;
    std::mt19937 mt(SEED);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (auto & val : data) {
        val = dist(mt);
    }
}


double statistics1(const std::vector<double> & data)
{
    double suma = 0.0;
    for(auto val : data) {
        suma += val;
    }
    return suma/data.size();
}
