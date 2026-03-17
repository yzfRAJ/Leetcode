#include <iostream>
#include "seqlist.h"
#include <stdio.h>
using namespace std;

Status InitSeqList(SeqList &L)
{
    L.elem=new ElemType[MAXSIZE];
    if(!L.elem)
    {
        cout<<"Error: Memory allocation failed"<<endl;
        return Error;
    }
    L.length=0;
    return Ok;
}

Status ListEmpty(SeqList &L)
{
    return L.length == 0 ? Ok : Error;
}

Status SeqListInsert(SeqList &L, int i, ElemType e)
{
    // i 是“位序”，从 1 开始，允许在尾部插入：i ∈ [1, length+1]
    if(i < 1 || i > L.length + 1)
    {
        cout<<"Error: Invalid position"<<endl;
        return Error;
    }
    if(L.length>=MAXSIZE)
    {
        cout<<"Error: list is full"<<endl;
        return Error;
    }
    for(int j=L.length;j>=i;j--)
    {
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return Ok;
}

Status SeqListDelete(SeqList &L, int i)
{
    if(i>L.length||i<1)
    {
        cout<<"Error: Invalid position"<<endl;
        return Error;
    }
    if(L.length>=MAXSIZE)
    {
        cout<<"Error: list is full"<<endl;
        return Error;
    }
    for(int j=i;j<L.length;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return Ok;
}

void TraverseSeqList(SeqList L)
{
    if(L.length == 0)
    {
        cout<<"list is empty"<<endl;
    }
    for(int j=0;j<L.length;j++)
    {
        cout<<L.elem[j]<<" ";
    }
    cout<<endl;
}

int ListLength(SeqList &L)
{
    return L.length;
}
//清空数据表
Status ClearList(SeqList &L)
{
    if(ListEmpty(L)==Ok)
    {
        cout<<"list is already empty"<<endl;
    }
    else
    {
        for(int j=0;j<L.length;j++)
        {
            L.elem[j] = 0;// Assuming ElemType can be set to 0, adjust as needed
        }
        L.length = 0;
        cout<<"list cleared"<<endl;
    }
    return Ok; 
}

Status DestroySeqList(SeqList &L)
{
        delete[] L.elem;//对应C++中用NEW创建内存分配，delete[]对应内存释放
        L.elem = nullptr;//空指针
        L.length = 0;
        return Ok;
}

Status GetElem(SeqList &L,int i,ElemType &e)
{
    if(!L.elem)
    {
        cout<<"Error: List is not initialized"<<endl;
        return Error;
    }
    if(i<1 || i>L.length)
    {
        cout<<"Error: Invalid position"<<endl;
        return Error;
    }
    else
    {
        e = L.elem[i-1];
        return Ok;
    }
}

int LocateElem(SeqList &L,ElemType &e)
{
    int subscript=0;
    if(!L.elem)
    {
        cout<<"Error: List is not initialized"<<endl;
    }
    else
    {
        for(int j=0;j<L.length;j++)
        {
            if(L.elem[j] == e)
            {
                subscript = j+1;
                
                break;
            }
        }
    }
    if(subscript == 0)
    {
        cout<<"Error: Element not found"<<endl;
    }
    return subscript;
}
//返回元素前驱
Status PriorElem(SeqList &L, ElemType cur_e, ElemType &pre_e)
{
    if(!L.elem)
    {
        cout<<"Error: List is not initialized"<<endl;
        return Error;
    }
    else
    {
        int j=LocateElem(L,cur_e);
        if(j==0)
        {
            return Error;
        }
        else
        {
            cout<<"not exist pre_e"<<endl;
            pre_e = L.elem[j-2];
            return Ok;
        }
    }
}

Status NextElem(SeqList &L, ElemType cur_e, ElemType &next_e)
{
    if(!L.elem)
    {
        cout<<"Error: List is not initialized"<<endl;
        return Error;
    }
    else
    {
        int j=LocateElem(L,cur_e);
        if(j==0)
        {
            cout<<"not exist next_e"<<endl;
            return Error;
        }
        else
        {
            next_e = L.elem[j];
            return Ok;
        }
    }
}
