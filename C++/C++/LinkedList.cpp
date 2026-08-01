//
//  LinkedList.cpp
//  C++
//
//  Created by Richmond Laureta on 7/31/26.
//

#include "Header.hpp"

Node::Node(int val) : val(val), next(nullptr){};

SinglyLinkedList::~SinglyLinkedList()
{
    //Problem 34.1 = Singly Linked List Design
    
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
}

SinglyLinkedList::SinglyLinkedList(): head(nullptr), size_(0){};

void SinglyLinkedList::pushFront(int val)
{
    //Problem 34.1 - Singly Linked List Design
    
    if(head == nullptr) head = new Node(val);
    else
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
    }
    
    size_++;
}

optional<int> SinglyLinkedList::popFront()
{
    //Problem 34.1 - Singly Linked List Design
    
    if(head == nullptr) return nullopt;
    else
    {
        int returnedValue = head->val;
        head = head->next;
        size_--;
        return returnedValue;
    }
}

void SinglyLinkedList::pushBack(int val)
{
    //Problem 34.1 - Singly Linked List Design
    
    if(head == nullptr) head = new Node(val);
    else
    {
        Node *currentNode = head;
        while(currentNode->next) currentNode = currentNode->next;
        currentNode->next = new Node(val);
    }
    
    size_++;
}

optional<int> SinglyLinkedList::popBack()
{
    //Problem 34.1 - Singly Linked List Design
    
    if(head == nullptr) return nullopt;
    
    if(head->next == nullptr)
    {
        int returnedValue = head->val;
        head = nullptr;
        size_--;
        return returnedValue;
    }
    
    Node *currentNode = head;
    
    while(currentNode->next->next) currentNode = currentNode->next;
    
    int returnedValue = currentNode->next->val;
    
    currentNode->next = nullptr;
    
    size_--;
    
    return returnedValue;
}

int SinglyLinkedList::size()
{
    //Problem 34.1 - Singly Linked List Design
    
    return size_;
}

Node* SinglyLinkedList::contains(int val)
{
    //Problem 34.1 - Singly Linked List Design
    
    Node* currentNode = head;
    
    while(true)
    {
        if(currentNode == nullptr) return nullptr;
        if(currentNode->val == val) return currentNode;
        currentNode = currentNode->next;
    }
}


