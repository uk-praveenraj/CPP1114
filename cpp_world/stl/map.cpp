#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // creating std::map object
    map<int, string> m;

    // adding elements
    m[1] = "ONE";
    m[2] = "TWO";
    m[3] = "THREE";

    // checking size
    cout << "Size of map m: " << m.size() << endl;

    // inserting using insert pair
    m.insert({ 4, "FOUR" });
    m.insert({ 4, "FOUR" });

    // deleting key 2 with its value
    m.erase(2);

    // printing the map
    cout << "Map:-" << endl;
    for (auto i : m) {
        cout << "Key: " << i.first << '\t';
        cout << "Value: " << i.second << endl;
    }

    // creating unordered_map object
    unordered_map<int, string> umap;

    // inserting key value pairs
    umap[1] = "ONE";
    umap[2] = "TWO";
    umap[3] = "THREE";
    umap.insert({ 4, "FOUR" });

    // finding some key
    if (umap.find(12) != umap.end()) {
        cout << "Key 12 Found!" << endl;
    }
    else {
        cout << "Key 12 Not Found!" << endl;
    }

    // traversing whole map at once using iterators
    cout << "umap:--" << endl;
    for (auto i = umap.begin(); i != umap.end(); i++) {
        cout << "Key:" << i->first
             << "\tValue: " << i->second << endl;
    }
    return 0;
}
