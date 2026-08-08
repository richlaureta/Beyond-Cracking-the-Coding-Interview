//
//  LinkedList.cpp
//  C++
//
//  Created by Richmond Laureta on 7/31/26.
//

#include "Header.hpp"

Node::Node(int val) : val(val), previous(nullptr), next(nullptr){};

SinglyLinkedList::SinglyLinkedList(): head(nullptr), size_(0){};

SinglyLinkedList::~SinglyLinkedList()
{
    //Problem 34.1 = Singly Linked List Design
    
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}

void SinglyLinkedList::pushFront(int val)
{
    //Problem 34.1 - Singly Linked List Design
    
    Node *newHead = new Node(val);
    newHead->next = head;
    head = newHead;
    
    size_++;
}

optional<int> SinglyLinkedList::popFront()
{
    //Problem 34.1 - Singly Linked List Design
    
    if(head == nullptr) return nullopt;
    
    Node* temporaryNode = head;
    int returnedValue = head->val;
    head = head->next;
    delete temporaryNode;
    temporaryNode = nullptr;
    
    size_--;
    return returnedValue;
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
        delete head;
        head = nullptr;
        size_--;
        return returnedValue;
    }
    
    Node *currentNode = head;
    
    while(currentNode->next->next) currentNode = currentNode->next;
    
    int returnedValue = currentNode->next->val;
    
    delete currentNode->next;
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

DoublyLinkedList::DoublyLinkedList(): head(nullptr), tail(nullptr), size_(0){};

void DoublyLinkedList::pushFront(int val)
{
    //Problem 34.2 - Doubly Linked List Design
    
    Node* frontNode = new Node(val);
    frontNode->next = head;
    
    if(head) head->previous = frontNode;
    else tail = frontNode;
    
    head = frontNode;
    size_++;
}

optional<int> DoublyLinkedList::popFront()
{
    //Problem 34.2 - Doubly Linked List Design
    
    optional<int> returnValue = nullopt;
    
    if(head and head == tail)
    {
        returnValue = head->val;
        head = nullptr;
        tail = nullptr;
        size_--;
        
        return returnValue;
    }
    
    if(head)
    {
        returnValue = head->val;
        Node* deleteHead = head;
        head = head->next;
        delete deleteHead;
        deleteHead = nullptr;
        
        if(head) head->previous = nullptr;
        
        size_--;
    }
    
    return returnValue;
}

void DoublyLinkedList::pushBack(int val)
{
    //Problem 34.2 Doubly Linked List Design
    
    Node* addNode = new Node(val);
    
    if(!tail)
    {
        head = addNode;
        tail = addNode;
        size_++;
        return;
    }
    
    Node* previousTail = tail;
    tail->next = addNode;
    tail = addNode;
    addNode->previous = previousTail;
    
    size_++;
}

optional<int> DoublyLinkedList::popBack()
{
    //Problem 34.2 Doubly Linked List Design
    
    optional<int> returnValue = nullopt;
    
    if(tail)
    {
        returnValue = tail->val;
        Node* deleteTail = tail;
        tail = tail->previous;
        delete deleteTail;
        deleteTail = nullptr;
    
        if(tail) tail->next = nullptr;
        else head = nullptr;
        
        size_--;
    }
    
    return returnValue;
}

int DoublyLinkedList::size()
{
    //Problem 34.2 - Doubly Linked List Design
    
    return size_;
}

Node* DoublyLinkedList::contains(int val)
{
    //Problem 34.2 - Doubly Linked List Design
    
    Node* currentNode = head;
    
    while(currentNode)
    {
        if(currentNode->val == val) return currentNode;
        
        currentNode = currentNode->next;
    }
    
    return currentNode;
}

LinkedListStack::LinkedListStack() : head(nullptr), size_(0){};

LinkedListStack::~LinkedListStack()
{
    //Problem 34.3 - Linked-List-Based Stack
    
    Node* currentNode = head;
    
    while(currentNode)
    {
        Node* temporaryNode = currentNode;
        currentNode = currentNode->next;
        delete temporaryNode;
        temporaryNode = nullptr;
    }
}

void LinkedListStack::push(int v)
{
    //Problem 34.3 - Linked-List-Based Stack
    
    Node* newHead = new Node(v);
    
    newHead->next = head;
    head = newHead;
    
    size_++;
}

optional<int> LinkedListStack::pop()
{
    //Problem 34.3 - Linked-List-Based Stack
    
    optional<int> returnValue = nullopt;
    
    if(head)
    {
        returnValue = head->val;
        Node* deleteHead = head;
        head = head->next;
        delete deleteHead;
        deleteHead = nullptr;
        
        size_--;
    }
    
    return returnValue;
}

optional<int> LinkedListStack::peek()
{
    //Problem 34.3 - Linked-List-Based Stack
    
    optional<int> returnValue = nullopt;
    
    if(head) returnValue = head->val;
    
    return returnValue;
}

int LinkedListStack::size()
{
    //Problem 34.3 - Linked-List-Based Stack
    
    return size_;
}

bool LinkedListStack::empty()
{
    //Problem 33.3 - Linked-List-Based Stack
    
    return size_ == 0;
}
