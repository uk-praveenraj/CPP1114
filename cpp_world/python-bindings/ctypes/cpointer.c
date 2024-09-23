#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// complie with this command:    gcc -fPIC -shared -o cpointer.so .\cpointer.c

char* alloc_mem(){
    char* str = strdup("Hello world\n");
    printf("Memory allocated...\n");
    return str;
}

void free_mem(char* ptr){
    free(ptr);    
    printf("Memory de-allocated...\n");
}