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
        vector<int> vec;
        TreeNode* predecessor=nullptr;
        while(root !=nullptr){
            if(root->left!=nullptr){
                predecessor=root->left;
                while(predecessor->right!=nullptr&&predecessor->right!=root){//右边为空，且右边不等于root
                    predecessor=predecessor->right;
                }
                if(predecessor->right==nullptr){//右边为空
                    predecessor->right=root;
                    root=root->left;
                }else{
                    vec.push_back(root->val);
                    root=root->right;
                    predecessor->right=nullptr;//断开
                }    
            //左边为空就访问右边
            }else{
                vec.push_back(root->val);
                root=root->right;
            }
        }
        return vec;
    }
};