// C++ Program to implement
// Bubble sort
// using template function
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
  vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};

  auto add = [] (int a, int b) {
    cout << "Sum is :" << a + b << endl;
    return a+b;
  };

  add(100, 78);

  auto printv = [] (const int &n) {cout << "vec " << n << endl;};
  std::for_each(v.cbegin(), v.cend(), printv);

  std::for_each(v.cbegin(), v.cend(), [] (const int &n) {cout <<"vec " << n << endl;});

  cout << "lambda returned " << add(10,30);
}
