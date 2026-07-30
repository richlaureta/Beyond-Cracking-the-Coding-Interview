//
//  Header.hpp
//  C++
//
//  Created by Richmond Laureta on 1/16/26.
//
#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_set>
#include <cmath>
#include <tuple>
#include <vector>
#include <climits>
#include <limits>
#include <algorithm>
#include <random>
#include <stack>
#include <span>
#include <deque>
#include <charconv>
#include <system_error>

using namespace std;

//Dynamic Array Questions
class DynamicArray
{
private:
    int* fixedArray;
    int _capacity;
    int _size;
    
public:
    DynamicArray();
    ~DynamicArray();
    
    //Copy Constructor
    DynamicArray(const DynamicArray &other);
    
    //Functions
    int get(int index) const;
    void set(int index, int number);
    int size() const;
    void append(int number);
    void resizeIncrease();
    void resizeDecrease();
    void popBack();
    
    //Extra added functions
    int pop(int index);
    bool contains(int number);
    void insert(int index1, int element);
    int remove(int element);
    
    //Added for testing
    int capacity() const ;
};

//String Manipulation
vector<string> split(const string &s, char c);
bool isLowerCase(char c);
bool isUpperCase(char c);
bool isDigit(char c);
bool isAlphaNumeric(char c);
string join(const vector<string> &arr, const string &s);
int indexOf(const string &s, const string &t);
int strStr(string haystack, string needle);

//Two Pointers
bool palindrome(string s);
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2);
bool palindromicSentence(const string &s);
bool reverseCaseMatch(const string &s);
vector<int> merge(const vector<int> &arr1, const vector<int> &arr2);
bool twoSum(const vector<int> &arr);
vector<int> threeWayMerge(const vector<int> &arr1, const vector<int> &arr2, const vector<int> &arr3);
vector<int> sortValleyArray(const vector<int> &arr);
vector<int> missingNumbers(const vector<int> &arr, int low, int high);
vector<vector<int>> intervalIntersection(const vector<vector<int>> &arr1, const vector<vector<int>> &arr2);
void reverse(vector<char> &arr);
bool isValidSolutionSortEven(const std::vector<int>& arr, const std::vector<int>& original);
void sortEven(vector<int> &arr);
int removeDuplicates(vector<int> &arr);
void partition(vector<int> &arr, int pivot);
bool isValidPartition(const vector<int> &arr, int pivot);
void sortColors(vector<char> &arr);
void swapPrefixSuffix(vector<char> &arr);
void moveWord(vector<char> &arr, const string &word);

//Grids and Matrices
vector<vector<int>> chessMoves(const vector<vector<int>> &board, const string &piece, int r, int c);
vector<vector<int>> safeCells(const vector<vector<int>> &board);
vector<vector<int>> spiral(int n);
int distanceToRiver(const vector<vector<int>> &field);
bool validSudoku(vector<vector<int>> board);
vector<vector<int>> subgridMaximums(const vector<vector<int>> &grid);
vector<vector<int>> subgridSums(const vector<vector<int>> &grid);
class MatrixOperations
{
private:
    vector<vector<double>> matrix;
public:
    MatrixOperations(const vector<vector<double>> &grid);
    
    void transpose();
    void reflectHorizontally();
    void reflectVertically();
    void rotateClockwise();
    void rotateCounterclockwise();
    const vector<vector<double>>& getMatrix() const;
};

//Binary Search
int searchInSortedArray(const vector<int> &arr, int target);
int valleyBottom(const vector<int> &arr);
vector<int> twoArrayTwoSum(const vector<int> &sortedArr, const vector<int> &unsortedArr);
bool targetCountDivisibleByK(const vector<int> &arr, int target, int k);
int raceOvertaking(const vector<int> &p1, const vector<int> &p2);
vector<int> searchInSortedGrid(const vector<vector<int>> &grid, int target);
int tideAerialView(const vector<vector<vector<int>>> &picture);

//Sets & Maps
string accountSharing(const vector<pair<string, string>> &connections);
string mostSharedAccount(const vector<pair<string, string>> &connections);
string mostFrequentOctet(const vector<string> &ips);
bool multiAccountCheating(const vector<pair<string, vector<string>>> &users);
class DomainResolver
{
private:
    unordered_map<string, unordered_set<string>> ipToDomainSetMap;
    unordered_map<string, unordered_set<string>> domainToSubdomainSetMap;
public:
    void registerDomain(string ip, string domain);
    void registerSubdomain(string domain, string subdomain);
    bool hasSubdomain(string ip, string domain, string subdomain);
};
vector<vector<int>> findSquared(const vector<int> &arr);
class Checker
{
private:
    string word;
    unordered_map<char, int> wordMapFrequency;
    
public:
    Checker(const string &word1);
    bool expandsInto(const string &word2);
    
};
struct Student
{
    int ID;
    int desk;
    vector<char> answers;
};
vector<vector<int>> suspectStudents(const vector<char> &answers, int m, const vector<Student> &students);
bool alphabeticSumProduct(const vector<string> &words, int target);
struct Action
{
    string agent;
    string action;
    int ticket;
    Action(string a, string act, int t);
};
vector<int> findAnomalies(const vector<Action> &log);
std::unordered_set<int> setIntersection(
    const std::unordered_set<int>& set1,
                                        const std::unordered_set<int>& set2);
int largestSetIntersectionPrefixSum(const std::vector<std::vector<int>>& sets);
int largestSetIntersectionFrequencyMap(const vector<vector<int>> &sets);

//Sorting
vector<char> letterOccurrencesLambda(const string &word);
vector<char> letterOccurrences(const string &word);
using Circle = pair<pair<double, double>, double>;
bool areCirclesNested(vector<Circle> &circles);
vector<int> processOperations(const vector<int> &nums, const vector<int> &operations);
class Spreadsheet
{
private:
    vector<vector<int>> spreadsheetTemplate;
public:
    Spreadsheet(int rows, int cols );
    void newSheet(int rows, int cols);
    void set(int row, int col, int value);
    int get(int row, int col);
    void sortColumnsByRow(int row);
    void sortRowsByColumn(int col);
};
class Book
{
public:
    string title;
    string author;
    int pageCount;
    string genre;
    int yearPublished;
    
    Book(string title, string author, int pageCount, string genre, int yearPublished);
};
vector<Book> bucketSort(const vector<Book> &books);
std::vector<int> firstKMinHeap(std::vector<int> arr, int k);
std::vector<int> firstKMaxHeap(const std::vector<int>& arr, int k);
std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> partition(
                                                                           const std::vector<int>& arr);
std::vector<int> firstKQuickselect(const std::vector<int>& arr, int k);
int quickselect(const std::vector<int>& arr, int k);
vector<int> firstKSorting(vector<int> arr, int k);

//Stacks & Queues
vector<int> compressArray(const vector<int> &arr);
class CompressArrayK
{
public:
    vector<int> solve(const vector<int> &arr, int k);
};
string currentUrl(const vector<pair<string, string>> &actions);
string currentUrlWithForward(const vector<pair<string, string>> &actions);
int maxBalancedPartition(const string &s);
bool customBrackets(const string &s, const vector<string> &brackets);
string longestBalancedSubsequence(const string &s);

//Recursion
void recursiveMoves(int index, const string &seq, vector<char> &joinedRobotInstructions);
string moves(const string &seq);
void recursionMaxLaminalSum(const vector<int> &arr, int raiseToThePower, int &maxSumOverhead);
int maxLaminalSum(const vector<int> &arr);

//Linked List
#endif // HEADER_HPP
