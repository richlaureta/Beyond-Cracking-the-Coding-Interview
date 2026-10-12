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
