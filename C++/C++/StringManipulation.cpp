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

int indexOf(string &s, string &t)
{
    //Problem 26.3 String Matching
    if(t.size() == 0) return 0;
    
    size_t index = s.find(t);
    
    if(index != string::npos) return (int)index;
    
    return -1;
}

int strStr(string haystack, string needle)
{
    //Problem #28 Find the Index of the First Occurrence in a String - Easy
    
    if(haystack.size() < needle.size()) return -1;
    
    int needleSum = 0;
    for(char letter: needle) needleSum += int(letter);
    
    int hayStackSum = 0;
    
    for(int index = 0; index < needle.size(); index++) hayStackSum += (int) haystack[index];
    
    int initialIndex = 0;
    if(needleSum == hayStackSum)
    {
        for(char letter1: needle)
        {
            if(letter1 != haystack[initialIndex]) break;
            initialIndex++;
            if(initialIndex == (int)needle.size()) return 0;
        }
    }
    
    int subtractIndex = 0;
    for(int index1 = (int)needle.size(); index1 < (int)haystack.size(); index1++)
    {
        hayStackSum -= (int)haystack[subtractIndex];
        hayStackSum += (int)haystack[index1];
        int temporaryIndex = subtractIndex + 1;
        if(needleSum == hayStackSum)
        {
            for(char letter2: needle)
            {
                if(letter2 != haystack[temporaryIndex]) break;
                temporaryIndex ++;
                
                if (temporaryIndex == index1 + 1) return subtractIndex + 1;
            }
        }
        subtractIndex++;
    }
    
    return -1;
}
