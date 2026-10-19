//
//  Miscelaneous.cpp
//  C++
//
//  Created by Richmond Laureta on 10/15/26.
//

#include "Header.hpp"

int romanToInt(string s)
{
    //LeetCode Problem 13 - Roman to Integer
    
    unordered_map<char, int> romanValueMap =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int countInteger = 0;
        
    int pointer = 0;
    
    while(pointer < s.size() - 1)
    {
        if(romanValueMap[s[pointer + 1]] > romanValueMap[s[pointer]])
        {
            countInteger += romanValueMap[s[pointer + 1]] - romanValueMap[s[pointer]];
            pointer += 2;
        }
        else
        {
            countInteger += romanValueMap[s[pointer]];
            pointer++;
        }
    }
    
    if(pointer == s.size() - 1) countInteger += romanValueMap[s[s.size() - 1]];
        
    return countInteger;
}

