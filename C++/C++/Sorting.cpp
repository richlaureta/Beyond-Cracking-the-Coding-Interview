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

bool areCirclesNested(vector<Circle> &circles)
{
    if((int) circles.size() == 1 or (int) circles.size() == 0) return true;
    
    sort(circles.begin(), circles.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    
    double previousX = circles[0].first.first;
    double previousY = circles[0].first.second;
    double previousRadius = abs(circles[0].second);
    
    for(int index = 1; index < (int) circles.size(); index++)
    {
        if(previousX + previousRadius >= circles[index].first.first + abs(circles[index].second)) return false;
        
        if(previousX - previousRadius <= circles[index].first.first - abs(circles[index].second)) return false;
        
        if(previousY + previousRadius >= circles[index].first.second + abs(circles[index].second)) return false;
        
        if(previousY - previousRadius <= circles[index].first.second - abs(circles[index].second)) return false;
        
        previousX = circles[index].first.first;
        previousY = circles[index].first.second;
        previousRadius = circles[index].second;
    }
    
    return true;
}

vector<int> processOperations(const vector<int> &nums, const vector<int> &operations)
{
    //Problem 31.3 - Delete Operations
    
    if((int) operations.size() == 0) return nums;
    
    vector<pair<int, int>> numberIndexVector = {};
    for(int index = 0; index < (int) nums.size(); index++) numberIndexVector.push_back({nums[index], index});
    
    sort(numberIndexVector.begin(), numberIndexVector.end());
    int minimumIndex = 0;
    unordered_set<int> removeIndexSet = {};
    
    for(int index = 0; index < (int) operations.size(); index++)
    {
        if(operations[index] == -1)
        {
            while(removeIndexSet.find(numberIndexVector[minimumIndex].second) != removeIndexSet.end()) minimumIndex++;
            removeIndexSet.insert(numberIndexVector[minimumIndex].second);
            minimumIndex++;
        }
        else removeIndexSet.insert(operations[index]);
    }
    
    vector<int> outputNumberVector = {};
    
    for(int index = 0; index < (int) nums.size(); index++)
    {
        if(removeIndexSet.find(index) == removeIndexSet.end()) outputNumberVector.push_back(nums[index]);
    }
    
    return outputNumberVector;
}
