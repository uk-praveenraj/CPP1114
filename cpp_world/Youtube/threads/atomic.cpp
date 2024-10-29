// compile using: g++ -std=c++17 .\atomic.cpp -o program -lpthread
#include <iostream> 
#include <mutex> 
#include <thread> 
#include <vector> 
#include <atomic> 
using namespace std; 

// shared value
int count =0;
std::atomic_int acount;

// mutex lock 
mutex mtx; 

void increment() 
{ 
    //std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
	count += 1; // critical section
    //acount += 1;
    acount = acount + 1;
    //lock.unlock();
} 

int main() 
{ 
    vector<std::thread> myThreads;
    for(int i=0; i<5000; ++i){
        myThreads.push_back(std::thread(increment));
    }

    for(int i=0; i<5000; ++i){
        myThreads[i].join();
    }

	cout << "Count is : " << count << endl; 
    cout << "ACount is : " << acount << endl; 
	return 0; 
}
