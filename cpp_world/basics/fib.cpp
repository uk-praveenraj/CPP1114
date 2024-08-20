// C++ program to illustrate the use of mutex locks to 
// synchronize the threads 
#include <iostream> 
#include <mutex> 
#include <thread> 
using namespace std; 

int fib(int n) 
{ 
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
} 
  
int main() 
{ 
    int n = 19;
    cout << fib(n);
    getchar();
    return 0; 
} 