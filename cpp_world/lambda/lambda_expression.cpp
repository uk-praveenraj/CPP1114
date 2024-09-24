#include <iostream>
#include <vector>

using namespace std;

template<typename func>
    void filter(func f, vector<int> arr)
    {
        for(auto i:arr )
        {
            if (f(i))
            {
                cout << i << endl;
            }
        }
    }

int main()
{

    cout << [](int x, int y) {return x+y;} (3,4) << endl;
    auto f= [](int x, int y) {return x+y;};
    
    cout << f(7,9);
    vector<int> vecc{0,1,2,3,4,5};
    
    filter([](int x){return x>2;}, vecc);
    filter([](int x){return x<2;}, vecc);
    
    return 0;
}
