//
//  BinarySearch.cpp
//  C++
//
//  Created by Richmond Laureta on 5/21/26.
//

#include "Header.hpp"

int searchInSortedArray(const vector<int> &arr, int target)
{
    //Problem 29.1 Search in Sorted Array
    
    int leftPointer = 0;
    int rightPointer = (int)arr.size() - 1;
    
    while(leftPointer <= rightPointer)
    {
        int middlePointer = (leftPointer + rightPointer) / 2;
        
        if(arr[middlePointer] == target) return middlePointer;
        else if(arr[leftPointer] == target) return leftPointer;
        else if(arr[rightPointer] == target) return rightPointer;
        
        if(arr[middlePointer] > target) rightPointer = middlePointer - 1;
        else leftPointer = middlePointer + 1;
    }
    
    return -1;
}

int valleyBottom(const vector<int> &arr)
{
    //Problem 29.3 Valley Bottom
    
    int leftPointer = 0;
    int rightPointer = (int) arr.size() - 1;
    
    while(true)
    {
        int middlePointer = (leftPointer + rightPointer) / 2;
        
        if(arr[leftPointer] <= arr[middlePointer] and arr[middlePointer] <= arr[rightPointer]) return arr[leftPointer];
        else if(arr[leftPointer] >= arr[middlePointer] and arr[middlePointer] >= arr[rightPointer]) return arr[rightPointer];
        
        if(arr[middlePointer] > arr[middlePointer + 1]) leftPointer = middlePointer;
        else rightPointer = middlePointer;
    }
}

vector<int> twoArrayTwoSum(const vector<int> &sortedArr, const vector<int> &unsortedArr)
{
    //Problem 29.4 2-Array 2-Sum
    
    for(int index = 0; index < (int) unsortedArr.size(); index++)
    {
        int leftPointer = 0;
        int rightPointer = (int) sortedArr.size() - 1;
        
        int targetNumber = 0 - unsortedArr[index];
        
        while(leftPointer <= rightPointer)
        {
            int middlePointer = (leftPointer + rightPointer) / 2;
            
            if(sortedArr[middlePointer] == targetNumber) return {middlePointer, index};
            else if(sortedArr[leftPointer] == targetNumber) return {leftPointer, index};
            else if(sortedArr[rightPointer] == targetNumber) return {rightPointer, index};
            
            if(sortedArr[middlePointer] < targetNumber) leftPointer = middlePointer + 1;
            else rightPointer = middlePointer - 1;
        }
    }
    
    return {-1, -1};
}
