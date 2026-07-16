//
//  Stacks&Queues.cpp
//  C++
//
//  Created by Richmond Laureta on 7/15/26.
//

#include "Header.hpp"

vector<int> compressArray(const vector<int> &arr)
{
    //Problem 32.1 - Compress Array
    
    if(arr.empty()) return {};
    
    vector<int> numberStack;
    numberStack.push_back(arr[0]);
    
    for(int number: span(arr).subspan(1))
    {
        if(number == numberStack.back())
        {
            int poppedNumber = numberStack.back();
            numberStack.pop_back();
            while(!numberStack.empty() and numberStack.back() == poppedNumber * 2)
            {
                poppedNumber = numberStack.back();
                numberStack.pop_back();
            }
            
            numberStack.push_back(poppedNumber * 2);
            
            continue;
        }
        
        numberStack.push_back(number);
    }
    return numberStack;
}
