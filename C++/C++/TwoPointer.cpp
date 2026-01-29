//
//  TwoPointer.cpp
//  C++
//
//  Created by Richmond Laureta on 1/28/26.
//

#include "Header.hpp"

bool palindrome(string s)
{
    int leftPointer = 0;
    int rightPointer = (int)s.size() - 1;
    
    while(leftPointer < rightPointer)
    {
        if(s[leftPointer] != s[rightPointer]) return false;
        
        leftPointer++;
        rightPointer--;
    }
    
    return true;
}
