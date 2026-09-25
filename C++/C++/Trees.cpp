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

vector<int> leftView(TreeNode* root)
{
    //Problem 35.8 - Left View
    
    if(!root) return {};
    
    deque<pair<TreeNode*, int>> nodeDequeue;
    nodeDequeue.push_back({root, 0});
    
    vector<int> leftViewNodeVector = {root->val};
    unordered_set<int> depthLevelSet;
    
    while(nodeDequeue.size() > 0)
    {
        pair<TreeNode*, int> poppedNode = nodeDequeue.front();
        nodeDequeue.pop_front();
        
        if(poppedNode.first->left)
        {
            nodeDequeue.push_back({poppedNode.first->left, poppedNode.second + 1});
            if(depthLevelSet.find(poppedNode.second + 1) == depthLevelSet.end())
            {
                depthLevelSet.insert(poppedNode.second + 1);
                leftViewNodeVector.push_back(poppedNode.first->left->val);
            }
        }
        
        if(poppedNode.first->right)
        {
            nodeDequeue.push_back({poppedNode.first->right, poppedNode.second + 1});
            if(depthLevelSet.find(poppedNode.second + 1) == depthLevelSet.end())
            {
                depthLevelSet.insert(poppedNode.second + 1);
                leftViewNodeVector.push_back(poppedNode.first->right->val);
            }
        }
    }
    
    return leftViewNodeVector;
}

int mostProlificLevel(TreeNode* root)
{
    //Problem 35.9 - Most Prolific Level
    
    if(!root) return -1;
    
    if (!root->left and !root->right) return 0;
    
    deque<pair<TreeNode*, int>> nodeDequeue;
    nodeDequeue.push_back({root, 0});
    unordered_map<int, int> depthLevelNodeCountMap;
    
    double maxProlificValue = INT_MIN;
    int maxProlificLevel = INT_MIN;
    
    unordered_set depthLevelSet = {-2, -1};
    
    pair<TreeNode*, int> poppedNode;
    while(nodeDequeue.size() > 0)
    {
        poppedNode = nodeDequeue.front();
        nodeDequeue.pop_front();
        depthLevelNodeCountMap[poppedNode.second]++;
        
        if(depthLevelSet.find(poppedNode.second - 2) == depthLevelSet.end())
        {
            double prolificValue = depthLevelNodeCountMap[poppedNode.second - 1]/depthLevelNodeCountMap[poppedNode.second - 2];
            
            if(prolificValue > maxProlificValue)
            {
                maxProlificValue = prolificValue;
                maxProlificLevel = poppedNode.second - 2;
            }
            
            depthLevelSet.insert(poppedNode.second - 2);
        }
        
        if(poppedNode.first->left) nodeDequeue.push_back({poppedNode.first->left, poppedNode.second + 1});
        
        if(poppedNode.first->right) nodeDequeue.push_back({poppedNode.first->right, poppedNode.second + 1});
    }
    
    double prolificValue = depthLevelNodeCountMap[poppedNode.second] / depthLevelNodeCountMap[poppedNode.second - 1];
    
    if(prolificValue > maxProlificValue)
    {
        maxProlificValue = prolificValue;
        maxProlificLevel = poppedNode.second - 1;
    }
            
    return maxProlificLevel;
}

vector<int> zigzagOrder(TreeNode* root)
{
    //Problem 35.10 - Zig-Zag Order
    
    if(!root) return {};
     
    vector<int> zigzagVector = {root->val};
    unordered_set<int> depthLevelSet = {-1, 0};

    unordered_map<int, vector<int>> levelValueVectorMap;
    deque<pair<TreeNode*, int>> nodeLevelDequeue;

    pair<TreeNode*, int> poppedNodeLevel;
    while node_l
     popped_node_level = node_level_deueue.popleft()
     level_value_list_dictionary[popped_node_level[1]].append(popped_node_level[0].val)
     
     if popped_node_level[1] - 1 not in depth_level_set:
         if (popped_node_level[1] - 1) % 2 == 0:
             for number in level_value_list_dictionary[popped_node_level[1] - 1]:
                 zigzag_list.append(number)
         else:
             for number in reversed(level_value_list_dictionary[popped_node_level[1] - 1]):
                 zigzag_list.append(number)
         
         depth_level_set.add(popped_node_level[1] - 1)
                 
     if popped_node_level[0].left:
         node_level_deueue.append((popped_node_level[0].left, popped_node_level[1] + 1))
         
     if popped_node_level[0].right:
         node_level_deueue.append((popped_node_level[0].right, popped_node_level[1] + 1))

    if popped_node_level[1] not in depth_level_set:
     if popped_node_level[1] % 2 == 0:
         for number in level_value_list_dictionary[popped_node_level[1]]:
             zigzag_list.append(number)
     else:
         for number in reversed(level_value_list_dictionary[popped_node_level[1]]):
             zigzag_list.append(number)
         
    return zigzag_list
}
