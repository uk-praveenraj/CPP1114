#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    // creating std::list object using initializer list
    list<int> l1 = { 1, 5, 9, 1, 4, 6 };

    // vector for initialization
    vector<char> v = { 't', 'h', 'e', 'l', 'i', 's', 't' };
    list<int> l2(v.begin(), v.end());

    // printing first element
    cout << "First element of l1: " << l1.front() << endl;

    // adding element
    l1.insert(l1.begin(), 5);

    // deleting element
    l1.erase(l1.begin());

    // traversing and printing l1
    cout << endl << "l1: ";
    for (auto i = l1.begin(); i != l1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // traversing and printing l2
    cout << "l2: ";
    for (auto i : l2) {
        cout << char(i);
    }
    cout << endl;

    return 0;
}