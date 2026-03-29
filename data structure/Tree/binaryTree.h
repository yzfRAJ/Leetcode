#ifndef __BINARYTREE_H
#define __BINARYTREE_H

#include <iostream>
#include <vector>

using namespace std;

typedef int ElemType;

struct TreeNode{
    ElemType data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(nullptr),right(nullptr){}
    TreeNode(ElemType data):data(data),left(nullptr),right(nullptr){}
    TreeNode(ElemType data,TreeNode* left,TreeNode* right):data(data),left(left),right(right){}
};

TreeNode* CreatBinaryTree(vector<int> &nums);//层序创建二叉树
void RecursionCreatBinaryTree(TreeNode*& root,vector<int> &nums,int &idx);//递归创建二叉树




void RecursionPreorderTraversal(TreeNode* root,vector<int>& vec);//递归前序遍历:中左右
void RecursionInorderTraversal(TreeNode* root,vector<int>& vec);//递归中序遍历：左中右
void RecursionPostorderTraversal(TreeNode* root,vector<int>& vec);//递归后序遍历：左右中

void IterationPreorderTraversal(TreeNode* root,vector<int>& vec);//迭代前序遍历:中左右
void IterationInorderTraversal(TreeNode* root,vector<int>& vec);//迭代中序遍历：左中右
void IterationPostorderTraversal(TreeNode* root,vector<int>& vec);//迭代后序遍历：左右中

#endif

