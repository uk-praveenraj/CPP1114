#include <stdio.h>

// complie with this command:    gcc -fPIC -shared -o clib.so .\clib.c

char* display(char *str, int age){
    printf("Hello World by %s aged %d \n", str, age);
    return "Done";
}