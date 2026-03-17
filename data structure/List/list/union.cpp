#include <iostream>
#include "seqlist.h"

using namespace std; 

int main()
{
    SeqList mylist,mylist1;
    ElemType x;
    int a[]={6,8,16,2,34,56,7,10,22,45};
    int b[]={6,11,12,16,38,54,22,56,45,32};
    InitSeqList(mylist);
    InitSeqList(mylist1);
    for(int i=0; i<10; i++)
    {
        SeqListInsert(mylist, i+1, a[i]);
        SeqListInsert(mylist1, i+1, b[i]);
    }
    int Length=ListLength(mylist1);
    int Length1=ListLength(mylist);
    while(ListEmpty(mylist1)==Error)
    {   
        int j=0;
        for(int i=1;i<=Length;i++)
        {
            GetElem(mylist1, i, x);
            if(LocateElem(mylist, x) <= 0)
            {   
                j++;
                SeqListInsert(mylist,Length1+j, x);
            }
        }
        DestroySeqList(mylist1);
    }
    TraverseSeqList(mylist);
    return 0;
}