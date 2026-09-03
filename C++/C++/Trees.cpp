//
//  Trees.cpp
//  C++
//
//  Created by Richmond Laureta on 9/3/26.
//

#include "Header.hpp"

TreeNode::TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};

void recursionChain(TreeNode* node, int depthLevel, int alignedChainCount, int* maxAlignedChainCount)
{
    //Problem 35.1 - Aligned Chain
    
    if(!node) return;
    
    if(node->val == depthLevel)
    {
        alignedChainCount++;
        *maxAlignedChainCount = max(*maxAlignedChainCount, alignedChainCount);
    }
    else alignedChainCount = 0;
    
    depthLevel++;
    recursionChain(node->left, depthLevel, alignedChainCount, maxAlignedChainCount);
    recursionChain(node->right, depthLevel, alignedChainCount, maxAlignedChainCount);
}

int longestAlignedChain(TreeNode* root)
{
    //Problem 35.1 - Aligned Chain
    
    int maxAlignedChainCount = 0;
    
    recursionChain(root, 0, 0, &maxAlignedChainCount);
    
    return maxAlignedChainCount;
}
