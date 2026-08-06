class Node:
    #Problem #34.1 - Singly Linked List Design
    
    def __init__(self, v = None):
        self.v = v
        self.previous = None
        self.next = None

class SinglyLinkedList:
    #Problem 34.1 - Singly Linked List Design
    
    def __init__(self):
        self.head = None
        self.size = 0
        
    def push_front(self, v):
        new_head = Node(v)
        new_head.next = self.head
        self.head = new_head
        
        self.size += 1
    
    def pop_front(self):
        if self.head == None:
            return None
        
        returned_value = self.head.v
        self.head = self.head.next
        self.size -= 1
        return returned_value
 
    def push_back(self, v):
        if self.head == None:
            self.head = Node(v)
        else:
            current_node = self.head
            while current_node.next:
                current_node = current_node.next
            
            current_node.next = Node(v)
        
        self.size += 1
  
    def pop_back(self):
        if self.head == None:
            return None
        
        if self.head.next == None:
            returned_value = self.head.v
            self.head = None
            self.size -= 1
            return returned_value
        
        current_node = self.head
        
        while current_node.next.next:
            current_node = current_node.next
        
        returned_value = current_node.next.v
        
        current_node.next = None
        
        self.size -= 1
        
        return returned_value
    
    def _size(self):
        return self.size
    
    def contains(self, v) -> Node:        
        current_node = self.head
        
        while True:
            if current_node == None:
                return None
            if current_node.v == v:
                return current_node
            
            current_node = current_node.next

class DoublyLinkedList:
    #Problem 34.2 - Doubly Linked List Design
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.size_ = 0
    
    def push_front(self, val):
        front_node = Node(val)
        front_node.next = self.head
        if self.head:
            self.head.previous = front_node
        else:
            self.tail = front_node
            
        self.head = front_node
        self.size_ += 1
    
    def pop_front(self):
        returned_value = None
                
        if self.head and self.head == self.tail:
            returned_value = self.head.v
            self.head = None
            self.tail = None
            self.size_ -= 1
            return returned_value
        
        if self.head:
            returned_value = self.head.v
            self.head = self.head.next
            if self.head:
                self.head.previous = None
            self.size_ -= 1

        return returned_value
    
    def push_back(self, v):
        add_node = Node(v)
        
        if not self.tail:
            self.head = add_node
            self.tail = add_node
            self.size_ += 1
            return
        
        previous_tail = self.tail
        self.tail.next = add_node
        self.tail = add_node
        add_node.previous = previous_tail
        self.size_ += 1
    
    def pop_back(self):
        return_value = None
        
        if self.tail:
            return_value = self.tail.v
            self.tail = self.tail.previous
            
            if self.tail:
                self.tail.next = None
            else:
                self.head = None
                
            self.size_ -= 1
            
        return return_value
    
    def size(self):
        return self.size_
    
    def contains(self, v) -> Node:
        current_node = self.head
        
        while current_node:
            if current_node.v == v:
                return current_node
            
            current_node = current_node.next

        return current_node

class LinkedListStack:
    #Problem 34.3 - Linked-List-Based Stack
    
    def __init__(self):
        self.head = None
        self.size_ = 0
        
    def push(self, v):
        new_head = Node(v)
        
        new_head.next = self.head
        self.head = new_head
        
        self.size_ += 1
        
    def pop(self):
        return_value = None
        
        if self.head:
            return_value = self.head.v
            self.head = self.head.next
            self.size_ -= 1
        
        return return_value
    
    def peek(self):
        return_value = None
        
        if self.head:
            return_value = self.head.v
        
        return return_value
    
    def size(self):
        return self.size_
    
    def empty(self) -> bool:
        return self.size_ == 0
    
#TESTS

def run_singly_linked_list_design_tests():
    sll = SinglyLinkedList()
    
    # Test size on empty list
    assert sll._size() == 0, f"\nsize(): got: {sll.size()}, want: 0\n"

	# Test pop_front on empty list
    assert sll.pop_front() is None, "\npop_front() on empty list should return None\n"

	# Test pop_back on empty list
    assert sll.pop_back() is None, "\npop_back() on empty list should return None\n"

	# Test push_front and size
    sll.push_front(10)
    assert sll._size() == 1, f"\nsize(): got: {sll.size()}, want: 1\n"

	# Test push_back and size
    sll.push_back(20)
    assert sll._size() == 2, f"\nsize(): got: {sll.size()}, want: 2\n"

	# Test contains
    assert sll.contains(10) is not None, "\ncontains(10) should find the node\n"
    assert sll.contains(30) is None, "\ncontains(30) should not find the node\n"

	# Test pop_front
    assert sll.pop_front() == 10, "\npop_front() should return 10\n"
    assert sll._size() == 1, f"\nsize(): got: {sll.size()}, want: 1\n"

	# Test pop_back
    assert sll.pop_back() == 20, "\npop_back() should return 20\n"
    assert sll._size() == 0, f"\nsize(): got: {sll.size()}, want: 0\n"

	# Test push_back and pop_back
    sll.push_back(30)
    assert sll.pop_back() == 30, "\npop_back() should return 30\n"

	# Test push_front and pop_front
    sll.push_front(40)
    assert sll.pop_front() == 40, "\npop_front() should return 40\n"
    
    del sll
    
    print("ALL SINGLY LINKED LIST DESIGN TESTS PROVIDED HAVE PASSED.")

def run_doubly_linked_list_design_tests():
    dll = DoublyLinkedList()

    # Test size on empty list
    assert dll.size() == 0, f"\nsize(): got: {dll.size()}, want: 0\n"

    # Test pop_front on empty list
    assert dll.pop_front() is None, "\npop_front() on empty list should return None\n"

    # Test pop_back on empty list
    assert dll.pop_back() is None, "\npop_back() on empty list should return None\n"

    # Test push_front and size
    dll.push_front(10)
    assert dll.size() == 1, f"\nsize(): got: {dll.size()}, want: 1\n"

    # Test push_back and size
    dll.push_back(20)
    assert dll.size() == 2, f"\nsize(): got: {dll.size()}, want: 2\n"

    # Test contains
    assert dll.contains(10) is not None, "\ncontains(10) should find the node\n"
    assert dll.contains(30) is None, "\ncontains(30) should not find the node\n"

    # Test pop_front
    assert dll.pop_front() == 10, "\npop_front() should return 10\n"
    assert dll.size() == 1, f"\nsize(): got: {dll.size()}, want: 1\n"

    # Test pop_back
    assert dll.pop_back() == 20, "\npop_back() should return 20\n"
    assert dll.size() == 0, f"\nsize(): got: {dll.size()}, want: 0\n"

    # Test push_back and pop_back
    dll.push_back(30)
    assert dll.pop_back() == 30, "\npop_back() should return 30\n"

    # Test push_front and pop_front
    dll.push_front(40)
    assert dll.pop_front() == 40, "\npop_front() should return 40\n"
    
    print("ALL DOUBLY LINKED LIST DESIGN TESTS PROVIDED HAVE PASSED.")

def run_linked_list_based_stack_tests():
    stack = LinkedListStack()

    # Test size on empty stack
    assert stack.size() == 0, f"\nsize(): got: {stack.size()}, want: 0\n"

    # Test pop on empty stack
    assert stack.pop() is None, "\npop() on empty stack should return None\n"

    # Test peek on empty stack
    assert stack.peek() is None, "\npeek() on empty stack should return None\n"

    # Test push and size
    stack.push(10)
    assert stack.size() == 1, f"\nsize(): got: {stack.size()}, want: 1\n"

    # Test peek
    assert stack.peek() == 10, "\npeek() should return 10\n"

    # Test push and pop
    stack.push(20)
    assert stack.pop() == 20, "\npop() should return 20\n"
    assert stack.size() == 1, f"\nsize(): got: {stack.size()}, want: 1\n"

    # Test empty
    assert not stack.empty(), "\nempty() should return False\n"
    stack.pop()
    assert stack.empty(), "\nempty() should return True\n"
    
    print("ALL LINKED-LIST-BASED STACK TESTS PROVIDED HAVE PASSED.")

#ALL TESTS

def Run_All_Linked_Lists_Tests():
    run_singly_linked_list_design_tests()
    run_doubly_linked_list_design_tests()
    run_linked_list_based_stack_tests()
    
    print()
    print("---------------------------------------------------------")
    print("ALL INCLUDED LINKED LIST TESTS IN THE FILE HAVE PASSED. |")
    print("---------------------------------------------------------")
    
if __name__ == "__main__":
    Run_All_Linked_Lists_Tests()