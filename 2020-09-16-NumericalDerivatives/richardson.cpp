#include <iostream>
#include <cmath>
#include <functional>

using fptr = double(double, double); 

// calcular la derivada forward del sin
// graficar x \in [0, 2pi] y comparar errores

// DX = 0.1, [0, 1] -> x  0.0 0.1 0.2 0.3 0.4 0.5 ...
//                     ii 0   1   2   3   4   5

double f(double x);
double deriv_forward(double x, double h);
double deriv_central(double x, double h);
double richardson_forward(double x, double h);
double richardson_central(double x, double h);
double richardson(double x, double h, fptr fun);

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
        //double error_richardson_forward = std::fabs(1 - richardson_forward(x, DX)/std::cos(x));
        //double error_richardson_central = std::fabs(1 - richardson_central(x, DX)/std::cos(x));
        double error_richardson_forward = std::fabs(1 - richardson(x, DX, deriv_forward)/std::cos(x));
        double error_richardson_central = std::fabs(1 - richardson(x, DX, deriv_central)/std::cos(x));
        std::cout << x
                  << "\t" << error_forward
                  << "\t" << error_central
                  << "\t" << error_richardson_forward
                  << "\t" << error_richardson_central
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

/*
double richardson_forward(double x, double h)
{
    double D1 = deriv_forward(x, h);
    double D2 = deriv_forward(x, h/2);
    
    return (4*D2 - D1)/3.0;
}

double richardson_central(double x, double h)
{
    double D1 = deriv_central(x, h);
    double D2 = deriv_central(x, h/2);
    
    return (4*D2 - D1)/3.0;
}
*/

double richardson(double x, double h, fptr fun)
{
    double D1 = fun(x, h);
    double D2 = fun(x, h/2);
    
    return (4*D2 - D1)/3.0;

}
