//
//  Stacks&Queues.cpp
//  C++
//
//  Created by Richmond Laureta on 7/15/26.
//

#include "Header.hpp"

vector<int> compressArray(const vector<int> &arr)
{
    //Problem 32.1 - Compress Array
    
    if(arr.empty()) return {};
    
    vector<int> numberStack;
    numberStack.push_back(arr[0]);
    
    for(int number: span(arr).subspan(1))
    {
        if(number == numberStack.back())
        {
            int poppedNumber = numberStack.back();
            numberStack.pop_back();
            while(!numberStack.empty() and numberStack.back() == poppedNumber * 2)
            {
                poppedNumber = numberStack.back();
                numberStack.pop_back();
            }
            
            numberStack.push_back(poppedNumber * 2);
            
            continue;
        }
        
        numberStack.push_back(number);
    }
    
    return numberStack;
}

vector<int> CompressArrayK::solve(const vector<int> &arr, int k)
{
    //Problem 31.2 - Compress Array by K
    
    vector<int> numberStack;
    int kCount = 1;
    
    for(int number: arr)
    {
        if(!numberStack.empty() and numberStack.back() == number)
        {
            kCount++;
            if(kCount == k)
            {
                for(int index = 0; index < k - 1; index++) numberStack.pop_back();
                int kProduct = number * k;
                int lastIndex = (int) numberStack.size() - 1;
                int kBacktrackCount = 1;
                
                while(lastIndex > -1 and kProduct == numberStack[lastIndex])
                {
                    kBacktrackCount++;
                    if(kBacktrackCount == k)
                    {
                        for(int index = 0; index < k - 1; index++) numberStack.pop_back();
                        kProduct *= k;
                        kBacktrackCount = 1;
                    }
                    
                    lastIndex--;
                }
                
                numberStack.push_back(kProduct);
                kCount = 1;
                continue;
            }
            
            numberStack.push_back(number);
            continue;
        }
        
        numberStack.push_back(number);
        kCount = 1;
    }
    
    return numberStack;
}

string currentUrl(const vector<pair<string, string>> &actions)
{
    //Problem 32.4 - Current URL
    
    stack<string> URLStack;
    for(auto action: actions)
    {
        if(action.first != "go")
        {
            int popCount = 0;
            int conversionToInteger;
            from_chars(action.second.data(), action.second.data() + action.second.size(), conversionToInteger);
            while(popCount != conversionToInteger and (int) URLStack.size() != 1)
            {
                URLStack.pop();
                popCount++;
            }
            continue;
        }
        
        URLStack.push(action.second);
    }
    
    if(URLStack.empty()) return "";
    
    return URLStack.top();
}

string currentUrlWithForward(const vector<pair<string, string>> &actions)
{
    //Problem 32.5 - Current Url with Forward
    
    stack<string> urlStack;
    deque<string> backedURLStack;
    
    for(pair<string, string> action: actions)
    {
        if(action.first == "go")
        {
            backedURLStack = {};
            urlStack.push(action.second);
        }
        else if(action.first == "back")
        {
            int popCount = 0;
            int convertedToInteger;
            from_chars(action.second.data(), action.second.data() + action.second.size(), convertedToInteger);
            while(popCount != convertedToInteger and (int) urlStack.size() != 1)
            {
                backedURLStack.push_back(urlStack.top());
                urlStack.pop();
                popCount++;
            }
        }
        else
        {
            int popCount = 0;
            int convertedToInteger;
            from_chars(action.second.data(), action.second.data() + action.second.size(), convertedToInteger);
            while(!backedURLStack.empty() and popCount != convertedToInteger)
            {
                urlStack.push(backedURLStack.front());
                backedURLStack.pop_front();
                popCount++;
            }
        }
    }
    
    if(urlStack.empty()) return "";
    
    return urlStack.top();
}

int maxBalancedPartition(const string &s)
{
    //Problem 32.6 - Balanced Partition
    
    int balancedPartitionCount = 0;
    int parenthesisCount = 0;
    
    for(char parenthesis: s)
    {
        if(parenthesis == '(') parenthesisCount++;
        else
        {
            parenthesisCount--;
            if(parenthesisCount == 0) balancedPartitionCount++;
        }
    }
    
    return balancedPartitionCount;
}

bool customBrackets(const string &s, const vector<string> &brackets)
{
    //Problem 32.7 - Custom Brackets
    
    unordered_map<char, char> openCloseBracketsMap;
    unordered_set<char> closeBracketsSet;
    
    for(string bracket: brackets)
    {
        openCloseBracketsMap[bracket[0]] = bracket[1];
        closeBracketsSet.insert(bracket[1]);
    }
    
    stack<char> bracketStack;
    
    for(char character: s)
    {
        if(openCloseBracketsMap.find(character) != openCloseBracketsMap.end())
        {
            bracketStack.push(openCloseBracketsMap[character]);
        }
        else if(closeBracketsSet.find(character) != closeBracketsSet.end())
        {
            if(bracketStack.empty() or character != bracketStack.top()) return false;
            
            bracketStack.pop();
        }
    }
    
    return (int) bracketStack.size() == 0;
}
