#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// complie with this command:    gcc -fPIC -shared -o carray.so .\carray.c

int sumArray(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; ++i ){
        sum += arr[i];
    }
    return sum;
}

int* incArray(int *arr, int size){
    for(int i = 0; i < size; ++i ){
        arr[i]++;
    }
    return arr;
}

int* getArray(){
    int *arr = malloc(10 * sizeof(int));
    for(int i = 0; i < 10; ++i ){
        arr[i] = i;
    }
    return arr;
}

void freeMem(int *arr){
    free(arr);
    printf("freeeeed");
}
