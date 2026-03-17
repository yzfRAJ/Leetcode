#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <new>
using namespace std;

typedef int ElemType;

struct LNode//结构体名
{
    ElemType data;
    struct LNode* next;//结构体指针
};

using LinkList=LNode*;//定义LinkList为指向LNode的指针类型

bool InitList(LinkList &L);
int ListLength(LinkList L);
LNode *LocateElem(LinkList L,ElemType e);
bool InsertElme(LinkList L,int i,ElemType e);
bool DeleteElem(LinkList L,int i,ElemType &e);
bool GetElem(LinkList L,int i, ElemType &e);

void Creat_LinkList_Rear(LinkList &L,ElemType a[],int n);
void Creat_LinkList_Front(LinkList &L,ElemType a[],int n);

void TraverseList(LinkList L);
void DestroyList(LinkList &L);

#endif
