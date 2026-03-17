/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=new ListNode();
        ListNode* p=list3;
        while(list1&&list2){
            if(list1->val<=list2->val){
                p->next=list1;//直接将地址赋值,不用开辟空间，省内存，
                list1=list1->next;
            }else{
                p->next=list2;
                list2=list2->next;
            }
            p=p->next;  
        }
        p->next=list1?list1:list2;
        return list3->next;//必须返回list3->next,因为list3是哑节点，初始化为0，若输出list3，开头是0，真正的链表从list3->next开始。
    }    
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=new ListNode();// 哑节点
        ListNode* p3;//拷贝副本不在原来的lsit上修改
        p3=list3; // 尾指针，用于构建新链表
        while(list1!=nullptr||list2!=nullptr){
            if(list1!=nullptr&&list2!=nullptr){
                if(list2->val<=list1->val){
                    p3->next = new ListNode(list2->val);//开辟空间，存储list2的值，从头节点后一个开始，list3的头节点是哑节点，值为0，不存储数据
                    list2=list2->next;
                    p3=p3->next;
                }
                else{
                    p3->next = new ListNode(list1->val);
                    p3=p3->next;
                    list1=list1->next;
                }
            }else if(list1!=nullptr){
                p3->next = new ListNode(list1->val);
                p3=p3->next;
                list1=list1->next;
            }else {
                p3->next = new ListNode(list2->val);
                list2=list2->next;
                p3=p3->next;
            }
        }
        return list3->next;
    }
};