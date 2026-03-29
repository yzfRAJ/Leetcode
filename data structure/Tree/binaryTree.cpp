#include "binaryTree.h"
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

TreeNode* CreatBinaryTree(vector<int> &nums){//层序建树
    if(nums.empty()) return nullptr;
    if(nums[0] == -1) return nullptr;
    TreeNode* root=new TreeNode(nums[0]);
    queue<TreeNode*> p;
    p.push(root);
    int idx=1;
    while(!p.empty() && idx<nums.size()){
        auto cur=p.front();
        p.pop();
        if(idx<nums.size()&&nums[idx]!=-1){
            cur->left=new TreeNode(nums[idx]);
            p.push(cur->left);
        }
        idx++;
        if(idx<nums.size()&&nums[idx]!=-1){
            cur->right=new TreeNode(nums[idx]);
            p.push(cur->right);
        }
        idx++;
    }
    return root;
}


void RecursionCreatBinaryTree(TreeNode*& root,vector<int> &nums,int &idx){
    if(idx >= static_cast<int>(nums.size()) || nums[idx] == -1){
        root = nullptr;
        idx++;
        return;
    }
    root = new TreeNode(nums[idx]);
    idx++;
    RecursionCreatBinaryTree(root->left, nums, idx);
    RecursionCreatBinaryTree(root->right, nums, idx);
}

void RecursionPreorderTraversal(TreeNode* root,vector<int>& vec){//递归前序遍历:中左右
    if(root == nullptr) return;
    vec.push_back(root->data);
    RecursionPreorderTraversal(root->left,vec);
    RecursionPreorderTraversal(root->right,vec);
}
void RecursionInorderTraversal(TreeNode* root,vector<int>& vec){//递归中序遍历：左中右
    if(root==nullptr) return;
    RecursionInorderTraversal(root->left, vec);
    vec.push_back(root->data);
    RecursionInorderTraversal(root->right, vec);
}
void RecursionPostorderTraversal(TreeNode* root,vector<int>& vec){//递归后序遍历：左右中
    if(root == nullptr) return;
    RecursionPostorderTraversal(root->left, vec);
    RecursionPostorderTraversal(root->right, vec);
    vec.push_back(root->data);
}

void IterationPreorderTraversal(TreeNode* root,vector<int>& vec){//迭代前序遍历:中左右
    if(root == nullptr) return;
    stack<TreeNode*> p;
    p.push(root);
    while(!p.empty()){
        auto cur=p.top();
        p.pop();
        vec.push_back(cur->data);
        if(cur->right!=nullptr){
            p.push(cur->right);
        }
        if(cur->left!=nullptr){
            p.push(cur->left);
        }
    }

}
void IterationInorderTraversal(TreeNode* root,vector<int>& vec){//迭代中序遍历：左中右
    stack<TreeNode*>p;
    auto cur=root;
    while(cur!=nullptr||!p.empty()){
        if(cur!=nullptr){
            p.push(cur);
            cur=cur->left;
        }else{
            cur=p.top();
            vec.push_back(cur->data);
            p.pop();
            cur=cur->right;
        }
    }
}
void IterationPostorderTraversal(TreeNode* root,vector<int>& vec){//迭代后序遍历：左右中
    if(root == nullptr) return;
    stack<TreeNode*> p;
    p.push(root);
    while(!p.empty()){
        auto cur=p.top();
        p.pop();
        vec.push_back(cur->data);
        if(cur->left!=nullptr){
            p.push(cur->left);
        }
        if(cur->right!=nullptr){
            p.push(cur->right);
        }        
    }
    reverse(vec.begin(),vec.end());
}




