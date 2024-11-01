#include <iostream>
#include <future>
#include <chrono>
#include <thread>
using namespace std;

void myThread(std::promise<int> promise_val){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    promise_val.set_value(50);

    // do whatever...
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "Exiting thread" << endl;
    
    return; 
}

int main(){
    std::promise<int> promise_val;
    std::future<int> future_val = promise_val.get_future();

    cout << "Starting thread" << endl;
    std::thread t(myThread, std::move(promise_val));

    cout << "Waiting for value from thread" << endl;
    cout << "Value is " << future_val.get() << endl; 

    t.join();

    return 0;
}