#include <iostream>
#include <vector>  // {1, 2, 3, 4, -9}
#include <algorithm> // copy, sort, transfrom ... 
#include <cmath>

int main(int argc, char **argv)
{
    std::vector<int> data = {3, 4, -1, -10, 0}; 

    auto comp = [](int a, int b){ return std::abs(a) < std::abs(b); };

    std::sort(data.begin(), data.end(), comp);

    for(int ii = 0; ii < 5; ++ii) {
        std::cout << "data[" << ii << "]: " << data[ii] << "\n";
    }
    
    return 0;
}
