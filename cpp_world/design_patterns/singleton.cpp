#include <bits/stdc++.h>

class Singleton{
    private:
    static Singleton* pInstance;
    static std::mutex mut;

    protected:
    Singleton(const std::string value) : mValue(value){}
        
    std::string mValue{};

    public:
    Singleton(Singleton &other) = delete; // shouldn't clone
    void operator=(const Singleton &) = delete; // shouldn't assign
    static Singleton *GetInstance(const std::string& value);
    std::string getValue() const {
        return mValue;
    }
};

Singleton* Singleton::pInstance= nullptr;
std::mutex Singleton::mut;


Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mut);
    if (pInstance == nullptr)
    {
        pInstance = new Singleton(value);
    }
    return pInstance;
}

void Thread1(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FIRST");
    std::cout << singleton->getValue() << "\n";
}

void Thread2(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Singleton* singleton = Singleton::GetInstance("SECOND");
    std::cout << singleton->getValue() << "\n";
}

void Thread3(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("THIRD");
    std::cout << singleton->getValue() << "\n";
}

int main()
{   
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    std::thread t3(Thread3);
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}

