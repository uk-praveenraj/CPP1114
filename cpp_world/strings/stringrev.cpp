#include <iostream> 
#include <mutex> 
#include <thread> 
#include <string> // for string and to_string()
#include <algorithm>
using namespace std; 

string revString(string input)
{
  int len = input.length();int i=0;
  for(int i=0; i < len/2; ++i){
    swap(input[i], input[len-i-1]);
  }
  return input;
}

string bigSum(string str1, string str2)
{
  // always consider str1 is bigger
  if (str1.length() < str2.length())
  {
    swap(str1,str2);
  }
  int str1Len = str1.length();
  int str2Len = str2.length();
  int pad = str1Len - str2Len;
  // pad zeros
  str2.insert(0, pad, '0');

  string tmpStr, result;
  int num1, num2, sum, remainder =0;
  // now do the calculation
  for (int i=str1Len-1; i >=0; --i){
    char tmp = str1[i];
    num1 = atoi(&tmp);
    tmp = str2[i];
    num2 = atoi(&tmp);

    sum = num1 + num2 + remainder;
    cout << "Sum first when i is " << i << " is " << sum << endl;
    remainder = 0;
    if(sum > 9)
    {
      remainder = 1;
      sum -= 10;
    }
    cout << "Sum when i is " << i << " is " << sum << endl;
    result += std::to_string(sum);
  }
  if(remainder != 0)
  {
    result += std::to_string(1);
  }

  std::reverse(result.begin(), result.end());
  cout << "result string is " <<result;
  return "something";

}

int main()
{
  // string str = "this is a car";
  // cout << revString(str);

  bigSum("923", "129");
}