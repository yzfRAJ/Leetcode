#include "CirLinkLIst.h"


// 让初始化函数负责申请头结点
bool InitList(LinkList &L)
{
    L = new (nothrow) LNode;
    if (L == nullptr) return false;
    L->next = L;
    L->prior = L;
    return true;
}

//求表长
int ListLength(LinkList L)
{
    LinkList p;
    int k=0;
    p=L->next;
    while(p !=L)
    {
        k++;
        p=p->next;
    }
    return k;
}

//查找元素操作,查找成功，则返回该结点的指针，否则返回空指针
LNode *LocateElem(LinkList L,ElemType e)
{
    LinkList p;
    p=L->next;
    while(p != L && p->data != e)
    {
        p=p->next;
    }
    return p;
}

//插入元素,其中头结点不存数据
bool InsertElem(LinkList L,int i,ElemType e)
{
    if (L == nullptr) return false;
    if (i < 1) return false;

    // 带头结点：找到第 i-1 个结点 p（从头结点算起），在其后插入新结点
    LinkList p = L;
    int j = 0;
    while (p != L && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == L) return false;

    LinkList s = new (nothrow) LNode;
    if (s == nullptr) return false;
    s->data = e;

    s->next = p->next;
    s->prior = p;
    if (p->next != L)
    {
        p->next->prior = s;
    }
    p->next = s;
    return true;
}

//删除元素
bool DeleteElem(LinkList L,int i,ElemType &e)
{
    if (L == nullptr) return false;
    if (i < 1) return false;

    // 带头结点：找到第 i-1 个结点 p（从头结点算起），删除其后的第 i 个结点
    LinkList p = L;
    int j = 0;
    while (p != L && j < i - 1)
    {
        p = p->next;
        ++j;
    }

    if (p == L || p->next == L ) return false;

    LinkList q = p->next;   // 第 i 个结点
    e = q->data;
    p->next = q->next;
    q->next->prior = p;
    delete q;
    return true;
}
//取元素
bool GetElem(LinkList L,int i, ElemType &e)
{
    if (L == nullptr) return false;
    if (i < 1) return false;

    LinkList p = L->next;
    int j = 1;
    while (p != L && j < i)
    {
        p = p->next;
        ++j;
    }
    if (p == L) return false;
    e = p->data;
    return true;
}
//尾插法建表
void Creat_LinkList_Rear(LinkList &L,ElemType a[],int n)
{
    LinkList p,q;
    q=L;
    for(int j=0;j<n;j++)
    {
        p=new(nothrow) LNode;
        if (p == nullptr) return;
        p->data=a[j];
        p->next=L;
        p->prior=q;
        q->next=p;
        q=p;
    }
    q->next=L;//表尾结点置空域
}

//头插法建表
void Creat_LinkList_Front(LinkList &L,ElemType a[],int n)
{
    LinkList p;
    L->next = L;
    for(int j=n-1;j>=0;j--)
    {
        p=new(nothrow) LNode;
        if (p == nullptr) return;
        p->data=a[j];
        p->next=L->next;
        p->prior=L;
        if (L->next != L)
        {
            L->next->prior = p;
        }
        L->next=p;
    }
}

//单链表遍历
void TraverseList(LinkList L)
{
    LinkList p = L->next;
    while (p!=L)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout << endl;
}

//单链表撤销
void DestroyList(LinkList &L)
{
    if (L == nullptr) return;

    LinkList p = L->next;
    while (p != L)
    {
        LinkList q = p->next;
        delete p;
        p = q;
    }

    delete L;      // 释放头结点
    L = nullptr;   // 头指针置空
}
