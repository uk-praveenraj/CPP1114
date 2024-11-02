#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class ObjectPool {
public:
    ObjectPool(std::size_t size) {
        mObjects.reserve(size);
        for (std::size_t i = 0; i < size; ++i) {
            mObjects.emplace_back(std::make_unique<T>());
        }
    }

    std::unique_ptr<T> acquire() {
        // check if the pool is empty
        if (mObjects.empty()) {
            return nullptr;
        }
        auto obj = std::move(mObjects.back());
        mObjects.pop_back();
        return obj;
    }

    void release(std::unique_ptr<T> obj) {
        mObjects.emplace_back(std::move(obj));
    }

private:
    std::vector<std::unique_ptr<T>> mObjects;
};


class SomeClass {
public:
    SomeClass(){
        std::cout << "Ctor called" << std::endl;
    }
    ~SomeClass(){
        std::cout << "Dtor called" << std::endl;
    }
    void doSomething() {
        std::cout << "I am doing something, without calling the ctor or dtor don't mind." << std::endl;
    }
};

int main() {
    ObjectPool<SomeClass> pool(5); // lets create a pool of size 5

    std::unique_ptr<SomeClass> obj1 = pool.acquire();
    std::unique_ptr<SomeClass> obj2 = pool.acquire();

    if (obj1 && obj2) {
        obj1->doSomething();
        obj2->doSomething();
    }

    // release objects back for future use
    pool.release(std::move(obj1));
    pool.release(std::move(obj2));

    return 0;
}