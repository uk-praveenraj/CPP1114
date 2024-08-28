#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    // creating vector
    vector<int> v = { 1, 5, 3, 4, 2 };
    // creating set using vector v
    set<int> s(v.begin(), v.end());

    // finding 4
    if (s.find(4) == s.end()) {
        cout << "5 not found" << endl;
    }
    else {
        cout << "5 found" << endl;
    }

    std::pair<std::set<int>::iterator,bool> ret;
    // adding 9
    ret = s.insert(9);
    if (ret.second) { cout << "24 - Able to insert" << endl;}
    ret = s.insert(9);
    if (ret.second == false) { cout << "26 - Not able to insert" << endl;}
    ret = s.insert(16);
    if (ret.second) { cout << "28 - Able to insert" << endl;}

    // printing set
    cout << "s: ";
    for (set<int>::iterator i = s.begin(); i != s.end();
         i++) {
        cout << *i << " ";
    }
    cout << endl;


    // creating an unordered_set object
    unordered_set<int> us = { 1, 5, 2, 3, 4 };

    // checking size
    cout << "Size of us: " << us.size() << endl;

    // inserting data
    us.insert(7);

    // finding some key
    if (us.find(3) != us.end()) {
        cout << "3 found!" << endl;
    }
    else {
        cout << "3 not found" << endl;
    }

    // traversing unordered_set using iterators
    cout << "us: ";
    for (auto i = us.begin(); i != us.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}
