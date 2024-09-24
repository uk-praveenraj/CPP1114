#include <C:\Users\ukpra\AppData\Local\Programs\Python\Python312\include\python.h>

// compile with
//g++ .\main.cpp -o output -L C:\Users\ukpra\AppData\Local\Programs\Python\Python312\libs -lpython312 - I C:\Users\ukpra\AppData\Local\Programs\Python\Python312\include

int main(int argc, char **argv){
    Py_Initialize();
    PyRun_SimpleString("print('Hello c++ from python')");
    Py_Finalize();

    return 0;
}