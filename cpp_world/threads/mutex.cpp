// C++ program to illustrate the use of mutex locks to 
// synchronize the threads 
#include <iostream> 
#include <mutex> 
#include <thread> 
using namespace std; 

// shared lock 
double val = 0; 

// mutex lock 
mutex m; 

int cnt = 0; 

void add(double num) 
{ 
	m.lock(); 
	val += num; 
	cnt++; 
	cout << "Thread " << cnt << ": " << val << endl; 
	m.unlock(); 
} 

// driver code 
int main() 
{ 
	thread t1(add, 300); 
	thread t2(add, 600); 
	t1.join(); 
	t2.join(); 
	cout << "After addition : " << val << endl; 
	return 0; 
}
