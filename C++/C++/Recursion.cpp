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
