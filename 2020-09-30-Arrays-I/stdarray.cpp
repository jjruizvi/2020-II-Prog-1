#include <iostream>
#include <array>
#include <vector>

int main(int argc, char **argv)
{  
  const int N = 2150000; 
  //int data[N] {0};
  std::array<int, N> data {0};
  //std::vector<int> data(0);
  //data.resize(N);
  
  //std::cout << data.size() << "\n";
  //std::cout << data.max_size() << "\n";
  
  //for(int ii = 0; ii < N; ++ii) { // <= N is an error
  //data[ii] = 2*ii + 1; 
  //}
  
  int ii = 0;
  for (auto & val : data) {
      val = 2*ii + 1;
      ii++;
  }
  
  double sum = 0.0;
  for (auto val : data) {
    sum += val; 
  }
  std::cout << "avg: " << sum/N << "\n";
  
  return 0;
}
