#include <iostream>
using namespace std;

int main(){
    int rows = 3, cols=3;

    int **table = new int*[rows];
    for(int i=0; i<rows;++i){
        table[i] = new int[cols];
    }
    int k=0;
    for(int i=0; i<rows;++i){
        for(int j=0; j<cols;++j){
            table[i][j] = k++;
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    //cleanup
    for(int i=0; i<rows;++i){
        delete[] table[i];
    }
    delete[] table;

    return 0;
}