#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = { 1, 2, 3, 4, 5, 6};
    // 2d vector with size and element value initialization
    vector<vector<int> > v2(3, vector<int>(3, 5));

    // adding values using push_back()
    v1.push_back(7);
    v1.insert(v1.begin() + 4, 15);
    // printing v1 using size()
    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    v1.erase(v1.begin() + 4);
    // printing v1 using iterators
    cout << "v1: ";
    for (auto i = v1.begin(); i != v1.end(); i++) {
        cout << *i << " ";
    }

    // printing v2 using range based for loop
    cout << "\nv2:-" << endl;
    for (auto i : v2) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}