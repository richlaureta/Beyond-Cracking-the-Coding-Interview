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

#endif // HEADER_HPP
