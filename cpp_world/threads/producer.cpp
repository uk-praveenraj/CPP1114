#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable condvar;

// void producer() {
//    for (int i = 1; i <= 5; ++i) {
//       std::lock_guard<std::mutex> lock(mtx);
//       buffer.push(i);
//       std::cout << "Produced: " << i << std::endl;
//       cv.notify_one();
//       std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
// }

// void consumer() {
//    while (true) {
//       std::unique_lock<std::mutex> lock(mtx);
//       cv.wait(lock, [] { return !buffer.empty(); });
//       int data = buffer.front();
//       buffer.pop();
//       std::cout << "Consumed: " << data << std::endl;
//       lock.unlock();
//       std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    }
// }

// int main() {
//    std::thread producerThread(producer);
//    //std::thread producerThread1(producer);
//    std::thread consumerThread(consumer);
    
//    producerThread.join();
//    //producerThread1.join();
//    consumerThread.join();

//    return 0;
// }

void producer(){
   for(int i=0; i< 15; ++i){
      std::lock_guard<std::mutex> mutexLock(mtx);
      buffer.push(i);
      std::cout << "Produced: " << i << std::endl;
      condvar.notify_one();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }
}

auto isBufferEmpty = [](){ return !buffer.empty(); };

void consumer(){
   while(true){
      std::unique_lock<std::mutex> mutexLock(mtx);
      condvar.wait(mutexLock, isBufferEmpty); // wait till buffer is not empty
      //condvar.wait(mutexLock, [] { return !buffer.empty(); });
      int data = buffer.front();
      buffer.pop();
      std::cout << "Consumed: " << data << std::endl;
      mutexLock.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
   }
}

int foo()
{
   static int i =1;
   i++;
   return i;
}

int main() {
   // std::thread producerThread(producer);
   // //std::thread producerThread1(producer);
   // std::thread consumerThread(consumer);
    
   // producerThread.join();
   // //producerThread1.join();
   // consumerThread.join();

// std::vector<int> v(2);
// v.push_back(1);
// v.push_back(1);
// v.push_back(1);
// std::cout << "Consumed: " << v.size() << std::endl;

// char const *p ="hello";
// p = "world";
// std::cout << "rrrr" << p << "rrrr" ;

int value;
value = foo();
value = foo();
std::cout << "rrrr" << value << "rrrr" ;
   return 0;
}