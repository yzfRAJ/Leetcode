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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> L,R;
        if(root->left!=nullptr){
            L.push(root->left);
        }
        if(root->right!=nullptr){
            R.push(root->right);
        }
        while(!L.empty()&&!R.empty()){
            auto cur1=L.top();
            auto cur2=R.top();
            L.pop();
            R.pop();
            if(cur1->val!=cur2->val) return false;
            if(cur1->right==nullptr&&cur2->left==nullptr){

            }else if(cur1->right==nullptr||cur2->left==nullptr){
                return false;
            }else{
                L.push(cur1->right);
                R.push(cur2->left);
            }
            if(cur1->left==nullptr&&cur2->right==nullptr){

            }else if(cur1->left==nullptr||cur2->right==nullptr){
                return false;
            }else{
                L.push(cur1->left);
                R.push(cur2->right);
            }
        }
        return L.empty()&&R.empty();
    }
};