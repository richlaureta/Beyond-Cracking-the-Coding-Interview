//
//  Trees.cpp
//  C++
//
//  Created by Richmond Laureta on 9/3/26.
//

#include "Header.hpp"

TreeNode::TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
NaryNode::NaryNode(string kind, int num, vector<NaryNode*> children) : kind(kind), num(num), children(children) {};

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

void dfsStacked(TreeNode* node, int leftCoordinate, int rightCoordinate, int* maxStackedCount, map<pair<int, int>, int>& coordinateMapCount)
{
    //Problem 35.4 - Tree Layout
    
    if(!node) return;
    
    coordinateMapCount[{leftCoordinate, rightCoordinate}]++;
    
    *maxStackedCount = max(*maxStackedCount, coordinateMapCount[{leftCoordinate, rightCoordinate}]);

    dfsStacked(node->left, leftCoordinate + 1, rightCoordinate, maxStackedCount, coordinateMapCount);
    dfsStacked(node->right, leftCoordinate, rightCoordinate + 1, maxStackedCount, coordinateMapCount);
}

int mostStacked(TreeNode* root)
{
    //Problem 35.4 - Tree Layout
    
    int maxStackCount = 0;
    
    map<pair<int, int>, int> coordinateMapCount;
    
    dfsStacked(root, 0, 0, &maxStackCount, coordinateMapCount);
    
    return maxStackCount;
}

int triangleCount(TreeNode* root)
{
    //Problem 35.5 - Triangle Count
    
    if(!root) return 0;
    
    vector<TreeNode*> nodeTriangleVector;
    deque<TreeNode*> nodeDequeue;
    nodeDequeue.push_back(root);
    
    while(!nodeDequeue.empty())
    {
        TreeNode* poppedNode = nodeDequeue.front();
        nodeDequeue.pop_front();
        
        if(poppedNode->left and poppedNode->right) nodeTriangleVector.push_back(poppedNode);
        
        if(poppedNode->left) nodeDequeue.push_back(poppedNode->left);
        
        if(poppedNode->right) nodeDequeue.push_back(poppedNode->right);
    }
    
    int triangleCount = 0;
    
    for(TreeNode* node : nodeTriangleVector)
    {
        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;
        while(leftNode and rightNode)
        {
            triangleCount++;
            leftNode = leftNode->left;
            rightNode = rightNode->right;
        }
    }
    return triangleCount;

}

bool sameValues(TreeNode* t1, TreeNode* t2) {
    //Problem 35.6 - Invert a Binary Tree
    
      if (!t1 && !t2) {
        return true;
      }
      if (!t1 || !t2) {
        return false;
      }
      return (t1->val == t2->val && sameValues(t1->left, t2->left) &&
              sameValues(t1->right, t2->right));
}

TreeNode* invert(TreeNode* root)
{
    //Problem 35.6 - Invert a Binary Tree
    
    if(!root) return nullptr;
    
    deque<TreeNode*> nodeDequeue;
    
    nodeDequeue.push_back(root);
    
    while(nodeDequeue.size() > 0)
    {
        TreeNode* poppedNode = nodeDequeue.front();
        nodeDequeue.pop_front();
        
        TreeNode* leftNode = poppedNode->left;
        TreeNode* rightNode = poppedNode->right;
        
        if(poppedNode->left) nodeDequeue.push_back(poppedNode->left);
        
        poppedNode->left = rightNode;
        
        if(poppedNode->right) nodeDequeue.push_back(poppedNode->right);
        
        poppedNode->right = leftNode;
    }
    
    return root;
}

int evaluate(NaryNode* node)
{
    //Problem 35.7 - Evaluate Expression Tree
    
    if(node->kind == "num") return node->num;
    else if(node->kind == "sum")
    {
        int sum = 0;
        for(NaryNode* child : node->children) sum += evaluate(child);
        return sum;
    }
    else if(node->kind == "product")
    {
        int product = 1;
        for(NaryNode* child : node->children) product *= evaluate(child);
        return product;
    }
    else if(node->kind == "min")
    {
        int minimumNumber = INT_MAX;
        for(NaryNode* child : node->children) minimumNumber = min(minimumNumber, evaluate(child));
        return minimumNumber;
    }
    else if (node->kind == "max")
    {
        int maximumNumber = INT_MIN;
        for(NaryNode* child : node->children) maximumNumber = max(maximumNumber, evaluate(child));
        return maximumNumber;
    }
    
    throw invalid_argument("Invalid node kind.");
}
