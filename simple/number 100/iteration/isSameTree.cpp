/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        if(p!=nullptr) s.push(p);
        if(q!=nullptr) s.push(q);
        while(!s.empty()){
            auto cur=s.top();
            s.pop();
            if(s.empty()) return false;
            else {
                auto cer1=s.top();
                s.pop();
                if(cur->val!=cer1->val){
                    return false;
                }        
                if(cur->right!=nullptr&&cer1->right!=nullptr)
                {   s.push(cur->right);
                    s.push(cer1->right);
                }else if(!(cur->right==nullptr&&cer1->right==nullptr)) return false;
                if(cur->left!=nullptr&&cer1->left!=nullptr){
                    s.push(cur->left);
                    s.push(cer1->left); 
                }else if(!(cur->left==nullptr&&cer1->left==nullptr)) return false;
            }
        }
        return true;
    }
};