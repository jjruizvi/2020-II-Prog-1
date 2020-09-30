#include <iostream>

int main(int argc, char **argv)
{  
  const int N = 11; 
  int data[N] {0};
  
  for(int ii = 0; ii < N; ++ii) { // <= N is an error
    data[ii] = 2*ii + 1; 
  }
  
  double sum = 0.0;
  for (int ii = 0; ii < N; ++ii) {
    sum += data[ii]; 
  }
  std::cout << "avg: " << sum/N << "\n";
  
  return 0;
}
