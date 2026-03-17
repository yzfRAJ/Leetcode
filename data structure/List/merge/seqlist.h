/*
seqlist.h 顺序表
*/
#ifndef SEQLIST_H
#define SEQLIST_H

#define MAXSIZE 100 //最大元素个数

typedef int ElemType;  //定义元素类型

enum Status{Ok,Error};  //状态，枚举类型

struct SeqList
{
	ElemType *elem;   //指针，存储空间动态申请
	int length;       //当前线性表的长度
};


Status InitSeqList(SeqList &L); //顺序表的初始化
Status SeqListInsert(SeqList &L, int i, ElemType e); //插入操作
Status SeqListDelete(SeqList &L, int i); //删除元素
void TraverseSeqList(SeqList L); //遍历顺序表
int ListLength(SeqList &L);    //线性表长度
Status ListEmpty(SeqList &L);   //线性表是否为空
Status ClearList(SeqList &L);  //将L重置为空表
Status DestroySeqList(SeqList &L); //销毁线性表
Status GetElem(SeqList &L,int i,ElemType &e); //用e返回L中第i个数据元素的值
int LocateElem(SeqList &L,ElemType &e);   //查询数据的位置 
Status PriorElem(SeqList &L, ElemType cur_e, ElemType &pre_e); //当前元素cur_e不是第一个数据，就pre_e返回它的前一个数据的值，否则返回error 
Status NextElem(SeqList &L, ElemType cur_e, ElemType &next_e); //当前元素不会最后一个，就用next_e返回它的后一个数值，否则返回error
void choose();//声明主菜单
void End();//退出菜单操作

#endif
