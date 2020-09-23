#include <iostream>
#include <cmath>

using fptr = double(double);
double f(double x);
double g(double x);
double deriv(double x);
double bisection(double xl, double xu, double eps, fptr fun);
double regulafalsi(double xl, double xu, double eps, fptr fun);
double fixedpoint(double x0, double eps, fptr gfun, fptr fun);
double newton(double x0, double eps, fptr fun, fptr fderiv);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    double xl = 1;
    double xu = 20.0;
    double eps = 1.0e-12;

    double xroot = bisection(xl, xu, eps, f);
    std::cout << xroot << "\t" << f(xroot) << "\n";
    xroot = regulafalsi(xl, xu, eps, f);
    std::cout << xroot << "\t" << f(xroot) << "\n";
    double x0 = 10;
    xroot = fixedpoint(x0, eps, g, f);
    std::cout << xroot << "\t" << f(xroot) << "\n";
    xroot = newton(x0, eps, f, deriv);
    std::cout << xroot << "\t" << f(xroot) << "\n";

    return 0;
}

double f(double x)
{
    const double G = 9.81;
    const double M = 68.1;
    const double T = 10.0;
    const double VF = 40.0;
    return (M*G*(1 - std::exp(-x*T/M))/x) - VF;
}

double g(double x)
{
    const double G = 9.81;
    const double M = 68.1;
    const double T = 10.0;
    const double VF = 40.0;
    return (M*G*(1 - std::exp(-x*T/M)))/VF; //=x
    //return f(x) + x; // lazy
}

double deriv(double x)
{
    double h = 0.0001;
    return (f(x+h/2) - f(x-h/2))/h;
}                                                \

double bisection(double xl, double xu, double eps, fptr fun)
{
    const int NITERMAX = 1000;
    double xr = 0;
    int niter = 0;
    while (niter <= NITERMAX) {
        xr = 0.5*(xl + xu);
        if (std::fabs(fun(xr)) <= eps) {
            break;
        } else if (fun(xr)*fun(xu) > 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        niter++;
    }
    std::cout << "Bisection Info -> Niter: " << niter << "\n";
    return xr;
}

double regulafalsi(double xl, double xu, double eps, fptr fun)
{
    const int NITERMAX = 1000;
    double xr = 0;
    int niter = 0;
    while (niter <= NITERMAX) {
        double fxu = fun(xu);
        double fxl = fun(xl);
        xr = xu - (fxu*(xl-xu))/(fxl - fxu);
        if (std::fabs(fun(xr)) <= eps) {
            break;
        } else if (fun(xr)*fun(xu) > 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        niter++;
    }
    std::cout << "RegulaFalsi Info -> Niter: " << niter << "\n";
    return xr;
}

double fixedpoint(double x0, double eps, fptr gfun, fptr fun)
{
    const int NITERMAX = 1000;
    double xr = x0;
    int niter = 0;
    while (niter <= NITERMAX) {
        xr = gfun(xr);
        if (std::fabs(fun(xr)) <= eps) {
            break;
        } 
        niter++;
    }
    std::cout << "Fixedpoint Info -> Niter: " << niter << "\n";
    return xr;
}

double newton(double x0, double eps, fptr fun, fptr fderiv)
{
    const int NITERMAX = 1000;
    double xr = x0;
    int niter = 0;
    while (niter <= NITERMAX) {
        xr = xr - fun(xr)/fderiv(xr);
        if (std::fabs(fun(xr)) <= eps) {
            break;
        } 
        niter++;
    }
    std::cout << "Newton Info -> Niter: " << niter << "\n";
    return xr;
}
