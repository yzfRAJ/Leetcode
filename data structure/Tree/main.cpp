#include <iostream>
#include <vector>
#include "binaryTree.h"

int main(){
    vector<int> nums={0,2,9,-1,8,-1,-1,-1,3,7,-1,-1,5,-1,6};
    TreeNode* tree=nullptr;
    int idx=0;
    RecursionCreatBinaryTree(tree,nums,idx);
    vector<int> vec;
    RecursionPostorderTraversal(tree,vec);
    // IterationPostorderTraversal(tree,vec);
    cout<<"ºóÐò±éÀúÔªËØ";
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}