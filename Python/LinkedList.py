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

class LinkedListQueue:
    #Problem 34.4 - Linked-List-Based Queue
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.size_ = 0
    
    def push(self, v):
        new_node = Node(v)
        
        if not self.tail:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        
        self.size_ += 1
    
    def pop(self):
        return_value = None
        
        if self.head:
            return_value = self.head.v
            self.head = self.head.next
            self.size_ -= 1
        
        return return_value

    def peek(self):
        if self.head:
            return self.head.v
        
        return None
    
    def size(self):
        return self.size_
    
    def empty(self):
        return self.size_ == 0

def copy_list(head: Node):
    #Problem 34.5 - Linked-List Copy
    
    if not head:
        return head
    
    current_node = head.next
    copy_head = Node(head.v)
    previous_node = copy_head
    
    while current_node:
        new_node = Node(current_node.v)
        previous_node.next = new_node
        previous_node = new_node
        current_node = current_node.next

    return copy_head

def reverse_list(head: Node):
    #Problem 34.6 - Linked-List Reversal
    
    current_node = head
    previous_node = None
    
    while current_node:
        next_node = current_node.next
        current_node.next = previous_node
        previous_node = current_node
        current_node = next_node
    
    return previous_node

def reverse_section(head, left, right):
    #Problem 34.7 - Sublist Reversal
    
    index_counter = -1
    current_node = head
    behind_left_index_node = None
    
    while current_node and left - 1 != index_counter:
        behind_left_index_node = current_node
        current_node = current_node.next
        index_counter += 1
    
    if not current_node:
        return head
    
    reversed_right_most_node = current_node
    previous_node = current_node
    current_node = current_node.next
    
    while current_node and index_counter + 1 != right:
        next_node = current_node.next
        current_node.next = previous_node
        previous_node = current_node
        current_node = next_node
        index_counter += 1
    
    if behind_left_index_node:
        behind_left_index_node.next = previous_node
        
    reversed_right_most_node.next = current_node
    
    if left == 0:
        head = previous_node
    
    return head

def has_cycle(head: Node) -> bool:
    #Problem 34.8 - Linked-List Cycle Detection
    
    slow_pointer = head
    fast_pointer = head
    
    while fast_pointer and fast_pointer.next:
        slow_pointer = slow_pointer.next
        fast_pointer = fast_pointer.next.next
        
        if slow_pointer == fast_pointer:
            return True
    
    return False

def convert_to_array(node: Node) -> list:
    #Problem 34.9 - Doubly Linked List to Array
    
    if not node:
        return []
    
    current_node = node
    
    while current_node.previous:
        current_node = current_node.previous
    
    merged_array = []
    
    while current_node:
        merged_array.append(current_node.v)
        current_node = current_node.next
    
    return merged_array    

def get_middle(head: Node):
    #Problem 34.10 - Linked-List Midpoint
    
    if not head:
        return None
    
    slow_pointer = head
    fast_pointer = head
    
    while fast_pointer and fast_pointer.next:
        slow_pointer = slow_pointer.next
        fast_pointer = fast_pointer.next.next
    
    return slow_pointer.v

def remove_kth_node(head: Node, k: int):
    #Problem 34.11 - Remove Kth Node from the End
    
    if k < 1:
        return head
    
    if not head:
        return None
    
    current_node = head
    
    index_counter = 1
    while current_node and index_counter <= k:
        current_node = current_node.next
        index_counter += 1    
    
    if index_counter < k:
        return head
    
    if not current_node:
        return head.next
    
    begin_again_node = head

    while current_node.next:
        begin_again_node = begin_again_node.next
        current_node = current_node.next
        
    begin_again_node.next = begin_again_node.next.next
    
    return head
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

def run_linked_list_based_queue_tests():
    queue = LinkedListQueue()

    # Test size on empty queue
    assert queue.size() == 0, f"\nsize(): got: {queue.size()}, want: 0\n"

    # Test pop on empty queue
    assert queue.pop() is None, "\npop() on empty queue should return None\n"

    # Test push and size
    queue.push(10)
    assert queue.size() == 1, f"\nsize(): got: {queue.size()}, want: 1\n"

    # Test push and pop
    queue.push(20)
    assert queue.pop() == 10, "\npop() should return 10\n"
    assert queue.size() == 1, f"\nsize(): got: {queue.size()}, want: 1\n"

    # Test empty
    assert not queue.empty(), "\nempty() should return False\n"
    queue.pop()
    assert queue.empty(), "\nempty() should return True\n"

    print("ALL LINKED-LIST-BASED QUEUE TESTS PROVIDED HAVE PASSED.")

def run_linked_list_copy_tests():

  def linked_list_to_array(head):
    result = []
    current = head
    while current:
      result.append(current.v)
      current = current.next
    return result

  def array_to_linked_list(arr):
    dummy = Node(0)
    current = dummy
    for val in arr:
      current.next = Node(val)
      current = current.next
    return dummy.next
  
  # Test cases
  tests = [
      # Test empty list
      [],
      # Test single element list
      [1],
      # Test multiple elements list
      [1, 2, 3],
      # Test list with repeated values
      [1, 1, 1],
      # Test list with negative values
      [-1, -2, -3],
      # Test list with zero
      [0],
      # Test longer list
      [1, 2, 3, 4, 5],
      # Test list with mixed values
      [-1, 0, 1],
  ]

  for i, arr in enumerate(tests):
    head = array_to_linked_list(arr)

    # Test first copy_list function
    copied_head_1 = copy_list(head)
    got_1 = linked_list_to_array(copied_head_1)
    assert got_1 == arr, f"\nTest {
        i + 1} (copy_list 1): got: {got_1}, want: {arr}\n"

    # Test second copy_list function
    # copied_head_2 = copy_list_with_dummy(head)
    # got_2 = linked_list_to_array(copied_head_2)
    # assert got_2 == arr, f"\nTest {
    #     i + 1} (copy_list 2): got: {got_2}, want: {arr}\n"
    
  print("ALL LINKED-LIST COPY TESTS PROVIDED PASSED.")

def run_linked_list_reversal_tests():

  def linked_list_to_array(head):
    result = []
    current = head
    while current:
      result.append(current.v)
      current = current.next
    return result


  def array_to_linked_list(arr):
    dummy_head = Node(0)
    current = dummy_head
    for val in arr:
      current.next = Node(val)
      current = current.next
    return dummy_head.next

  # Test cases
  tests = [
      # Test empty list
      ([], []),
      # Test single element list
      ([1], [1]),
      # Test multiple elements list
      ([1, 2, 3], [3, 2, 1]),
      # Test list with repeated values
      ([1, 1, 1], [1, 1, 1]),
      # Test list with negative values
      ([-1, -2, -3], [-3, -2, -1]),
      # Test list with zero
      ([0], [0]),
      # Test longer list
      ([1, 2, 3, 4, 5], [5, 4, 3, 2, 1]),
      # Test list with mixed values
      ([-1, 0, 1], [1, 0, -1]),
  ]

  for i, (arr, expected) in enumerate(tests):
    head = array_to_linked_list(arr)
    reversed_head = reverse_list(head)
    got = linked_list_to_array(reversed_head)
    assert got == expected, f"\nTest {i + 1}: got: {got}, want: {expected}\n"
  
  print("ALL LINKED-LIST REVERSAL TESTS PROVIDED HAVE PASSED.")

def run_sublist_reversal_tests():

  def linked_list_to_array(head):
    result = []
    current = head
    while current:
      result.append(current.v)
      current = current.next
    return result


  def array_to_linked_list(arr):
    dummy = Node(0)
    current = dummy
    for val in arr:
      current.next = Node(val)
      current = current.next
    return dummy.next

  # Test cases
  tests = [
      # From book
      ([1, 2, 3, 4, 5], 1, 3, [1, 4, 3, 2, 5]),
      ([1, 2, 3, 4, 5], 2, 7, [1, 2, 5, 4, 3]),
      ([1, 2], 5, 6, [1, 2]),

      # Test empty list
      ([], 0, 1, []),
      # Test single element list
      ([1], 0, 1, [1]),
      # Test reversing entire list
      ([1, 2, 3], 0, 3, [3, 2, 1]),
      # Test reversing sublist with repeated values
      ([1, 1, 1, 2, 2], 1, 3, [1, 2, 1, 1, 2]),
      # Test reversing sublist with negative values
      ([-1, -2, -3, -4], 1, 3, [-1, -4, -3, -2]),
      # Test reversing sublist with zero
      ([0, 1, 2], 0, 1, [1, 0, 2]),
      # Test reversing sublist at the end
      ([1, 2, 3, 4, 5], 2, 4, [1, 2, 5, 4, 3]),
      # Test left beyond list length - should not modify
      ([1, 2, 3], 4, 5, [1, 2, 3]),
      # Test right beyond list length - reverse to end
      ([1, 2, 3], 1, 5, [1, 3, 2]),
  ]

  for i, (arr, left, right, expected) in enumerate(tests):
    head = array_to_linked_list(arr)
    reversed_head = reverse_section(head, left, right)
    got = linked_list_to_array(reversed_head)
    assert got == expected, f"\nTest {i + 1}: got: {got}, want: {expected}\n"
    
  print("ALL SUBLIST REVERSAL TESTS PROVIDED HAVE PASSED.")

def run_linked_list_cycle_detection_tests():

  # arr: non-empty array representing the linked list
  # final_pointer_index: index of the node that the last pointer's next pointer
  # should point to.
  # If final_pointer_index is -1, then the last pointer's next pointer should
  # point to null.
  #
  # Returns the head of the list
  def create_cyclic_list(arr, final_pointer_index):

    # Build list and store cycle start node
    dummy_head = Node(0)
    current = dummy_head
    cycle_start_node = None
    for i, val in enumerate(arr):
      current.next = Node(val)
      current = current.next
      if i == final_pointer_index:
        cycle_start_node = current

    # Create cycle if needed
    if cycle_start_node:
      current.next = cycle_start_node

    return dummy_head.next

  tests = [
      # Test: (list, final_pointer_index, want)

      # Single node no cycle
      ([1], -1, False),
      # Single node with cycle
      ([1], 0, True),
      # Multiple nodes with no cycle
      ([1, 2, 3, 4, 5], -1, False),
      # Multiple nodes all in a cycle
      ([1, 2, 3, 4, 5], 0, True),
      # Multiple nodes with cycle in the middle
      ([1, 2, 3, 4, 5], 2, True),
      # Multiple nodes with cycle at the end
      ([1, 2, 3, 4, 5], 4, True),
      # The length of the cycle is equal to the distance from the
      # head to the start of the cycle (both are 5)
      ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5, True),
      # The length of the cycle is greater than the distance from the
      # head to the start of the cycle
      ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 4, True),
      # The length of the cycle is less than the distance from the
      # head to the start of the cycle
      ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 6, True),
  ]

  for i, (arr, final_pointer_index, want) in enumerate(tests):
    head = create_cyclic_list(arr, final_pointer_index)
    got = has_cycle(head)

    if final_pointer_index == -1:
      cycle_desc = "no cycle"
    else:
      cycle_desc = f"cycle starting at index {final_pointer_index}"
    test_case_str = f"Test {i + 1}: has_cycle(list {arr} with {cycle_desc})"
    assert got == want, f"\n{test_case_str}: got: {got}, want: {want}"
  
  print("ALL LINKED-LIST CYCLE DETECTION TESTS PROVIDED PASSED.")

def run_doubly_linked_list_to_array_tests():

  def create_doubly_linked_list(arr):
    head = Node(arr[0])
    cur = head
    for val in arr[1:]:
      new_node = Node(val)
      cur.next = new_node
      new_node.previous = cur
      cur = new_node
    return head


  def node_at_index(head, index):
    cur = head
    for _ in range(index):
      cur = cur.next
    return cur

  tests = [
      # Examples from the book
      ([1, 2, 3, 4], 2),
      ([1, 2, 3, 4], 0),

      ([1, 2, 3, 4, 5], 0),
      ([1, 2, 3, 4, 5], 1),
      ([1, 2, 3, 4, 5], 2),
      ([1, 2, 3, 4, 5], 3),
      ([1, 2, 3, 4, 5], 4),
      # Test single node
      ([1], 0),
  ]

  for i, (arr, index) in enumerate(tests):
    head = create_doubly_linked_list(arr)
    node = node_at_index(head, index)
    got = convert_to_array(node)
    assert got == arr, f"\nTest {i + 1}: got: {got}, want: {arr}\n"
  
  print("ALL DOUBLY LINKED LIST TO ARRAY TESTS PROVIDED HAVE PASSED.")

def run_linked_list_midpoint_tests():

  def array_to_linked_list(arr):
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
      current.next = Node(val)
      current = current.next
    return head

  tests = [
      # Test single node
      ([10], 10),
      # Test two nodes
      ([10, 20], 20),
      # Test odd number of nodes
      ([10, 20, 30], 20),
      # Test even number of nodes
      ([10, 20, 30, 40], 30),
      # Test longer odd list
      ([10, 20, 30, 40, 50], 30),
      # Test longer even list
      ([10, 20, 30, 40, 50, 60], 40),
      # Test with negative values
      ([-10, -20, -30], -20),
      # Test with zeros
      ([0, 0, 0], 0),
  ]
  for i, (input_arr, want) in enumerate(tests):
    # Test the fast/slow pointer solution
    head = array_to_linked_list(input_arr)
    got = get_middle(head)
    assert got == want, f"\nTest {i + 1} (fast/slow): got: {got}, want: {want}\n"

    # # Test the two pass solution
    # got = get_middle_two_pass(head)
    # assert got == want, f"\nTest {i + 1} (two pass): got: {got}, want: {want}\n"

  print("ALL LINKED-LIST MIDPOINT TESTS PROVIDED HAVE PASSED.")

def run_remove_kth_node_from_the_end_tests():

  def linked_list_to_array(head):
    result = []
    current = head
    while current:
      result.append(current.v)
      current = current.next
    return result


  def array_to_linked_list(arr):
    if not arr:
      return None
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
      current.next = Node(val)
      current = current.next
    return head

  tests = [
      # Test single element list
      ([1], 1, []),
      # Test removing first element (k = length)
      ([1, 2, 3], 3, [2, 3]),
      # Test removing last element (k = 1)
      ([1, 2, 3], 1, [1, 2]),
      # Test removing middle element
      ([1, 2, 3], 2, [1, 3]),
      # Test longer list removing first
      ([1, 2, 3, 4, 5], 5, [2, 3, 4, 5]),
      # Test longer list removing last
      ([1, 2, 3, 4, 5], 1, [1, 2, 3, 4]),
      # Test longer list removing middle
      ([1, 2, 3, 4, 5], 3, [1, 2, 4, 5]),
      # Test with repeated values
      ([1, 1, 1], 2, [1, 1]),
      # Test with negative values
      ([-1, -2, -3], 2, [-1, -3]),
  ]

  for i, (arr, k, want) in enumerate(tests):
    # Test the fast/slow pointer solution
    result = remove_kth_node(array_to_linked_list(arr), k)
    got = linked_list_to_array(result)
    assert got == want, f"\nTest {
        i + 1} (fast/slow): remove_kth_node({arr}, {k}): got: {got}, want: {want}\n"

    # Test the two pass solution
    # result = remove_kth_node_two_pass(array_to_linked_list(arr), k)
    # got = linked_list_to_array(result)
    # assert got == want, f"\nTest {
    #     i + 1} (two pass): remove_kth_node_two_pass({arr}, {k}): got: {got}, want: {want}\n"
    
  print("ALL REMOVE KTH NODE FROM THE END TESTS PROVIDED HAVE PASSED.")

#ALL TESTS

def Run_All_Linked_Lists_Tests():
    run_singly_linked_list_design_tests()
    run_doubly_linked_list_design_tests()
    run_linked_list_based_stack_tests()
    run_linked_list_based_queue_tests()
    run_linked_list_copy_tests()
    run_linked_list_reversal_tests()
    run_sublist_reversal_tests()
    run_linked_list_cycle_detection_tests()
    run_doubly_linked_list_to_array_tests()
    run_linked_list_midpoint_tests()
    run_remove_kth_node_from_the_end_tests()
    
    print()
    print("---------------------------------------------------------")
    print("ALL INCLUDED LINKED LIST TESTS IN THE FILE HAVE PASSED. |")
    print("---------------------------------------------------------")
    
if __name__ == "__main__":
    Run_All_Linked_Lists_Tests()