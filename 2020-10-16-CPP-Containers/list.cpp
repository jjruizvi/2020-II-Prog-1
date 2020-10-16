// from: https://en.cppreference.com/w/cpp/container/list

#include <algorithm>
#include <iostream>
#include <list>
#include <cmath>
 
int main()
{
    // Create a list containing integers
    std::list<int> l = { 7, 5, 16, 8 };
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, -42);
    }
 
    // Iterate and print values of the list
    for (int n : l) {
        std::cout << n << '\n';
    }

    std::cout << "empty: " << l.empty() << std::endl;
    std::cout << "size : " << l.size() << std::endl;
    std::cout << "max_size: " << l.max_size() << std::endl;

    std::cout << "Default sort ... \n";
    l.sort();
    for (int n : l) {
        std::cout << n << '\n';
    }

    std::cout << "Custom sort ... \n";
    l.sort([](int m, int n) { return std::abs(m) < std::abs(n); });
    for (int n : l) {
        std::cout << n << '\n';
    }

    return 0;
}
