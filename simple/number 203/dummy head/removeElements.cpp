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
//创建一个哑节点当头节点，并delete 释放节点，这样不需要单独判断头节点是否需要删除
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* L=new ListNode();
        L->next=head;//创建一个哑节点
        ListNode* p=L;
        while(p!=nullptr&&p->next!=nullptr){
            if(p->next->val==val){
                ListNode* q=p->next;
                p->next=p->next->next;
                delete q;
            }else p=p->next;
        }
        return L->next;
    }
};  