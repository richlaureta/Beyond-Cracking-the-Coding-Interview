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

Spreadsheet::Spreadsheet(int rows, int cols)
{
    //Problem 31.4 - Spreadsheet
    
    spreadsheetTemplate = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Spreadsheet::newSheet(int rows , int cols)
{
    //Problem 31.4 - Spreadsheet
    
    if(rows < 1 or rows > 100 or cols < 1 or cols > 100) throw invalid_argument("Rows and columns have to be more than 0 and less than 101.");
    
    spreadsheetTemplate = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Spreadsheet::set(int row, int col, int value)
{
    //Problem 31.4 - Spreadsheet
    
    if(spreadsheetTemplate.empty()) throw invalid_argument("You have to set a new matrix template using the newSheet() function.");
    
    if(row < 0 or row > (int) spreadsheetTemplate.size() - 1 or col < 0 or col > (int) spreadsheetTemplate[0].size() - 1)
    {
        throw invalid_argument("row value or col value are out of range.");
    }
    
    spreadsheetTemplate[row][col] = value;
}

int Spreadsheet::get(int row, int col)
{
    //Problem 31.4 Spreadsheet
    
    if(spreadsheetTemplate.empty()) throw invalid_argument("You have to set a new matrix template using the newSheet() function.");
    
    if(row < 0 or row > (int) spreadsheetTemplate.size() - 1 or col < 0 or col > (int) spreadsheetTemplate[0].size() - 1)
    {
        throw invalid_argument("row value or col value are out of range.");
    }
    
    return spreadsheetTemplate[row][col];
}

void Spreadsheet::sortColumnsByRow(int row)
{
    //Problem 31.4 - Spreadsheet
    
    if(spreadsheetTemplate.empty()) throw invalid_argument("You have to set a new matrix template using the newSheet() function.");
    
    if(row < 0 or row > (int) spreadsheetTemplate.size() - 1)
    {
        throw invalid_argument("row value out of range.");
    }
    
    vector<pair<int, int>> columnSortList = {};
    for(int index = 0; index < (int) spreadsheetTemplate[row].size(); index++) columnSortList.push_back({spreadsheetTemplate[row][index], index});
    
    sort(columnSortList.begin(), columnSortList.end());
    
    vector<vector<int>> temporaryCopySpreadsheet = spreadsheetTemplate;
    
    int columnIndex = 0;
    for(pair<int, int> valueIndex: columnSortList)
    {
        for(int index1 = 0; index1 < (int) spreadsheetTemplate.size(); index1++)
        {
            spreadsheetTemplate[index1][columnIndex] = temporaryCopySpreadsheet[index1][valueIndex.second];
        }
        columnIndex++;
    }
}

void Spreadsheet::sortRowsByColumn(int col)
{
    //Problem 31.4  - Spreadsheet
    
    if(spreadsheetTemplate.empty()) throw invalid_argument("You have to set a new matrix template using the newSheet() function.");
    
    if(col < 0 or col > (int) spreadsheetTemplate[0].size() - 1)
    {
        throw invalid_argument("col value out of range.");
    }
    
    vector<pair<int, int>> rowSortList = {};
    for(int index = 0; index < (int) spreadsheetTemplate.size(); index++) rowSortList.push_back({spreadsheetTemplate[index][col], index});
    
    sort(rowSortList.begin(), rowSortList.end());
    
    vector<vector<int>> temporaryCopySpreadsheet = spreadsheetTemplate;
    
    int rowIndex = 0;
    for(pair<int, int> valueIndex: rowSortList)
    {
        for(int index1 = 0; index1 < (int) spreadsheetTemplate[valueIndex.second].size(); index1++)
        {
            spreadsheetTemplate[rowIndex][index1] = temporaryCopySpreadsheet[valueIndex.second][index1];
        }
        rowIndex++;
    }
}
