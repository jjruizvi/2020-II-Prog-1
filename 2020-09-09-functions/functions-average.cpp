#include <iostream>

double average(const double & k, double y);

int main(void)
{
    double x = 9.8, y = -10.76, z = 0;
    std::cout << "main:    " << x << std::endl;
    z = average(x, y);
    std::cout << z << std::endl;
    std::cout << "main:    " << &x << std::endl;
    std::cout << "main:    " << x << std::endl;
    return 0;
}

double average(const double & k, double y)
{
    double result = 0;
    result = 0.5*(k + y);
    std::cout << "average: " << &k << std::endl;
    //k = 25.768543; // ERROR
    return result;
}
