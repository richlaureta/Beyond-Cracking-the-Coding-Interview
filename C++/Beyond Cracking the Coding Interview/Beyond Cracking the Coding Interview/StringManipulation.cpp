//
//  StringManipulation.cpp
//  Beyond Cracking the Coding Interview
//
//  Created by Richmond Laureta on 1/16/26.
//

#include "Header.hpp"

int testing(int n)
{
    return n;
}

vector<string> split(const string &s, char c)
{
    //Beyond Cracking the Coding Interview - Problem 26.1 String Split
    
    if((int) s.size() == 0) return {};
    
    vector<string> splitStringVector;
    string temporayStringArray = "";
    
    for(int index = 0; index < s.size(); index++)
    {
        if(s[index] == c)
        {
            if(index > 0 and s[index - 1] == c )
            {
                splitStringVector.push_back("");
                continue;
            }
            splitStringVector.push_back(temporayStringArray);
            temporayStringArray = "";
            continue;
        }
        
        temporayStringArray.push_back(s[index]);
    }
    
    splitStringVector.push_back(temporayStringArray);
    
    return splitStringVector;
}
