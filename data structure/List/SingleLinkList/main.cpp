#include "SingleLinkList.h"



int main(){

    LinkNode* LN;
    LinkNode* LN1;
    LinkNode* LN2;
    Linklist_Init(LN);
    Linklist_Init(LN1);
    Linklist_Init(LN2);
    for(int i=0;i<10;i++){
        Linklist_InsertElem(LN,i,i+1);
    }
    int a[]={10,10,10,10,10,10,10,10,10,11};
    Linklist_InsertElem(LN,19,1);
    Linklist_LocateElem(LN,5);
    cout<<"列表长度为："<<Linklist_Length(LN)<<endl;
    int e;
    Linklist_delete(LN,5,e);//按位置删除元素
    cout<<"被删除的元素为："<<e<<endl;
    cout<<"列表长度为："<<Linklist_Length(LN)<<endl;

    // Linklist_DeleteElem(LN,9);//按元素删除元素
    cout<<"列表长度为："<<Linklist_Length(LN)<<endl;
    Linklist_traversal(LN);
    Linklist_GetElem(LN,5,e);
    cout<<"获取的元素为："<<e<<endl;
    Creat_LinkList_Rear(LN1,a,10);
    Linklist_DeleteElem(LN1,10);//按元素删除元素
    Creat_LinkList_Front(LN2,a,10);
    Linklist_traversal(LN1);
    Linklist_traversal(LN2);
    
    return 0;
}