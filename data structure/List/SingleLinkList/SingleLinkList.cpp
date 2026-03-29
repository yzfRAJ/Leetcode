#include "SingleLinkList.h"

bool Linklist_Init(Linklist &L)//单列表初始化
{
    L=new LinkNode();//申请头结点，分配成功：返回一个有效地址，L 不会是 nullptr
    L->next=nullptr;
    return true;
}


int  Linklist_Length(Linklist L)//列表长度
{
    int Length=0;
    if(!L || !L->next){
        cout<<"列表为空"<<endl;
        return Length;
    }
    Linklist p=L->next;
    while(p){
        Length++;
        p=p->next;
    }

    return Length;
}


Linklist Linklist_LocateElem(Linklist L,elemtype e)  //查找元素，返回元素位置指针
{
    Linklist p;
    p=L->next;
    while(p){
        if(p->data==e) break;
        p=p->next;
    }
    if(!p) cout<<"列表中没有该元素"<<endl;
    return p;
}

bool Linklist_InsertElem(Linklist &L,elemtype e,elemtype n)//插入元素
{
    Linklist p,q;
    int i=0;
    p=L;//头节点
    if(n<1){
        cout<<"插入位置不正确"<<endl; return false;
    }
    if(!L) {
        cout<<"列表为空"<<endl; return false;
    }
    while(p&&i<n-1){
        p=p->next;
        i++;
    }
    if(!p) return false;
    q=new LinkNode();
    q->data=e;
    q->next=p->next;
    p->next=q;//将q本身地址存进p->next里
    return true;
}

bool Linklist_delete(Linklist &L,elemtype i,elemtype &e)//删除元素
{
    Linklist p,q;
    p=L;
    int j=0;
    if(i<1){
        cout<<"删除位置不正确"<<endl; return false;
    }
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    if(!p||!p->next) return false;
    q=p->next;
    e=q->data;
    p->next=q->next;
    delete q;
    return true;
}

bool Linklist_DeleteElem(Linklist &L,elemtype e)//输入要删除的元素
{
    Linklist p=L,q=L;
    while(p){
        if(p->data==e){
            q->next=p->next;
            delete p;
            Linklist p=q->next;
        }
        q=p;
        p=p->next;
    }
    if(!p){
        cout<<"列表没有该元素"<<endl;
        return false;
    }
    return true;
}

bool Linklist_GetElem(Linklist L,elemtype i,elemtype &e)//获取元素
{   
    Linklist p;
    p=L->next;
    if(i<1){
        cout<<"输入位置不正确"<<endl;
        return 0;
    }
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    if(!p) return false;
    e=p->data;
    return true;
}

void Creat_LinkList_Rear(Linklist &L,elemtype a[],elemtype n)//尾插法建表，每次把新结点接到当前尾结点后面
{
    Linklist p=L,q;
    for(int i=0;i<n;i++)
    {
        q=new LinkNode();
        q->data=a[i];
        p->next=q;
        p=p->next;
    }
    p->next=nullptr;
}

void Creat_LinkList_Front(Linklist &L,elemtype a[],elemtype n)//头插法建表，每次把新结点插到头结点后面
{
    Linklist p=L,q;
    for(int i=n-1;i>=0;i--)
    {
        q=new LinkNode();
        q->data=a[i];
        q->next=p->next;
        p->next=q;
    }
}

bool Linklist_traversal(Linklist L){
    Linklist p=L->next;
    cout<<"列表的元素为：";
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return true;
}

bool Linklist_Destroy(Linklist &L)
{
    if(!L) return false;
    Linklist p=L->next;
    while(p){
        Linklist q = p->next;
        delete p;
        p = q;
    }
    delete L;
    L = nullptr;
    return true;
}