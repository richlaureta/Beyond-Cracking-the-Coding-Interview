//
//  Graphs.cpp
//  C++
//
//  Created by Richmond Laureta on 10/12/26.
//

#include "Header.hpp"

bool validate(const vector<vector<int>>& graph)
{
    //Problem 36.1 - Adjacency List Validation
    
    unordered_map<int, unordered_set<int>> nodeSetMap;
    for (int index = 0; index < graph.size(); index++)
    {
        for(int number : graph[index])
        {
            if (number > (graph.size() - 1) or
                number < 0 or
                number == index or
                nodeSetMap[index].find(number) != nodeSetMap[index].end())
            {
                return false;
            }
            
            nodeSetMap[index].insert(number);
        }
    }
    
    for(int index = 0; index < graph.size(); index++)
    {
        for(int number : graph[index])
        {
            if(nodeSetMap[number].find(index) == nodeSetMap[number].end()) return false;
        }
    }
    
    return true;
}

vector<int> pathBfs(const vector<vector<int>>& graph, int node1, int node2) {
    //Problem 36.2 - Graph Path - Part of the Tests
    
  std::queue<int> Q;
  Q.push(node2);
  std::unordered_map<int, int> predecessors;
  predecessors[node2] = -1;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    for (int nbr : graph[node]) {
      if (predecessors.find(nbr) == predecessors.end()) {
        predecessors[nbr] = node;
        Q.push(nbr);
      }
    }
  }
  if (predecessors.find(node1) == predecessors.end()) {
    return std::vector<int>();
  }
  std::vector<int> path = {node1};
  while (path.back() != node2) {
    path.push_back(predecessors[path.back()]);
  }
  return path;
}

void pathDfs(const vector<vector<int>> &graph, int nodeIndex, int node2, vector<int> &pathVector, vector<int> &temporaryPathVector, unordered_set<int> &pathSet, bool &foundFlag)
{
    //Problem 36.2 - Graph Path
    
    for(int index = 0; index < graph[nodeIndex].size(); index++)
    {
        if(graph[nodeIndex][index] == node2)
        {
            pathVector.insert(pathVector.end(), temporaryPathVector.begin(), temporaryPathVector.end());
            pathVector.push_back(graph[nodeIndex][index]);
            foundFlag = true;
            return;
        }
        
        if (pathSet.find(graph[nodeIndex][index]) != pathSet.end()) continue;
            
        pathSet.insert(graph[nodeIndex][index]);
        temporaryPathVector.push_back(graph[nodeIndex][index]);
            
        pathDfs(graph, graph[nodeIndex][index], node2, pathVector, temporaryPathVector, pathSet, foundFlag);
            
        if(foundFlag == true) return;
            
        temporaryPathVector.pop_back();
    }
}

vector<int> path(const vector<vector<int>> &graph, int node1, int node2)
{
    //Problem 36.2 - Graph Path
    
    if(node1 == node2) return {node1};
    
    vector<int> pathVector = {node1};
    vector<int> temporaryPathVector;
    unordered_set<int> pathSet = {node1};
    
    bool foundFlag = false;
            
    for(int index = 0; index < graph[node1].size(); index++)
    {
        if(graph[node1][index] == node2)
        {
            pathVector.push_back(graph[node1][index]);
            return pathVector;
        }
        
        pathSet.insert(graph[node1][index]);
        temporaryPathVector.push_back(graph[node1][index]);
        
        pathDfs(graph, graph[node1][index], node2, pathVector, temporaryPathVector, pathSet, foundFlag);
        
        if(foundFlag == true) break;
        
        temporaryPathVector.pop_back();
    }
    
    if(foundFlag == false) return {};
    
    return pathVector;
}

bool isTree(const vector<vector<int>> &graph)
{
    //Problem 36.3 - Tree Check
    
    if(graph.size() == 0) return true;
    
    deque<pair<int, int>> nodeDequeue = {{0, -1}};
    unordered_set<int> nodeSet;
    
    while(nodeDequeue.size() > 0)
    {
        int poppedNode = nodeDequeue.front().first;
        int connectionNode = nodeDequeue.front().second;
        
        nodeDequeue.pop_front();
        
        nodeSet.insert(poppedNode);
        for (int nodePoint : graph[poppedNode])
        {
            if(nodeSet.find(nodePoint) == nodeSet.end()) nodeDequeue.push_back({nodePoint, poppedNode});
            else if(nodePoint != connectionNode) return false;
        }
    }
    
    if(graph.size() == nodeSet.size()) return true;
    
    return false;
}

void dfsSpanning(int node, unordered_set<int> &nodeSet, vector<vector<int>> &spanningConnectionVector,
                 const vector<vector<int>> &graph)
{
    //Problem 36.4 - Spanning Tree
    
    for(int nodeIndex : graph[node])
    {
        if(nodeSet.find(nodeIndex) != nodeSet.end()) continue;
            
        nodeSet.insert(nodeIndex);
        spanningConnectionVector.push_back({node, nodeIndex});
        dfsSpanning(nodeIndex, nodeSet, spanningConnectionVector, graph);
    }
}

vector<vector<int>> spanningTree(const vector<vector<int>> &graph)
{
    //Problem 36.4 - Spanning Tree
    
    unordered_set<int> nodeSet;
    vector<vector<int>> spanningConnectionVector;
        
    nodeSet.insert(0);
        
    dfsSpanning(0, nodeSet, spanningConnectionVector, graph);
    
    return spanningConnectionVector;
}
