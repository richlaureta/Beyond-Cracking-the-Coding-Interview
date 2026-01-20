//
//  DynamicArray.cpp
//  C++
//
//  Created by Richmond Laureta on 1/19/26.
//

#include "Header.hpp"

DynamicArray::DynamicArray()
{
    _capacity = 10;
    _size = 0;
    fixedArray = new int[_capacity]();
}

DynamicArray::~DynamicArray()
{
    delete[]fixedArray;
}

DynamicArray::DynamicArray(const DynamicArray &other)
{
    _capacity = other._capacity;
    _size = other._size;
    fixedArray = new int[_capacity];
    
    for(int index = 0; index < _size; index++)
    {
        fixedArray[index] = other.fixedArray[index];
    }
}

int DynamicArray::get(int index) const
{
    if(index < 0 or index >= _size)
    {
        throw out_of_range("Index out of bounds.");
    }
    
    return fixedArray[index];
}

void DynamicArray::set(int index, int number)
{
    if(index < 0 or index >= _size)
    {
        throw out_of_range("Index out of bounds.");
    }
    
    fixedArray[index] = number;
}

int DynamicArray::size() const
{
    return _size;
}

void DynamicArray::resizeIncrease()
{
    _capacity *= 2;
    
    int *temporaryFixedArray = new int[_capacity]();
    
    for(int index = 0; index < _size; index++)
    {
        temporaryFixedArray[index] = fixedArray[index];
    }
    
    delete[] fixedArray;
    fixedArray = temporaryFixedArray;
    
}

void DynamicArray::append(int number)
{
    if(_size == capacity()) resizeIncrease();
    
    fixedArray[_size] = number;
    
    _size++;
}

void DynamicArray::resizeDecrease()
{
    _capacity = round(_capacity/2);
    
    int *temporaryFixedArray = new int[_capacity]();
    
    for(int index = 0; index < _size; index++)
    {
        temporaryFixedArray[index] = fixedArray[index];
    }
    
    delete[] fixedArray;
    fixedArray = temporaryFixedArray;
    
}

void DynamicArray::popBack()
{
    if(_size == 0)
    {
        throw out_of_range("Dynamic Array is empty.");
    }
    
    _size--;
    if(_size * 4 < _capacity and _capacity > 10) resizeDecrease();
}

int DynamicArray::capacity() const
{
    return _capacity;
}

int DynamicArray::pop(int index)
{
    if(index < 0 or index >= _size)
    {
        if(_size == 0) throw out_of_range("The dynamic array is empty.");
        
        throw out_of_range("Index is out of bounds.");
    };
    
    int poppedNumber = fixedArray[index];
    
    for(int index1 = index; index1 < _size; index1++)
    {
        fixedArray[index1] = fixedArray[index1 + 1];
    }
    
    _size--;
    
    return poppedNumber;
}

bool DynamicArray::contains(int digit)
{
    for(int index = 0; index < _size; index++)
    {
        if(digit == fixedArray[index])
        {
            return true;
        }
    }
    
    return false;
}

void DynamicArray::insert(int i, int element)
{
    if(i < 0 or i >= _size)
    {
        throw out_of_range("Index is out of bounds.");
    }
    
    int *temporaryArray = new int[_size - i - 1];
    
    int temporaryIndex = 0;
    for(int index = i; index < _size; index++)
    {
        temporaryArray[temporaryIndex] = fixedArray[index];
        temporaryIndex++;
    }
    
    fixedArray[i] = element;
    
    if(_size == capacity()) resizeIncrease();
    
    int temporaryIndex1 = 0;
    for(int index1 = i + 1; index1 < _size + 1; index1++)
    {
        fixedArray[index1] = temporaryArray[temporaryIndex1];
        temporaryIndex1++;
    }
    
    _size++;
}

int DynamicArray::remove(int element)
{
    for(int i = 0; i < _size; i++)
    {
        if(element == fixedArray[i])
        {
            pop(i);
            return i;
        }
    }
    
    return -1;
}
