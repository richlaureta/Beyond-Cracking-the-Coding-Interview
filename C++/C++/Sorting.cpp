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
    
    priority_queue<pair<int,char>,  vector<pair<int, char>>, greater<pair<int, char>>> maxHeap;
    
    for(auto key: letterFrequencyMap) maxHeap.push({-letterFrequencyMap[key.first], key.first});
    
    vector<char> sortedLetterByFrequencyVector;
    
    int maxHeapSize = (int) maxHeap.size();
    
    for(int index = 0; index < maxHeapSize; index++)
    {
        char letter = maxHeap.top().second;
        maxHeap.pop();
        sortedLetterByFrequencyVector.push_back(letter);
    }
    
    return sortedLetterByFrequencyVector;
}
