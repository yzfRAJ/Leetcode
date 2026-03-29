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
//先判断第一个后面的节点是否需要删除，回头判断头节点是否需要删除
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p=head;
        ListNode* q=head;
        while(p!=nullptr){
            if(p->val==val){
                q->next=p->next;
                p=p->next;
            }else{
                q=p;
                p=p->next;
            }
        }
        if(head!=nullptr&&head->val==val){//第一个节点无法删除，最后判断即可
            head=head->next;
        }
        return head;
    }
};  