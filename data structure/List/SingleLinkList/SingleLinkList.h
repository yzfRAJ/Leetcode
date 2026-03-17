#ifndef _SINGLELINKLIST__H
#define _SINGLELINKLIST__H

#include <iostream>
#include <new>

using namespace std;

typedef int elemtype;

typedef struct LinkNode{
    elemtype data;
    struct LinkNode* next;
}LinkNode;

using Linklist=LinkNode*;

bool Linklist_Init(Linklist &L);//单列表初始化

int  Linklist_Length(Linklist L);//列表长度
Linklist Linklist_LocateElem(Linklist L,elemtype e);//查找元素，返回元素位置指针
bool Linklist_InsertElem(Linklist &L,elemtype e,elemtype i);//插入元素
bool Linklist_delete(Linklist &L,elemtype i,elemtype &e);//输入坐标删除元素
bool Linklist_DeleteElem(Linklist &L,elemtype e);//输入要删除的元素
bool Linklist_GetElem(Linklist L,elemtype i,elemtype &e);//获取元素
void Creat_LinkList_Rear(Linklist &L,elemtype a[],elemtype n);//尾插法建表
void Creat_LinkList_Front(Linklist &L,elemtype a[],elemtype n);//头插法建表


bool Linklist_traversal(Linklist L);//遍历链表
bool Linklist_Destroy(Linklist &L);//销毁列表

#endif
