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

void InorderTraversal(TreeNode* tree,vector<int> &vec){
    if(tree==nullptr) return;
    InorderTraversal(tree->left,vec);
    vec.push_back(tree->val);
    InorderTraversal(tree->right,vec);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vec;
        InorderTraversal(root,vec);
        return vec;
    }
};