//
//  Sets&Maps.cpp
//  C++
//
//  Created by Richmond Laureta on 6/8/26.
//

#include "Header.hpp"

string accountSharing(const vector<pair<string, string>> &connections)
{
    //Problem 30.1 - Account Sharing Detection
    
    unordered_set<string> names;
    
    for(pair<string, string> connection: connections)
    {
        if(names.find(connection.second) != names.end()) return connection.first;
        
        names.insert(connection.second);
    }
    
    return "";
}


string mostSharedAccount(const vector<pair<string, string>> &connections)
{
    //Problem 30.2 - Most Shared Account
    
    unordered_map<string, int> nameUsedCount;
    string mostSharedUser = "";
    int maxNameCountUsed = 0;
    
    for(pair<string, string> connection: connections)
    {
        nameUsedCount[connection.second]++;
        if(nameUsedCount[connection.second] > maxNameCountUsed)
        {
            mostSharedUser = connection.second;
            maxNameCountUsed = nameUsedCount[connection.second];
        }
    }
    
    return mostSharedUser;
}

string mostCommontOctet(const vector<string> &ips)
{
    //Problem 30.3 - Most Frequent Octet
    
    if((int)ips.size() == 1)
    {
        size_t dotIndex0 = ips[0].find('.');
        string octet0 = ips[0].substr(0, dotIndex0);
        return octet0;
    }
    
    unordered_set<string> octetSet = {};
    
    for(string ip: ips)
    {
        size_t dotIndex = ip.find('.');
        string octet = ip.substr(0, dotIndex);
        if(octetSet.find(octet) != octetSet.end()) return octet;
        octetSet.insert(octet);
    }
    
    return "";
}
