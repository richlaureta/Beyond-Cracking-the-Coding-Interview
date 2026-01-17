//
//  main.cpp
//  Beyond Cracking the Coding Interview by Gayle Laakman McDowell
//
//  Created by Richmond Laureta on 1/16/26.
//

#include "Header.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
    //Problem 26.1 String Split
    
    vector<string> splitStrings = split("/home/./..//Documents/", '/');
    
    for(int index = 0; index < splitStrings.size(); index++)
    {
        cout << splitStrings[index] << endl;
    }
    
    return EXIT_SUCCESS;
}
