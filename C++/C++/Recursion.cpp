//
//  Recursion.cpp
//  C++
//
//  Created by Richmond Laureta on 7/27/26.
//

#include "Header.hpp"

void recursiveMoves(int index, const string &seq,vector<char> &characterVector)
{
    //Problem 33.1 - Robot Instructions
    if(index == (int) seq.size()) return;
    
    if(seq[index] == '2')
    {
        recursiveMoves(index + 1, seq, characterVector);
        recursiveMoves(index + 2, seq, characterVector);
    }
    else
    {
        characterVector.push_back(seq[index]);
        recursiveMoves(index + 1, seq, characterVector);
    }
}

string moves(const string &seq)
{
    //Problem 33.1 - Robot Instructions
    
    vector<char> characterVector;
    
    recursiveMoves(0, seq, characterVector);
    
    string joinedRobotInstructions(characterVector.begin(), characterVector.end());
    
    return joinedRobotInstructions;
}

void recursionMaxLaminalSum(const vector<int> &arr, int raiseToThePower, int &maxSumOverhead)
{
    //Problem 33.5 - Laminal Arrays
    
    if((int) arr.size() < (int) pow(2, raiseToThePower)) return;
    
    int divideElements = round((int) arr.size() / pow(2, raiseToThePower));
    
    int indexSegment = 0;
    while(indexSegment < (int) arr.size())
    {
        int sum = 0;
        int indexTracking = 0;
        for(int index = indexSegment; index < indexSegment + divideElements; index++)
        {
            sum += arr[index];
            indexTracking = index + 1;
        }
        
        indexSegment = indexTracking;
        maxSumOverhead = max(maxSumOverhead, sum);
    }
    
    recursionMaxLaminalSum(arr, raiseToThePower + 1, maxSumOverhead);
}

int maxLaminalSum(const vector<int> &arr)
{
    //Problem 33.5 - Laminal Arrays
    
    int maxSumOverhead = INT_MIN;
    
    recursionMaxLaminalSum(arr, 0, maxSumOverhead);
    
    return maxSumOverhead;
}
