// C++ Program to check
// if number is Armstrong
// or not
#include <iostream>
#include <vector>
using namespace std;

bool ArmStrong(int n)
{
  int val = n;
  int sum = 0;

  while (val > 0){
    int rem = val % 10;
    sum += rem * rem * rem;
    val = val /10;
  }
  // condition to check
  if (n == sum) {
      cout << ("Yes, it is Armstrong Number");
      return true;
  }
  else {
      cout << ("No, it is not an Armstrong Number");
      return false;
  }
}

// Returns true if the string is pangram else false
bool checkPangram(string& str)
{
    // Create a hash table to mark the characters
    // present in the string
    std::vector<bool> mark(26, false);
    // For indexing in mark[]
    int index;
    // Traverse all characters
    for (int i = 0; i < str.length(); i++) {
        // If uppercase character, subtract 'A'
        // to find index.
        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';
        // If lowercase character, subtract 'a'
        // to find index.
        else if ('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
        // If this character is other than english
        // lowercase and uppercase characters.
        else
            continue;
        mark[index] = true;
    }
 
    // Return false if any character is unmarked
    for (int i = 0; i <= 25; i++)
        if (mark[i] == false)
            return (false);
    // If all characters were present
    return (true);
}

void myAsciiToInt(string str)
{
	int res = 0;
  for(int i=0; i < str.length(); ++i){
    res = res * 10 + str[i] - '0';
  }
  cout << "result is " << res;
}

int main()
{
  int n = 154;
  //ArmStrong(n);
  // string str = "abcde";
  // int index = str[4] - 'a'; // Panagram 
  // cout << "index is " << index;

  myAsciiToInt("89789");
  int val = '8' - '0'; // 8
  cout << "val is " << val;
  return 0;
}