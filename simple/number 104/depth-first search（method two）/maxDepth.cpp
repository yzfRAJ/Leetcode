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
void PreorderTraversal(TreeNode* root,int length,int &max_length){
    if(root==nullptr){
        return; 
    } 
    length++;
    if(length>max_length) max_length=length;
    PreorderTraversal(root->left,length,max_length);
    PreorderTraversal(root->right,length,max_length);    
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int length=0,max_length=0;
        PreorderTraversal(root,length,max_length);
        return max_length;
    }
};