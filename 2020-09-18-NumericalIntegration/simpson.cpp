#include <iostream>
#include <cmath>
#include <functional>

using fptr  = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double g(double x);
double trapecio(fptr fun, double a, double b, int N);
double simpson(fptr fun, double a, double b, int N);
double richardson(fptr2 alg, fptr fun, double a, double b, int N);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    
    const double xmin = 0.0;
    const double xmax = 1.0;

    for(int NMAX = 1; NMAX <= 1.0e8; NMAX *= 10) {
        double intnum_trapecio = trapecio(f, xmin, xmax, NMAX);
        double intnum_traprich = richardson(trapecio, f, xmin, xmax, NMAX);
        double intnum_simpson  = simpson(f, xmin, xmax, NMAX);
        double inttheo = -std::cos(xmax) + std::cos(xmin);
        double delta_trapecio = std::fabs(1 - intnum_trapecio/inttheo);
        double delta_simpson  = std::fabs(1 - intnum_simpson/inttheo);
        double delta_traprich = std::fabs(1 - intnum_traprich/inttheo);
        std::cout << NMAX
                  << "\t" << delta_trapecio
                  << "\t" << delta_traprich
                  << "\t" << delta_simpson
                  << "\n";
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

double richardson(fptr2 alg, fptr fun, double a, double b, int N)
{
    return (4*alg(fun, a, b, 2*N) - alg(fun, a, b, N))/3;
}

double simpson(fptr fun, double a, double b, int N)
{
    const double h = (b-a)/N;
    double suma = 0; 
    double aux1 = 0, aux2 = 0;

    for(int ii = 1; ii <= N/2 -1; ++ii) {
        double x = a + 2*ii*h;
        aux1 += fun(x);
    }
    for(int ii = 1; ii <= N/2; ++ii) {
        double x = a + (2*ii-1)*h;
        aux2 += fun(x);
    }
    suma = h*(fun(a) + 2*aux1 + 4*aux2 + fun(b))/3;
    return suma;
}
