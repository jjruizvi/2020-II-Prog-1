#include <iostream>

int main(int argc, char **argv)
{
    // tipos primitivos
    double x {-9.6e3}; // 64 bits, 8 bytes, 1.0e-16, 2^1024 \simeq (10^307)
    long double y = -9.6e3; // > 64 bits
    float z = 10.54e-8; // 32 bits, 1.0e-6, 10^40
    int a = 5678; //
    long int b = -98765443; //
    short int c = 678;
    char l = 'a';
    bool flag = true; 

    std::cout << sizeof(bool) << std::endl;

    std::cout << sizeof(short int) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long int) << std::endl;

    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long double) << std::endl;
    
    return 0;
}
