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

vector<int> sortValleyArray(const vector<int> &arr)
{
    //Problem 27.9 Sort Valley-Shaped Array
    
    if((int)arr.size() == 1) return arr;
    
    int leftPointer = 0;
    int rightPointer = (int)arr.size() - 1;
    
    vector<int> sortedVector((int)arr.size());
    int indexVector = (int)arr.size() - 1;
    
    while(leftPointer <= rightPointer)
    {
        if(rightPointer - leftPointer == 1 or rightPointer - leftPointer == 0)
        {
            if(rightPointer == leftPointer)
            {
                sortedVector[indexVector] = arr[rightPointer];
                break;
            }
            
            if(arr[leftPointer] < arr[rightPointer])
            {
                sortedVector[indexVector] = arr[rightPointer];
                indexVector--;
                sortedVector[indexVector] = arr[leftPointer];
            }
            else
            {
                sortedVector[indexVector] = arr[leftPointer];
                indexVector--;
                sortedVector[indexVector] = arr[rightPointer];
            }
            
            break;
        }
        
        if(arr[leftPointer] > arr[rightPointer])
        {
            sortedVector[indexVector] = arr[leftPointer];
            leftPointer++;
            indexVector--;
        }
        else if(arr[rightPointer] > arr[leftPointer])
        {
            sortedVector[indexVector] = arr[rightPointer];
            rightPointer--;
            indexVector--;
        }
        else
        {
            sortedVector[indexVector] = arr[leftPointer];
            indexVector--;
            leftPointer++;
            sortedVector[indexVector] = arr[rightPointer];
            indexVector--;
            rightPointer--;
        }
    }
    
    return sortedVector;
}

vector<int> missingNumbers(const vector<int> &arr, int low, int high)
{
    //Problem 27.10 Missing Numbers in Range
    
    int leftPointer = 0;
    
    while(leftPointer < (int)arr.size() and arr[leftPointer] < low) leftPointer++;
    
    vector<int> missingNumbersVector = {};
    
    int startingRange = low;
    
    while(leftPointer < (int)arr.size() and startingRange < arr[leftPointer])
    {
        for(int index = startingRange; index < arr[leftPointer]; index++)
        {
            missingNumbersVector.push_back(startingRange);
        }
        startingRange = arr[leftPointer];
    }
    
    while(leftPointer < (int)arr.size() and startingRange < high)
    {
        int holdStartingValue = startingRange;
        for(int index = 0; index < arr[leftPointer] - holdStartingValue - 1; index++)
        {
            startingRange++;
            missingNumbersVector.push_back(startingRange);
        }
        
        if(startingRange < arr[leftPointer] and leftPointer == (int)arr.size())
        {
            for(int index = startingRange; index < arr[leftPointer]; index++) missingNumbersVector.push_back(index);
        }
        
        startingRange = arr[leftPointer];
        leftPointer++;
        
        if(leftPointer < (int)arr.size() and arr[leftPointer] > high)
        {
            for(int index = 0; index < high - startingRange; index++)
            {
                startingRange++;
                missingNumbersVector.push_back(startingRange);
            }
        }
        else if(leftPointer < (int)arr.size() and arr[leftPointer] == high)
        {
            for(int index = 0; index < high - startingRange - 1; index++)
            {
                startingRange++;
                missingNumbersVector.push_back(startingRange);
            }
        }
        else if(leftPointer >= (int)arr.size() and high > arr[(int)arr.size() - 1])
        {
            for(int index = arr[(int)arr.size() - 1] + 1; index < high + 1; index++)
            {
                startingRange++;
                missingNumbersVector.push_back(startingRange);
            }
        }
    }
    
    if((int)arr.size() == 0)
    {
        for(int index = low; index < high + 1; index++) missingNumbersVector.push_back(index);
    }
    
    return missingNumbersVector;
}

vector<vector<int>> intervalIntersection(const vector<vector<int>> &arr1, const vector<vector<int>> &arr2)
{
    //Problem 27.11 Interval Intersection
    
    int arr1Pointer = 0;
    int arr2Pointer = 0;
    
    vector<vector<int>> intervalOverlapVector = {};
    
    while(arr1Pointer < (int)arr1.size() and arr2Pointer < (int)arr2.size())
    {
        if(arr1[arr1Pointer][1] < arr2[arr2Pointer][0]) arr1Pointer++;
        
        if(arr1Pointer < (int)arr1.size() and arr1[arr1Pointer][0] > arr2[arr2Pointer][1]) arr2Pointer++;
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr1[arr1Pointer][1] < arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] < arr2[arr2Pointer][0])
        {
            intervalOverlapVector.push_back({arr2[arr2Pointer][0], arr1[arr1Pointer][1]});
            arr1Pointer++;
        }
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr1[arr1Pointer][1] < arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] > arr2[arr2Pointer][0])
        {
            intervalOverlapVector.push_back({arr1[arr1Pointer][0], arr1[arr1Pointer][1]});
            arr1Pointer++;
        }
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr1[arr1Pointer][1] > arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] < arr2[arr2Pointer][0])
        {
            intervalOverlapVector.push_back({arr2[arr2Pointer][0], arr2[arr2Pointer][1]});
            arr2Pointer++;
        }
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr2[arr2Pointer][0] == arr1[arr1Pointer][1])
        {
            intervalOverlapVector.push_back({arr1[arr1Pointer][1], arr2[arr2Pointer][0]});
            arr1Pointer++;
        }
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr2[arr2Pointer][1] == arr1[arr1Pointer][0])
        {
            intervalOverlapVector.push_back({arr2[arr2Pointer][1], arr1[arr1Pointer][0]});
            arr2Pointer++;
        }
        
        if (arr1Pointer < (int)arr1.size() and
            arr2Pointer < (int)arr2.size() and
            arr1[arr1Pointer][1] > arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] > arr2[arr2Pointer][0])
        {
            intervalOverlapVector.push_back({arr1[arr1Pointer][0], arr2[arr2Pointer][1]});
            arr2Pointer++;
        }
    }
    
    return intervalOverlapVector;
}

void reverse(vector<char> &arr)
{
    //Problem 27.12 Array Reversal
    
    int leftPointer = 0,  rightPointer = (int)arr.size() - 1;
    
    while(leftPointer < rightPointer)
    {
        swap(arr[leftPointer], arr[rightPointer]);
        leftPointer++;
        rightPointer--;
    }
}

bool isValidSolutionSortEven(const std::vector<int>& arr, const std::vector<int>& original) {
    // Check that we have the same elements
    
    //Problem 27.13 Parity Sorting TESTING
    auto arr_sorted = arr;
    auto original_sorted = original;
    std::sort(arr_sorted.begin(), arr_sorted.end());
    std::sort(original_sorted.begin(), original_sorted.end());
    if (arr_sorted != original_sorted) {
        return false;
    }
    
    // Find the boundary between even and odd numbers
    int boundary = 0;
    while (boundary < arr.size() && arr[boundary] % 2 == 0) {
        boundary++;
    }
    
    // Check that all numbers before boundary are even
    // and all numbers after are odd
    for (int i = 0; i < boundary; i++) {
        if (arr[i] % 2 != 0) {
            return false;
        }
    }
    for (int i = boundary; i < arr.size(); i++) {
        if (arr[i] % 2 != 1) {
            return false;
        }
    }
    return true;
}

void sortEven(vector<int> &arr)
{
    //Problem 27.13 Parity Sorting
    
    int index = 0, oddIndex = (int)arr.size() - 1;
    
    while(index < oddIndex)
    {
        if(arr[index] % 2 != 0)
        {
            while(oddIndex > 0 and arr[oddIndex] % 2 != 0) oddIndex--;
            if(oddIndex > index) swap(arr[index], arr[oddIndex]);
        }
        
        index++;
    }
}

int removeDuplicates(vector<int> &arr)
{
    //Problem 27.14 In-Place Duplicate Removal
    
    if((int)arr.size() == 0) return 0;
    
    int uniqueCount = 1;
    
    for(int index = 1; index < (int)arr.size(); index++)
    {
        if(arr[index] != arr[index - 1])
        {
            arr[uniqueCount] = arr[index];
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}

bool isValidPartition(const std::vector<int>& arr, int pivot) {
  // Find boundaries between sections
  int first = 0;
  while (first < arr.size() && arr[first] < pivot) {
    first++;
  }
  int second = first;
  while (second < arr.size() && arr[second] == pivot) {
    second++;
  }

  // Check that all elements are in their correct sections
  for (int i = 0; i < first; i++) {
    if (arr[i] >= pivot) {
      return false;
    }
  }
  for (int i = first; i < second; i++) {
    if (arr[i] != pivot) {
      return false;
    }
  }
  for (int i = second; i < arr.size(); i++) {
    if (arr[i] <= pivot) {
      return false;
    }
  }
  return true;
}

void partition(vector<int> &arr, int pivot)
{
    //Problem 27.15 Quicksort Partition
    
    int greaterThanPivotIndex = (int) arr.size() - 1;
    int index = 0;
    
    while(index < greaterThanPivotIndex)
    {
        if(arr[index] > pivot)
        {
            while(arr[greaterThanPivotIndex] > pivot) greaterThanPivotIndex--;
            swap(arr[index], arr[greaterThanPivotIndex]);
            greaterThanPivotIndex--;
        }
        
        index++;
    }
    
    int index1 = 0;
    int equalIndex = index - 1;
    
    while(index1 < equalIndex)
    {
        if(arr[index1] == pivot)
        {
            while(arr[equalIndex] == pivot) equalIndex--;
            swap(arr[index1], arr[equalIndex]);
            equalIndex--;
        }
        
        index1++;
    }
}
