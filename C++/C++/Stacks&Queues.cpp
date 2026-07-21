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
    
    if((int) URLStack.size() == 0) return "";
    
    return URLStack.top();
}
