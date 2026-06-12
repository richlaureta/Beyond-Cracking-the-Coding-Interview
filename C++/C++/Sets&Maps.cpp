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

string mostFrequentOctet(const vector<string> &ips)
{
    //Problem 30.3 - Most Frequent Octet
    
    unordered_map<string, int> octetFrequencyMap;
    int mostCommonCountOctet = 0;
    string mostCommonOctet = "";
    
    for(string ip: ips)
    {
        size_t dotIndex = ip.find('.');
        string octet = ip.substr(0, dotIndex);
        octetFrequencyMap[octet]++;
        if(octetFrequencyMap[octet] > mostCommonCountOctet)
        {
            mostCommonCountOctet = octetFrequencyMap[octet];
            mostCommonOctet = octet;
        }
    }
    
    return mostCommonOctet;
}

bool multiAccountCheating(const vector<pair<string, vector<string>>> &users)
{
    //Problem 30.4 - Multi-Account Cheating
    
    unordered_set<string> ipSet = {};
    
    for(pair<string, vector<string>> user: users)
    {
        for(string ip: user.second)
        {
            if(ipSet.find(ip) != ipSet.end()) return true;
        }
        
        for(string ip: user.second)
        {
            ipSet.insert(ip);
        }
    }
    
    return false;
}

void DomainResolver::registerDomain(string ip, string domain)
{
    //Problem 30.5 - Domain Resolver
    
    ipToDomainSetMap[ip].insert(domain);
}

void DomainResolver::registerSubdomain(string domain, string subdomain)
{
    //Problem 30.5 - Domain Resolver
    
    domainToSubdomainSetMap[domain].insert(subdomain);
}

bool DomainResolver::hasSubdomain(string ip, string domain, string subdomain)
{
    //Problem 30.5 - Domain Resolver
    
    if(ipToDomainSetMap[ip].find(domain) == ipToDomainSetMap[ip].end()) return false;
    
    if(domainToSubdomainSetMap[domain].find(subdomain) == domainToSubdomainSetMap[domain].end()) return false;
        
    return true;
}

vector<vector<int>> findSquared(const vector<int> &arr)
{
    //Problem 30.6 Find All Sqaures
    
    unordered_map<int, int> numberIndex;
    
    for(int index0 = 0; index0 < (int) arr.size(); index0++)
    {
        numberIndex[arr[index0]] = index0;
    }
    
    vector<vector<int>> squaredIndex;
    
    for(int index = 0; index < (int) arr.size(); index++)
    {
        int squaredNumber = arr[index] * arr[index];
        
        if(numberIndex.contains(squaredNumber))
        {
            squaredIndex.push_back({index, numberIndex[squaredNumber]});
        }
    }

    return squaredIndex;
}
