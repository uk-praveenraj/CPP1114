#include <iostream>
using namespace std;
    
template<typename T>
T SumPlease(T v) {
  return v;
}

template<typename T, typename... Args>
T SumPlease(T first, Args... args) {
  return first + SumPlease(args...);
}
int main()
{
	std::string str1 = "Mary", str2 = "Had", str3 = "A", str4 = "Little", str5 = "Lamb";
	std::string res = SumPlease(str1, str2, str3, str4, str5);
	cout << res;

  return 0;
}
