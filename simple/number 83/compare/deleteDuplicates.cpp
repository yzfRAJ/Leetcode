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
//从前往后单个比较即可，并释放节点
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *p=head;
        while(p!=nullptr&&p->next!=nullptr){
            if(p->val==p->next->val)
            {
                ListNode* q=p->next;
                p->next=q->next;
                delete q;
            }else{
                p=p->next;
            }
        }
        return head;
    }
};