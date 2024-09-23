#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
    Test()
    {
        cout << "Creating test" << endl;
    }
    ~Test()
    {
        cout << "Deleting test"<< endl;
    }

};

int main(){
    unique_ptr<int> uptr1 = make_unique<int>(15);
    unique_ptr<int> uptr2 = move(uptr1);
    cout << *uptr2;

    unique_ptr<Test> uptr1 = make_unique<Test>();

    shared_ptr<Test> shptr1 = make_shared<Test>();
    cout << "I am shared with " << shptr1.use_count() << endl;
    {
        shared_ptr<Test> shptr2 = shptr1;
        cout << "I am shared with " << shptr1.use_count() << endl;
    }
    cout << "I am shared with " << shptr1.use_count() << endl;


    weak_ptr<int> wPtr1;
    {
        shared_ptr<int> shptr3 = make_shared<int>(25);
        wPtr1 = shptr3;
    }
    // now there is not strong reference to 25
    return 0;
    //system("pause>nul");
}