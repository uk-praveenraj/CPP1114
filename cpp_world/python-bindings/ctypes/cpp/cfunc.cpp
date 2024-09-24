#include <iostream>
#include <pybind11/pybind11.h>
using namespace std;
namespace py=pybind11;

// complie with this command:    g++ -fPIC -shared -o func.so .\func.cpp

// //ctypes way
// extern "C" {
//     void func(){
//         cout << "Func with no args" << endl;
//     }

//     // void func(int a){
//     //     cout << "Func with one int arg " << a << endl;
//     // }

//     // void func(string a){
//     //     cout << "Func with one string arg " << a << endl;
//     // }
// }

