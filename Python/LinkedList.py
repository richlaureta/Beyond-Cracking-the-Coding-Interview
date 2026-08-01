class Node:
    #Problem #34.1 - Singly Linked List Design
    
    def __init__(self, v = None):
        self.v = v
        self.next = None
    
class SinglyLinkedList:
    #Problem 34.1 - Singly Linked List Design
    
    def __init__(self):
        self.head = None
        self.size = 0
        
    def push_front(self, v):
        if self.head == None:
            self.head = Node(v)
        else:
            new_head = Node(v)
            new_head.next = self.head
            self.head = new_head
        
        self.size += 1
    
    def pop_front(self) -> int:
        if self.head == None:
            return None
        else:
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
  
    def pop_back(self) -> int:
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
    
    def _size(self) -> int:
        return self.size
    
    def contains(self, v) -> Node:        
        current_node = self.head
        
        while True:
            if current_node == None:
                return None
            if current_node.v == v:
                return current_node
            
            current_node = current_node.next

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

#ALL TESTS
def Run_All_Linked_Lists_Tests():
    run_singly_linked_list_design_tests()
    
    print()
    print("---------------------------------------------------------")
    print("ALL INCLUDED LINKED LIST TESTS IN THE FILE HAVE PASSED. |")
    print("---------------------------------------------------------")
    
if __name__ == "__main__":
    Run_All_Linked_Lists_Tests()