//
//  TwoPointer.cpp
//  C++
//
//  Created by Richmond Laureta on 1/28/26.
//

#include "Header.hpp"

bool palindrome(string s)
{
    //Problem 27.1 - Palindrome Check
    
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

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2)
{
    //Problem 27.3 - Array Intersection
    
    int arr1Pointer = 0;
    int arr2Pointer = 0;
    
    vector<int> intersectionVector = {};
    
    while(arr1Pointer < arr1.size() and arr2Pointer < arr2.size())
    {
        if(arr1[arr1Pointer] == arr2[arr2Pointer])
        {
            intersectionVector.push_back(arr1[arr1Pointer]);
            arr1Pointer++;
            arr2Pointer++;
        }
        else if(arr1[arr1Pointer] < arr2[arr2Pointer]) arr1Pointer++;
        else arr1Pointer++;
    }
    
    return intersectionVector;
}

bool palindromicSentence(const string &s)
{
    //Problem 27.4 Palindromic Sentence
    
    int leftPointer = 0;
    int rightPointer = (int)s.size() - 1;
    
    while(leftPointer < rightPointer)
    {
        while(leftPointer < rightPointer and !isalnum(s[leftPointer])) leftPointer++;
        
        
        while(leftPointer < rightPointer and !isalnum(s[rightPointer])) rightPointer--;
    
        if(tolower(s[leftPointer]) != tolower(s[rightPointer])) return false;
        
        leftPointer++;
        rightPointer--;
    }
    
    return true;
}

bool reverseCaseMatch(const string &s)
{
    //Problem 27.5 Reverse Case Match
    
    int leftPointer = 0;
    int rightPointer = (int)s.size() - 1;
    
    while(true)
    {
        while(leftPointer < (int)s.size() and isupper(s[leftPointer])) leftPointer++;
    
        while(rightPointer > -1 and islower(s[rightPointer])) rightPointer--;
        
        if(leftPointer >= (int)s.size() or rightPointer < 0) break;
        
        if(s[leftPointer] != tolower(s[rightPointer])) return false;
        
        leftPointer++;
        rightPointer--;
    }
    
    return true;
}

vector<int> merge(const vector<int> &arr1, const vector<int> &arr2)
{
    //Problem 27.6 Merge Two Sorted Arrays
    
    int arr1Pointer = 0;
    int arr2Pointer = 0;
    
    vector<int> mergedVector = {};
    while(arr1Pointer < arr1.size() and arr2Pointer < arr2.size())
    {
        if(arr1[arr1Pointer] < arr2[arr2Pointer])
        {
            mergedVector.push_back(arr1[arr1Pointer]);
            arr1Pointer++;
        }
        else if(arr1[arr1Pointer] > arr2[arr2Pointer])
        {
            mergedVector.push_back(arr2[arr2Pointer]);
            arr2Pointer++;
        }
        else
        {
            mergedVector.push_back(arr1[arr1Pointer]);
            mergedVector.push_back(arr2[arr2Pointer]);
            arr1Pointer++;
            arr2Pointer++;
        }
    }
    
    while(arr1Pointer < arr1.size())
    {
        mergedVector.push_back(arr1[arr1Pointer]);
        arr1Pointer++;
    }
    
    while(arr2Pointer < arr2.size())
    {
        mergedVector.push_back(arr2[arr2Pointer]);
        arr2Pointer++;
    }
    
    return mergedVector;
}
