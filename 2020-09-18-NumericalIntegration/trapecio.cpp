#include <iostream>
#include <cmath>
#include <functional>

using fptr = double(double);

double f(double x);
double trapecio(fptr fun, double a, double b, int N);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    
    const double xmin = 0.0;
    const double xmax = 1.0;

    for(int NMAX = 1; NMAX <= 1.0e6; NMAX *= 10) {
        double intnum_trapecio = trapecio(f, xmin, xmax, NMAX); 
        double inttheo = -std::cos(xmax) + std::cos(xmin); 
        double delta_trapecio = std::fabs(1 - intnum_trapecio/inttheo);
        std::cout << NMAX << "\t" << delta_trapecio << "\n";
    }
    
    return 0;
}

double f(double x)
{
    return std::sin(x);
}

double trapecio(fptr fun, double a, double b, int N)
{
    const double h = (b-a)/N;
    double suma = 0.5*(fun(a) + fun(b));
    for(int ii = 1; ii <= N-1; ++ii) {
        double xi = a + ii*h;
        suma += fun(xi);
    }
    suma *= h;
    return suma;
}
