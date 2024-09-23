#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// complie with this command:    gcc -fPIC -shared -o cstruct.so .\cstruct.c

struct Point
{
    int x;
    int y;
};

void printPoint(struct Point p){
    printf("x: %d y: %d \n", p.x, p.y);
}

struct Point* getPoint(){
    struct Point *p;
    p->x=10;
    p->y=20;
    return p;
}

struct Student
{
    char* name;
};

void printStu(struct Student s){
    printf("Name is %s", s.name);
}

struct Student* getStu(){
    struct Student *s = malloc(sizeof(struct Student));
    s->name = strdup("UK");
    return s;
} 

void freeMem(struct Student* s){
    free(s);
    printf("Freed the memeory");
}

struct PointArrary{
    struct Point points[3];
};

void printPA(struct PointArrary pa){
    for (int i = 0; i < 3; ++i){
        printf("%d %d\n", pa.points[i].x, pa.points[i].y);
    }
}