#include <iostream>
#include <cmath>

// calcular la derivada forward del sin
// graficar x \in [0, 2pi] y comparar errores

// DX = 0.1, [0, 1] -> x  0.0 0.1 0.2 0.3 0.4 0.5 ...
//                     ii 0   1   2   3   4   5

double f(double x);
double deriv_forward(double x, double h);
double deriv_central(double x, double h);

int main(int argc, char **argv)
{
    const double DX = 0.01;
    const double XMIN = 0.0;
    const double XMAX = 2*M_PI;
    
    const int N = (XMAX - XMIN)/DX;
    for (int ii = 0; ii < N; ++ii) {
        double x = XMIN + ii*DX;
        double error_forward = std::fabs(1 - deriv_forward(x, DX)/std::cos(x));
        double error_central = std::fabs(1 - deriv_central(x, DX)/std::cos(x));
        std::cout << x
                  << "\t" << error_forward
                  << "\t" << error_central
                  << "\n"; 
    }
    
    return 0;
}

double f(double x)
{
    return std::sin(x);
}

double deriv_forward(double x, double h)
{
    return (f(x+h) - f(x))/h;
}

double deriv_central(double x, double h)
{
    return (f(x+h/2) - f(x-h/2))/h;
}
