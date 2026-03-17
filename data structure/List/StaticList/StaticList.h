#ifndef STATICLIST_H
#define STATICLIST_H

#include <iostream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100
typedef struct {
    ElemType data;
    int cur;
} StaticList[MAXSIZE];


#endif
