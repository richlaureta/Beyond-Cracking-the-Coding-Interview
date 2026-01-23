//
//  StringManipulation.cpp
//  C++
//
//  Created by Richmond Laureta on 1/16/26.
//

#include "Header.hpp"

bool isLowerCase(char c)
{
    if((int)c > 96 and (int)c < 123) return true;
    return false;
}

bool isUpperCase(char c)
{
    if((int)c > 64 and (int)c < 91) return true;
    return false;
}

bool isDigit(char c)
{
    if((int)c > 47 and (int)c  < 58) return true;
    return false;
}

bool isAlphaNumeric(char c)
{
    return isLowerCase(c) or isUpperCase(c) or isDigit(c);
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
            if(index > 0 and s[index - 1] == c)
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

string join(const vector<string> &arr, const string &s)
{
    //Problem 26.2 String Join
    
    string combinedString = "";
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == s)
        {
            combinedString.append(s);
        }
        
        if(i == arr.size() -1 and arr[i] == "") continue;
        
        if(arr[i] == "")
        {
            combinedString.append(s);
            continue;
        }
        
        combinedString.append(arr[i]);
        
        if(i < arr.size() - 1) combinedString.append(s);
    }
    
    return combinedString;
}
