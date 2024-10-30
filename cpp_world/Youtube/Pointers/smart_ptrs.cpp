// compile using: g++ -std=c++17 .\smart_ptrs.cpp -o program -lpthread
#include <iostream> 
#include <memory> 
using namespace std; 

int main(){
    // Unique pointers
    unique_ptr<int> uPtr1 = std::make_unique<int>(25);
    //unique_ptr<int> uPtr2 = uPtr1;
    unique_ptr<int> uPtr2 = std::move(uPtr1);

    cout << *uPtr2 << endl;
    //cout << *uPtr1 << endl;

    // Shared pointers
    shared_ptr<int> sPtr1 = make_shared<int>(25); 
    cout << "Shared pointer count is : " << sPtr1.use_count() << endl; 
    {
        shared_ptr<int> sPtr2 = sPtr1; 
        cout << "Shared pointer count is : " << sPtr2.use_count() << endl;
    }
    cout << "Shared pointer count is : " << sPtr1.use_count() << endl;

    // // Weak pointers
    weak_ptr<int> wPtr1;
    //{
        shared_ptr<int> swPtr1 = make_shared<int>(25); 
        wPtr1 = swPtr1;
    //}
    if(wPtr1.expired()){
        cout << "I am dead" << endl;
    } else{
        cout << "I am alive" << endl;
    }        

    return 0;
}