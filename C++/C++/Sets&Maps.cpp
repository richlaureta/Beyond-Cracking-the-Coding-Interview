//
//  Sets&Maps.cpp
//  C++
//
//  Created by Richmond Laureta on 6/8/26.
//

#include "Header.hpp"

string accountSharing(const vector<pair<string, string>> &connections)
{
    //Problem 30.1 Account Sharing Detection
    
    unordered_set<string> names;
    
    for(pair<string, string> connection: connections)
    {
        if(names.find(connection.second) != names.end()) return connection.first;
        
        names.insert(connection.second);
    }
    
    return "";
}
