#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


template <typename T>  T Sum(T x, T y){
  return x+y;
}

int main()
{
  std::cout << "Sum int is :" << Sum<int> (3,5);
  std::cout << "Sum char is :" << Sum<string> ('a','d');
  std::cout << "Sum float is :" << Sum<float> (2.33,5.66);
}