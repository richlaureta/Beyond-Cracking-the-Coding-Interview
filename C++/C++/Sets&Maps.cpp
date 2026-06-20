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
    //Problem 30.6 - Find All Squares
    
    unordered_map<double, int> numberIndexMap;
    vector<vector<int>> squaredIndex;
    
    for(int index = 0; index < (int) arr.size(); index++)
    {
        numberIndexMap[arr[index] + 0.0] = index;

        double number = (arr[index] * arr[index]) + 0.0;
        double squareRoot = sqrt(arr[index]);
        
        if(numberIndexMap.contains(number)) squaredIndex.push_back({index, numberIndexMap[number]});
        else if(numberIndexMap.contains(squareRoot)) squaredIndex.push_back({numberIndexMap[squareRoot], index});
        
    }
    
    return squaredIndex;
}

Checker::Checker(const string &word1)
{
    //Problem 30.7 - Word Expansion Class
    
    this->word = word1;
    
    for(char letter: word1)
    {
        wordMapFrequency[letter]++;
    }
}

bool Checker::expandsInto(const string &word2)
{
    //Problem 30.7 - Word Expansion Class
    
    if((int) word2.length() <= (int) this->word.length() or (int) word2.length() > ((int) word.length()) + 1) return false;
    
    unordered_map<char, int> wordFrequencyMap1;
    wordFrequencyMap1.reserve(this->wordMapFrequency.size());
    wordFrequencyMap1 = this->wordMapFrequency;
    
    int wordLength = (int) word.length();
    int exactlyOneCount = 0;
    
    for(char letter1: word2)
    {
        if(wordFrequencyMap1.find(letter1) == wordFrequencyMap1.end())
        {
            exactlyOneCount++;
            if(exactlyOneCount > 1) return false;
            continue;
        }
        
        wordFrequencyMap1[letter1]--;
        
        if(wordFrequencyMap1[letter1] == -1)
        {
            exactlyOneCount++;
            if(exactlyOneCount > 1) return false;
            continue;
        }
        
        wordLength--;
    }
    
    if(exactlyOneCount == 1 and wordLength == 0) return true;
    
    return false;
}

vector<vector<int>> suspectStudents(const vector<char> &answers, int m, const vector<Student> &students)
{
    //Problem 30.8 - Cheater Detection
    
    if((int) students.size() == 0 or m == 1 or (int) answers.size() == 0) return {};

    unordered_map<int, tuple<int, vector<char>>> deskToTupleMap;
    
    vector<vector<int>> suspectedPairsVector;
    
    for(Student student: students)
    {
        if(deskToTupleMap.find(student.desk - 1) != deskToTupleMap.end() and (student.desk - 1) % m != 0)
        {
            vector<int> wrongAnswerIndexVector = {};
            
            for(int index = 0; index < (int) answers.size(); index++)
            {
                if(answers[index] != student.answers[index]) wrongAnswerIndexVector.push_back(index);
            }
            
            for(int index1 = 0; index1 < (int) wrongAnswerIndexVector.size(); index1++)
            {
                if(student.answers[wrongAnswerIndexVector[index1]] ==
                   get<1>(deskToTupleMap[student.desk - 1])[wrongAnswerIndexVector[index1]])
                {
                    suspectedPairsVector.push_back({get<0>(deskToTupleMap[student.desk - 1]), student.ID});
                    break;
                }
            }
        }
        
        if(deskToTupleMap.find(student.desk + 1) != deskToTupleMap.end() and (student.desk + 1) % m != 1)
        {
            vector<int> wrongAnswerIndexVector = {};
            
            for(int index = 0; index < (int) answers.size(); index++)
            {
                if(answers[index] != student.answers[index]) wrongAnswerIndexVector.push_back(index);
            }
            
            for(int index1 = 0; index1 < (int) wrongAnswerIndexVector.size(); index1++)
            {
                if(student.answers[wrongAnswerIndexVector[index1]] ==
                   get<1>(deskToTupleMap[student.desk + 1])[wrongAnswerIndexVector[index1]])
                {
                    suspectedPairsVector.push_back({get<0>(deskToTupleMap[student.desk + 1]), student.ID});
                    break;
                }
            }
        }
        
        deskToTupleMap[student.desk] = {student.ID, student.answers};
    }
    
    return suspectedPairsVector;
}
