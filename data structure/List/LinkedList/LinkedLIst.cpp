#include "LinkedLIst.h"


// 让初始化函数负责申请头结点
bool InitList(LinkList &L)
{
    L = new LNode();//申请头结点，分配成功：返回一个有效地址，L 不会是 nullptr
    L->next = nullptr;
    return true;
}

//求表长
int ListLength(LinkList L)
{
    LinkList p;
    int k=0;
    p=L->next;
    while(p !=nullptr)
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
    while(p != nullptr && p->data != e)
    {
        p=p->next;
    }
    return p;
}

//插入元素,其中头结点不存数据
bool InsertElme(LinkList L,int i,ElemType e)
{
    if (L == nullptr) return false;
    if (i < 1) return false;

    // 带头结点：找到第 i-1 个结点 p（从头结点算起），在其后插入新结点
    LinkList p = L;
    int j = 0;
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == nullptr) return false;
    LinkList s = new (nothrow) LNode;//开辟存储空间
    if (s == nullptr) return false;
    s->data = e;
    s->next = p->next;
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
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        ++j;
    }

    if (p == nullptr || p->next == nullptr) return false;

    LinkList q = p->next;   // 第 i 个结点
    e = q->data;
    p->next = q->next;
    delete q;//删除q
    return true;
}
//取元素
bool GetElem(LinkList L,int i, ElemType &e)
{
    if(i<1)return false;
    if(L==nullptr)return false;
    LinkList p;
    p = L->next;
    int j=0;
    while(p != nullptr && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    e=p->data;
    return true;
}
//尾插法建表
void Creat_LinkList_Rear(LinkList &L,ElemType a[],int n)
{
    LinkList p,q;
    p=L;
    for(int j=0;j<n;j++)
    {
        q=new(nothrow) LNode;
        q->data=a[j];
        p->next=q;
        p=q;
    }
    q->next=NULL;//表尾结点置空域
}

//头插法建表
void Creat_LinkList_Front(LinkList &L,ElemType a[],int n)
{
    LinkList p;
    L->next = nullptr;
    for(int j=n-1;j>=0;j--)
    {
        p=new(nothrow) LNode;
        p->data=a[j];
        p->next=L->next;
        L->next=p;
    }
}

//单链表遍历
void TraverseList(LinkList L)
{
    LinkList p = L->next;
    while (p!=nullptr)
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
    while (p != nullptr)
    {
        LinkList q = p->next;
        delete p;
        p = q;
    }

    delete L;      // 释放头结点
    L = nullptr;   // 头指针置空
}
