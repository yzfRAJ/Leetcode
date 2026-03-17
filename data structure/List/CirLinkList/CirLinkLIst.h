#ifndef CIRLINKEDLIST_H
#define CIRLINKEDLIST_H

#include <iostream>
#include <new>
using namespace std;

typedef int ElemType;

typedef struct Node//结构体名
{
    ElemType data;
    struct Node* next;//结构体指针
    struct Node* prior;//结构体指针
    
} LNode,*LinkList;//结构体变量，指针变量

bool InitList(LinkList &L);
int ListLength(LinkList L);
LNode *LocateElem(LinkList L,ElemType e);
bool InsertElem(LinkList L,int i,ElemType e);
bool DeleteElem(LinkList L,int i,ElemType &e);
bool GetElem(LinkList L,int i, ElemType &e);
void Creat_LinkList_Rear(LinkList &L,ElemType a[],int n);
void Creat_LinkList_Front(LinkList &L,ElemType a[],int n);
void TraverseList(LinkList L);
void DestroyList(LinkList &L);

#endif
