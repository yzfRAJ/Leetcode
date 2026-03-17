#include "LinkedLIst.h"
typedef int ElemType;
 

int main()
{
    ElemType a[]={1,24,7,9,15,94,34,25,56,2};
    ElemType deletedElement;
    LinkList L;
    InitList(L);
    Creat_LinkList_Rear(L,a,10);
    cout<< "Linked list elements: ";
    TraverseList(L);
    cout<<endl;
    DeleteElem(L, 4, deletedElement);
    cout << "Deleted element: " << deletedElement << endl;
    cout << "Linked list after deletion: ";
    TraverseList(L);
    cout<<endl;
    DestroyList(L);
}