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

bool twoSum(const vector<int> &arr)
{
    //Problem 27.7 2-Sum
    
    int leftPointer = 0;
    int rightPointer = (int)arr.size() - 1;
    
    while(leftPointer < rightPointer)
    {
        if(arr[leftPointer] + arr[rightPointer] < 0) leftPointer++;
        else if(arr[leftPointer] + arr[rightPointer] > 0) rightPointer--;
        else return true;
    }
    
    return false;
}

vector<int> threeWayMerge(const vector<int> &arr1, const vector<int> &arr2, const vector<int> &arr3)
{
    //Problem 27.8 Three-Way Merge Without Duplicates
    
    unordered_set<int> inThereSet;
    vector<int> uniqueVector;
    
    int arr1Pointer = 0;
    int arr2Pointer = 0;
    int arr3Pointer = 0;
    
    while(arr1Pointer < arr1.size() and arr2Pointer < arr2.size() and arr3Pointer < arr3.size())
    {
        if(arr1[arr1Pointer] < arr2[arr2Pointer] and arr1[arr1Pointer] < arr3[arr3Pointer])
        {
            if(inThereSet.find(arr1[arr1Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr1[arr1Pointer]);
                uniqueVector.push_back(arr1[arr1Pointer]);
            }
            arr1Pointer++;
            continue;
        }
        else if(arr2[arr2Pointer] < arr1[arr1Pointer] and arr2[arr2Pointer] < arr3[arr3Pointer])
        {
            if(inThereSet.find(arr2[arr2Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr2[arr2Pointer]);
                uniqueVector.push_back(arr2[arr2Pointer]);
            }
            arr2Pointer++;
            continue;
        }
        else if(arr3[arr3Pointer] < arr1[arr1Pointer] and arr3[arr3Pointer] < arr2[arr2Pointer])
        {
            if(inThereSet.find(arr3[arr3Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr3[arr3Pointer]);
                uniqueVector.push_back(arr3[arr3Pointer]);
            }
            arr3Pointer++;
            continue;
        }
        
        if(arr1[arr1Pointer] == arr2[arr2Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer])
        {
            if(inThereSet.find(arr1[arr1Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr1[arr1Pointer]);
                uniqueVector.push_back(arr1[arr1Pointer]);
            }
            arr1Pointer++;
            arr2Pointer++;
            arr3Pointer++;
        }
        else if(arr1[arr1Pointer] < arr2[arr2Pointer] and arr2[arr2Pointer] == arr3[arr3Pointer])
        {
            if(inThereSet.find(arr1[arr1Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr1[arr1Pointer]);
                uniqueVector.push_back(arr1[arr1Pointer]);
            }
            arr1Pointer++;
        }
        else if(arr2[arr2Pointer] < arr1[arr1Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer])
        {
            if(inThereSet.find(arr2[arr2Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr2[arr2Pointer]);
                uniqueVector.push_back(arr2[arr2Pointer]);
            }
            arr2Pointer++;
        }
        else if(arr3[arr3Pointer] < arr1[arr1Pointer] and arr1[arr1Pointer] == arr2[arr2Pointer])
        {
            if(inThereSet.find(arr3[arr3Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr3[arr3Pointer]);
                uniqueVector.push_back(arr3[arr3Pointer]);
            }
            arr3Pointer++;
        }
        else if(arr1[arr1Pointer] < arr3[arr3Pointer] and arr1[arr1Pointer] == arr2[arr2Pointer])
        {
            if(inThereSet.find(arr1[arr1Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr1[arr1Pointer]);
                uniqueVector.push_back(arr1[arr1Pointer]);
            }
            arr1Pointer++;
            arr2Pointer++;
        }
        else if(arr1[arr1Pointer] < arr2[arr2Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer])
        {
            if(inThereSet.find(arr1[arr1Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr1[arr1Pointer]);
                uniqueVector.push_back(arr1[arr1Pointer]);
            }
            arr1Pointer++;
            arr3Pointer++;
        }
        else if(arr2[arr2Pointer] < arr1[arr1Pointer] and arr2[arr2Pointer] == arr3[arr3Pointer])
        {
            if(inThereSet.find(arr2[arr2Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr2[arr2Pointer]);
                uniqueVector.push_back(arr2[arr2Pointer]);
            }
            arr2Pointer++;
            arr3Pointer++;
        }
        else if(arr2[arr2Pointer] < arr3[arr3Pointer] and arr2[arr2Pointer] == arr1[arr1Pointer])
        {
            if(inThereSet.find(arr2[arr2Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr2[arr2Pointer]);
                uniqueVector.push_back(arr2[arr2Pointer]);
            }
            arr1Pointer++;
            arr2Pointer++;
        }
        else if(arr3[arr3Pointer] < arr1[arr1Pointer] and arr3[arr3Pointer] == arr2[arr2Pointer])
        {
            if(inThereSet.find(arr3[arr3Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr3[arr3Pointer]);
                uniqueVector.push_back(arr3[arr3Pointer]);
            }
            arr2Pointer++;
            arr3Pointer++;
        }
        else if(arr3[arr3Pointer] < arr2[arr2Pointer] and arr3[arr3Pointer] == arr1[arr1Pointer])
        {
            if(inThereSet.find(arr3[arr3Pointer]) == inThereSet.end())
            {
                inThereSet.insert(arr3[arr3Pointer]);
                uniqueVector.push_back(arr3[arr3Pointer]);
            }
            arr1Pointer++;
            arr3Pointer++;
        }
    }
    
    int pointer1 = 0;
    int pointer2 = 0;
    
    vector<int> vector1 = {};
    vector<int> vector2 = {};
    
    if(arr1Pointer > (int)arr1.size() - 1)
    {
        pointer1 = arr2Pointer;
        pointer2 = arr3Pointer;
        vector1 = arr2;
        vector2 = arr3;
    }
    else if(arr2Pointer > (int)arr2.size() - 1)
    {
        pointer1 = arr1Pointer;
        pointer2 = arr3Pointer;
        vector1 = arr1;
        vector2 = arr3;
    }
    else if(arr3Pointer > (int)arr3.size() - 1)
    {
        pointer1 = arr1Pointer;
        pointer2 = arr2Pointer;
        vector1 = arr1;
        vector2 = arr2;
    }
    
    while(pointer1 < vector1.size() and pointer2 < vector2.size())
    {
        if(vector1[pointer1] < vector2[pointer2])
        {
            if(inThereSet.find(vector1[pointer1]) == inThereSet.end())
            {
                inThereSet.insert(vector1[pointer1]);
                uniqueVector.push_back(vector1[pointer1]);
            }
            pointer1++;
        }
        else if(vector2[pointer2] < vector1[pointer1])
        {
            if(inThereSet.find(vector2[pointer2]) == inThereSet.end())
            {
                inThereSet.insert(vector2[pointer2]);
                uniqueVector.push_back(vector2[pointer2]);
            }
            pointer2++;
        }
        else
        {
            if(inThereSet.find(vector1[pointer1]) == inThereSet.end())
            {
                inThereSet.insert(vector1[pointer1]);
                uniqueVector.push_back(vector1[pointer1]);
            }
            pointer1++;
            pointer2++;
        }
    }
    
    while(pointer1 < vector1.size())
    {
        if(inThereSet.find(vector1[pointer1]) == inThereSet.end())
        {
            inThereSet.insert(vector1[pointer1]);
            uniqueVector.push_back(vector1[pointer1]);
        }
        pointer1++;
    }
    
    while(pointer2 < vector2.size())
    {
        if(inThereSet.find(vector2[pointer2]) == inThereSet.end())
        {
            inThereSet.insert(vector2[pointer2]);
            uniqueVector.push_back(vector2[pointer2]);
        }
        pointer2++;
    }
    
    return uniqueVector;
}
