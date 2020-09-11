#include <iostream>
#include <cstdlib>

template <typename T, typename S>
T getmax(T a, S b)
{
    T result = a;
    if (b > a) {
        result = b;
    }
    return result;
}


int main(int argc, char **argv)
{
    std::cout << getmax(-1, -2) << std::endl;
    std::cout << getmax(2.49, 2.51) << std::endl;
    std::cout << getmax(2.49, 2) << std::endl;
    std::cout << getmax(2, 2.98) << std::endl;
    
    return 0;
}
