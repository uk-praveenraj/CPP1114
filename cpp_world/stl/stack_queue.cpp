#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;

    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    s.push(6);
    // checking top element
    cout << "s.top() = " << s.top() << endl;

    // getting all the elements
    cout << "s: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    // size after popping all elements
    cout << "Final Size: " << s.size();


    // creating queue
    queue<int> q;

    // pushing elements
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    q.push(6);

    cout << endl << "q.front() = " << q.front() << endl;
    cout << "q.back() = " << q.back() << endl;

    // printing queue by popping all elements
    cout << "q: ";
    int size = q.size();
    for (int i = 0; i < size; i++) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}