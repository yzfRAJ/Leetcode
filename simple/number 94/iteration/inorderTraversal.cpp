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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> p;
        TreeNode* cur=root;
        vector<int> vec;
        while(cur!=nullptr||!p.empty()){
            if(cur!=nullptr){
                p.push(cur);
                cur=cur->left;
            }else{
                cur=p.top();
                vec.push_back(cur->val);
                p.pop();
                cur=cur->right;
            }
        }
        return vec;
    }
};