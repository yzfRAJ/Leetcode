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
//左开右闭
TreeNode* sortarray(vector<int>& nums,int left,int right) {
        if(left>=right) return nullptr;
        int mid=left+(right-left)/2;
        auto root=new TreeNode(nums[mid]);
        root->left=sortarray(nums,left,mid);
        root->right=sortarray(nums,mid+1,right);
        return root;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0,right=nums.size();
        TreeNode* root=sortarray(nums,left,right);
        return root;
    }
};