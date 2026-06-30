//
//  Sorting.cpp
//  C++
//
//  Created by Richmond Laureta on 6/29/26.
//


#include "Header.hpp"

vector<char> letterOccurrencesLambda(const string& word)
{
    //Part of the 31.1 - Sorting by Frequency Problem Tests
    
    std::unordered_map<char, int> letterToCount;
      std::vector<char> res;
      for (char c : word) {
        if (!letterToCount.count(c)) {
          res.push_back(c);
        }
        letterToCount[c]++;
      }

      std::sort(res.begin(), res.end(),
                [&](char a, char b) {
                  if (letterToCount[a] != letterToCount[b]) {
                    return letterToCount[a] > letterToCount[b];
                  }
                  return a < b;
                });
      return res;
}

vector<char> letterOccurrences(const string &word)
{
    //Problem 31.1 - Sorting by Frequency
    
    unordered_map<char, int> letterFrequencyMap;
    
    for(char letter: word) letterFrequencyMap[letter]++;
    
    vector<pair<int, char>> willSortVector;
    
    for(auto key: letterFrequencyMap) willSortVector.push_back({-letterFrequencyMap[key.first], key.first});
    
    sort(willSortVector.begin(), willSortVector.end());
    
    vector<char> sortedLetterByFrequencyVector;
    
    int vectorSize = (int) willSortVector.size();
    
    for(int index = 0; index < vectorSize; index++)
    {
        sortedLetterByFrequencyVector.push_back(willSortVector[index].second);
    }
    
    return sortedLetterByFrequencyVector;
}
