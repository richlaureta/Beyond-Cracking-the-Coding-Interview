from collections import defaultdict
from collections import deque

class Node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Nary_Node:
    def __init__(self, kind, num, children):
        self.kind = kind
        self.num = num
        self.children = children

def longest_aligned_chain(root):
    #Problem 35.1 - Aligned Chain
    
    max_count_aligned_chain = [0]
    
    def recusion_aligned_chain(node: Node, depth_level = 0, chained_count = 0):
        if not node:
            return
        
        if node.val == depth_level:
            chained_count += 1
            max_count_aligned_chain[0] = max(max_count_aligned_chain[0], chained_count)
        else:
            chained_count = 0
        
        depth_level += 1
        recusion_aligned_chain(node.left, depth_level, chained_count)
        recusion_aligned_chain(node.right, depth_level, chained_count)
    
    recusion_aligned_chain(root)
    
    return max_count_aligned_chain[0]

def most_stacked(root: Node):
    #Problem 35.4 - Tree Layout

    max_stack_count = [0]
    coordinate_dictionary_count = defaultdict(int)
    
    def dfsStacked(node: Node, left_coordinate, right_coordinate):
        if not node:
            return
        
        coordinate_dictionary_count[(left_coordinate, right_coordinate)] += 1
        max_stack_count[0] = max(max_stack_count[0], coordinate_dictionary_count[(left_coordinate, right_coordinate)])
        
        dfsStacked(node.left, left_coordinate + 1, right_coordinate)
        dfsStacked(node.right, left_coordinate, right_coordinate + 1)
        
    dfsStacked(root, 0, 0)
    
    return max_stack_count[0]

def aligned_path(root: Node):
    #Problem 35.3 - Aligned Path
        
    node_list = []
    
    def dfs_traversal(node: Node, depth_level):
        if not node:
            return
        
        node_list.append((node, depth_level))
        
        dfs_traversal(node.left, depth_level + 1)
        dfs_traversal(node.right, depth_level + 1)
    
    dfs_traversal(root, 0)
    
    max_aligned_node_count = [0]
    
    def dfs_aligned_path(node: Node, depth_level, aligned_node_count):
        if not node or node.val != depth_level:
            return
        

        aligned_node_count += 1
        max_aligned_node_count[0] = max(aligned_node_count, max_aligned_node_count[0])

            
        dfs_aligned_path(node.left, depth_level + 1, aligned_node_count)
        dfs_aligned_path(node.right, depth_level + 1, aligned_node_count)
    
    max_aligned_path_count = 0
       
    for node_depth_level in node_list:
        max_aligned_node_count[0] = 0
        
        if node_depth_level[0].val == node_depth_level[1]:
            dfs_aligned_path(node_depth_level[0].left, node_depth_level[1] + 1, 0)
            max_left_aligned_node_count = max_aligned_node_count[0] + 1
            max_aligned_node_count[0] = 0
            dfs_aligned_path(node_depth_level[0].right, node_depth_level[1] + 1, 0)
            max_right_aligned_node_count = max_aligned_node_count[0]
            
            max_aligned_path_count = max(max_aligned_path_count, max_left_aligned_node_count + max_right_aligned_node_count)
        
    return max_aligned_path_count

def triangle_count(root: Node):
    #Problem 35.5 - Triangle Count
    
    if not root:
        return 0
    
    node_triangle_list = []
    node_dequeue = deque([root])
    
    while node_dequeue:
        popped_node = node_dequeue.popleft()
        
        if popped_node.left and popped_node.right:
            node_triangle_list.append(popped_node)
        
        if popped_node.left:
            node_dequeue.append(popped_node.left)
        
        if popped_node.right:
            node_dequeue.append(popped_node.right)
            
    triangle_count = 0
    for node in node_triangle_list:
        left_node = node.left
        right_node = node.right
        while left_node and right_node:
            triangle_count += 1
            left_node = left_node.left
            right_node = right_node.right
    
    return triangle_count

def invert(root: Node):
    #Problem 35.6 - Invert a Binary Tree
    
    if not root:
        return None
    
    node_dequeue = deque([root])
    
    while node_dequeue:
        popped_node = node_dequeue.popleft()
        
        left_node = popped_node.left
        right_node = popped_node.right
        
        if popped_node.left:
            node_dequeue.append(popped_node.left)
        popped_node.left = right_node
        
        if popped_node.right:
            node_dequeue.append(popped_node.right)
        popped_node.right = left_node
        
    return root

def evaluate(node: Nary_Node):
    #Problem 35.7 - Evaluate Expression Tree

    if node.kind == "num":
        return node.num
    elif node.kind == "sum":            
        sum = 0
        for child in node.children:
            sum += evaluate(child)
        return sum
    elif node.kind == "product":            
        product = 1
        for child in node.children:
            product *= evaluate(child)
        
        return product
    elif node.kind == "min":            
        minimum_number = float('inf')
        for child in node.children:
            minimum_number = min(minimum_number, evaluate(child))
        
        return minimum_number
    elif node.kind == "max":            
        maximum_number = float('-inf')
        for child in node.children:
            maximum_number = max(maximum_number, evaluate(child))
        
        return maximum_number
    
    raise ValueError("Invalid node kind.")

def left_view(root: Node):
    #Problem #35.8 - Left View
    
    if not root:
        return []
    
    node_dequeue = deque([(root , 0)])
    left_view_node_list = [root.val]
    depth_level_set = set()
    
    while node_dequeue:
        popped_node = node_dequeue.popleft()
        
        if popped_node[0].left:
            node_dequeue.append((popped_node[0].left, popped_node[1] + 1))
            if popped_node[1] + 1 not in depth_level_set:
                depth_level_set.add(popped_node[1] + 1)
                left_view_node_list.append(popped_node[0].left.val)
        
        if popped_node[0].right:
            node_dequeue.append((popped_node[0].right, popped_node[1] + 1))
            if popped_node[1] + 1 not in depth_level_set:
                depth_level_set.add(popped_node[1] + 1)
                left_view_node_list.append(popped_node[0].right.val)
        
    return left_view_node_list

def most_prolific_level(root: Node):
    #Problem 35.9 - Most Prolific Level
    
    if not root:
        return -1
    
    if not root.left and not root.right:
        return 0
    
    node_dequeue = deque([(root, 0)])
    depth_level_node_count_dictionary = defaultdict(int) 
    
    max_prolific_value = float('-inf')
    max_prolific_level = float('-inf')
    
    depth_level_set = set([-2, -1])
    
    popped_node = None
    while node_dequeue:
        popped_node = node_dequeue.popleft()
        depth_level_node_count_dictionary[popped_node[1]] += 1
        
        if popped_node[1] - 2 not in depth_level_set:
            prolific_value = depth_level_node_count_dictionary[popped_node[1] - 1]/depth_level_node_count_dictionary[popped_node[1] - 2]
                
            if prolific_value > max_prolific_value:
                max_prolific_value = prolific_value
                max_prolific_level = popped_node[1] - 2
            
            depth_level_set.add(popped_node[1] - 2)
                
        if popped_node[0].left:
            node_dequeue.append((popped_node[0].left, popped_node[1] + 1))
        
        if popped_node[0].right:
            node_dequeue.append((popped_node[0].right, popped_node[1] + 1))
    
    prolific_value = depth_level_node_count_dictionary[popped_node[1]] / depth_level_node_count_dictionary[popped_node[1] - 1]
    
    if prolific_value > max_prolific_value:
        max_prolific_value = prolific_value
        max_prolific_level = popped_node[1] - 1
            
    return max_prolific_level

def zig_zag_order(root: Node):
    #Problem 35.10 - Zig-zag Order
    
    if not root:
        return []
    
    zigzag_list = [root.val]
    depth_level_set = set([-1, 0])
    
    level_value_list_dictionary = defaultdict(list)
    node_level_deueue = deque([(root, 0)])
    
    popped_node_level = None
    while node_level_deueue:
        popped_node_level = node_level_deueue.popleft()
        level_value_list_dictionary[popped_node_level[1]].append(popped_node_level[0].val)
        
        if popped_node_level[1] - 1 not in depth_level_set:
            if (popped_node_level[1] - 1) % 2 == 0:
                for number in level_value_list_dictionary[popped_node_level[1] - 1]:
                    zigzag_list.append(number)
            else:
                for number in reversed(level_value_list_dictionary[popped_node_level[1] - 1]):
                    zigzag_list.append(number)
            
            depth_level_set.add(popped_node_level[1] - 1)
                    
        if popped_node_level[0].left:
            node_level_deueue.append((popped_node_level[0].left, popped_node_level[1] + 1))
            
        if popped_node_level[0].right:
            node_level_deueue.append((popped_node_level[0].right, popped_node_level[1] + 1))
    
    if popped_node_level[1] not in depth_level_set:
            if popped_node_level[1] % 2 == 0:
                for number in level_value_list_dictionary[popped_node_level[1]]:
                    zigzag_list.append(number)
            else:
                for number in reversed(level_value_list_dictionary[popped_node_level[1]]):
                    zigzag_list.append(number)
            
    return zigzag_list
        
#TESTS

def run_aligned_chain_tests():
  tests = [
      # Test 1: from the book
      (Node(7, Node(1, Node(2, Node(4), Node(3)),
                    Node(8)), Node(3, Node(2, Node(3)))), 3),
      # Test 2
      (Node(0,
            Node(1,
                 Node(2,
                      Node(3),
                      None),
                 Node(4)),
            Node(5)), 4),

      # Test 3: Empty tree
      (None, 0),

      # Test 4: Single node aligned at root
      (Node(0), 1),

      # Test 5: Single node not aligned
      (Node(1), 0),

      # Test 6: Multiple valid chains, should return longest
      (Node(0,
            Node(1,
                 Node(2,
                      Node(4),
                      None),
                 Node(2,
                      Node(3),
                      None))), 4),

      # Test 7: No aligned nodes
      (Node(5,
            Node(4,
                 Node(3),
                 Node(3)),
            Node(2)), 0),

      # Test 8
      (Node(0,
            Node(1),
            Node(1)), 2),
  ]

  for i, (root, want) in enumerate(tests, 1):
    got = longest_aligned_chain(root)
    assert got == want, f"\nTest {i} failed! Got: {got}, Want: {want}"
  
  print("ALL ALIGNED CHAIN TESTS PROVIDED HAVE PASSED.")

def run_tree_layout_tests():
  # Test 1: Example from the book - two nodes stacked
  root1 = Node(1)
  root1.left = Node(2)
  root1.right = Node(3)
  root1.left.left = Node(4)
  root1.left.right = Node(5)
  root1.left.left.right = Node(7)
  root1.right.left = Node(6)
  root1.right.left.left = Node(8)
  root1.right.left.right = Node(9)

  root2 = Node(1)

  root3 = Node(1,
               Node(2),
               Node(3))

  # Test 4: Perfect binary tree of depth 4
  root4 = Node(1,
               Node(2,
                    Node(4,
                         Node(8),
                         Node(9, None, Node(16))),
                    Node(5,
                         Node(10, None, Node(17)),
                         Node(11, Node(18), None))),
               Node(3,
                    Node(6,
                         Node(12),
                         Node(13)),
                    Node(7,
                         Node(14, Node(19), None),
                         Node(15, Node(20), None))))

  tests = [
      (root1, 2),  # Example from book
      (root2, 1),  # Single node
      (root3, 1),
      (root4, 4),
  ]

  for i, (root, want) in enumerate(tests, 1):
    got = most_stacked(root)
    assert got == want, f"\nmost_stacked(): got: {got}, want: {want}\n"

  print("ALL TREE LAYOUT TESTS PROVIDED HAVE PASSED.")

def run_aligned_path_tests():
  tests = [
      # Test 1: Example from the book
      (Node(7, Node(1, Node(2, Node(4), Node(3)),
                    Node(8)), Node(3, Node(2, Node(3), Node(3)))), 3),
      # Variation 1
      (Node(7, Node(1, Node(20, Node(4), Node(3)),
                    Node(8)), Node(3, Node(2, Node(3), Node(3)))), 3),
      # Variation 2
      (Node(7, Node(1, Node(2, Node(4), Node(3)),
                    Node(8)), Node(3, Node(20, Node(3), Node(3)))), 3),
      # Variation 3
      (Node(7, Node(1, Node(20, Node(4), Node(3)),
                    Node(8)), Node(3, Node(20, Node(3), Node(3)))), 1),
      # Test 2: Empty tree
      (None, 0),
      # Test 3: Single aligned node
      (Node(0), 1),
      # Test 4: Single unaligned node
      (Node(1), 0),
      # Test 5: Path through root
      (Node(0, Node(1), Node(1)), 3),
      # Test 6: No aligned nodes
      (Node(5, Node(4), Node(2)), 0),
      # Test 7
      (Node(0, Node(1, Node(2), Node(2)), Node(1)), 4),
  ]

  for i, (root, want) in enumerate(tests, 1):
    got = aligned_path(root)
    assert got == want, f"\naligned_path(): got: {got}, want: {want}\n"
    
  print("ALL ALIGNED PATH TESTS PROVIDED PASSED.")

def run_triangle_count_tests():
  tests = [
      # Example
      (Node(1,
            Node(2,
                 Node(4),
                 Node(5)),
            Node(3,
                 Node(6),
                 Node(7))), 4),
      (None, 0),  # Empty tree
      (Node(1), 0),  # Single node
      # No triangles - only left children
      (Node(1,
            Node(2,
                     Node(3),
                     None),
            None), 0),
      # No triangles - only right children
      (Node(1,
            None,
            Node(2,
                 None,
                 Node(3))), 0),
      (Node(1,
            Node(2),
            Node(3)), 1),
  ]

  for _, (root, want) in enumerate(tests):
    got = triangle_count(root)
    assert got == want, f"\ntriangle_count(): got: {got}, want: {want}\n"
  
  print("ALL TRIANGLE COUNT TESTS PROVIDED HAVE PASSED.")

def run_invert_a_binary_tree_tests():

  # Test 1: Example from the book - tree with 4 triangles
  root1a = Node(1,
                Node(6,
                     Node(4,
                          None,
                          Node(5)),
                     Node(11)),
                Node(7,
                     Node(2,
                          None,
                          Node(9)),
                     None))
  root1b = Node(1)
  root1b.left = Node(7)
  root1b.right = Node(6)
  root1b.left.right = Node(2)
  root1b.left.right.left = Node(9)
  root1b.right.left = Node(11)
  root1b.right.right = Node(4)
  root1b.right.right.left = Node(5)

  # Test 2: Empty tree
  root2 = None

  # Test 3: Single node
  root3 = Node(1)

  root4a = Node(1,
                Node(2,
                     Node(3),
                     None),
                None)
  root4b = Node(1,
                None,
                Node(2,
                     None,
                     Node(3)))

  tests = [
      (root1a, root1b),  # Example from book
      (root2, None),  # Empty tree
      (root3, root3),  # Single node
      (root4a, root4b),
  ]

  def same_values(t1, t2):
    if not t1 and not t2:
      return True
    if not t1 or not t2:
      return False
    return (t1.val == t2.val and
            same_values(t1.left, t2.left) and
            same_values(t1.right, t2.right))

  for i, (root, want) in enumerate(tests, 1):
    got = invert(root)
    assert same_values(got, want), f"\ninvert(): got != want\n"
  
  print("ALL INVERT A BINARY TREE TESTS PROVIDED HAVE PASSED.")

def run_evaluate_expression_tree_tests():
  # Test 0: Example from the book
  root0 = Nary_Node("min", None, [
      Nary_Node("max", None, [
          Nary_Node("num", 4, None),
          Nary_Node("num", 6, None),
          Nary_Node("sum", None, [
              Nary_Node("num", 5, None),
              Nary_Node("num", 7, None)
          ])
      ]),
      Nary_Node("sum", None, [
          Nary_Node("product", None, [
              Nary_Node("num", 6, None),
              Nary_Node("num", 8, None)
          ])
      ])
  ])

  # Test 1: Example - (2 + 3) * 4
  root1 = Nary_Node("product", None, [
      Nary_Node("sum", None, [
          Nary_Node("num", 2, None),
          Nary_Node("num", 3, None)
      ]),
      Nary_Node("num", 4, None)
  ])

  # Test 2: Single number node
  root2 = Nary_Node("num", 5, None)

  # Test 3: Empty sum node
  root3 = Nary_Node("sum", None, [])

  # Test 4: Empty product node
  root4 = Nary_Node("product", None, [])

  # Test 5: Complex expression with all operations
  # min(2, max(3,4)) + product(1,2,3)
  root5 = Nary_Node("sum", None, [
      Nary_Node("min", None, [
          Nary_Node("num", 2, None),
          Nary_Node("max", None, [
              Nary_Node("num", 3, None),
              Nary_Node("num", 4, None)
          ])
      ]),
      Nary_Node("product", None, [
          Nary_Node("num", 1, None),
          Nary_Node("num", 2, None),
          Nary_Node("num", 3, None)
      ])
  ])

  tests = [
      (root0, 12),
      (root1, 20),  # (2 + 3) * 4 = 20
      (root2, 5),   # Single number
      (root3, 0),   # Empty sum = 0
      (root4, 1),   # Empty product = 1
      (root5, 8),   # min(2,max(3,4)) + product(1,2,3) = 2 + 6 = 8
      (root0.children[0], 12),
      (root0.children[1], 48),
  ]

  for i, (root, want) in enumerate(tests, 1):
    got = evaluate(root)
    assert got == want, f"\nevaluate(root{i}): got: {got}, want: {want}\n"
  
  print("ALL EVALUATE EXPRESSION TREE TESTS PROVIDED HAVE PASSED.")

def run_left_view_tests():

  # Test 1
  root1 = Node(1,
               Node(2,
                    Node(4),
                    Node(5)),
               Node(3,
                    None,
                    Node(6)))

  # Test 2: Empty tree
  root2 = None

  # Test 3: Single node
  root3 = Node(1)

  # Test 4: Only right children
  root4 = Node(1,
               None,
               Node(2,
                    None,
                    Node(3)))

  # Test 5: Only left children
  root5 = Node(1,
               Node(2,
                    Node(3),
                    None),
               None)

  # Test 6: Example from the book
  root6 = Node(5,
               Node(2,
                    None,
                    Node(6)),
               Node(9,
                    Node(9,
                         None,
                         Node(1)),
                    Node(8)))

  tests = [
      (root1, [1, 2, 4]),  # Example
      (root2, []),  # Empty tree
      (root3, [1]),  # Single node
      (root4, [1, 2, 3]),  # Only right children
      (root5, [1, 2, 3]),  # Only left children
      (root6, [5, 2, 6, 1])  # Example from the book
  ]

  for i, (root, want) in enumerate(tests):
    got = left_view(root)
    assert got == want, f"\nleft_view(root{i + 1}): got: {got}, want: {want}\n"

  print("ALL LEFT VIEW TESTS PROVIDED HAVE PASSED.")

def run_most_prolific_level_tests():
  # Test 1
  root1 = Node(5,
               Node(2,
                    None,
                    Node(6)),
               Node(9,
                    Node(9,
                         None,
                         Node(1)),
                    Node(8)))

  # Test 2: Empty tree
  root2 = None

  # Test 3: Single node
  root3 = Node(1)

  # Test 4: Perfect binary tree
  root4 = Node(1,
               Node(2,
                    Node(4),
                    Node(5)),
               Node(3,
                    Node(6),
                    Node(7)))

  # Test 5: Unbalanced tree
  root5 = Node(1,
               Node(2,
                    Node(4,
                         Node(8),
                         Node(9)),
                    Node(5)),
               Node(3))

  # Test 6: Example from the book
  root6 = Node(1,
               Node(2,
                    Node(4,
                         Node(8),
                         Node(9)),
                    Node(5,
                         None,
                         Node(11))),
               None)
  # Test 7
  root7 = Node(1,
               Node(2,
                    Node(4,
                         Node(8),
                         Node(9))))
  tests = [
      (root1, [0]),
      (root2, [-1]),  # Empty tree
      (root3, [0]),  # Single node: level 0 has prolificness 0
      # Level 0->1 and 1->2 both have prolificness 2
      (root4, [0, 1]), # Both level 0 and 1 are valid answers
      (root5, [0]),
      (root6, [1]),
      (root7, [2]),
  ]

  for i, (root, valid_wants) in enumerate(tests):
    got = most_prolific_level(root)
    assert got in valid_wants, f"\nmost_prolific_level(root{
        i + 1}): got: {got}, valid_wants: {valid_wants}\n"
  
  print("ALL MOST PROLIFIC LEVEL TESTS PROVIDED HAVE PASSED.")

def run_zigzag_order_tests():
  # Example 1 from the book
  root1 = Node(1)
  root1.left = Node(2)
  root1.right = Node(3)
  root1.left.left = Node(4)
  root1.left.right = Node(5)
  root1.right.left = Node(6)
  root1.right.right = Node(7)

  # Example 2 - empty tree
  root2 = None

  # Example 3 - single node
  root3 = Node(1)

  # Example 4 - unbalanced tree
  root4 = Node(1)
  root4.left = Node(2)
  root4.left.left = Node(3)
  root4.left.left.left = Node(4)

  # Example 5 - complete binary tree
  root5 = Node(1)
  root5.left = Node(2)
  root5.right = Node(3)
  root5.left.left = Node(4)
  root5.left.right = Node(5)
  root5.right.left = Node(6)
  root5.right.right = Node(7)
  root5.left.left.left = Node(8)
  root5.left.left.right = Node(9)
  root5.left.right.left = Node(10)
  root5.left.right.right = Node(11)
  root5.right.left.left = Node(12)
  root5.right.right.left = Node(14)
  root5.right.right.right = Node(15)

  tests = [
      # Example 1 - basic tree
      (root1, [1, 3, 2, 4, 5, 6, 7]),
      # Example 2 - empty tree
      (root2, []),
      # Example 3 - single node
      (root3, [1]),
      # Example 4 - unbalanced tree
      (root4, [1, 2, 3, 4]),
      # Example 5 - complete binary tree
      (root5, [1, 3, 2, 4, 5, 6, 7, 15, 14, 12, 11, 10, 9, 8])
  ]

  for i, (root, want) in enumerate(tests):
    got = zig_zag_order(root)
    assert got == want, f"\nExample {
        i + 1}: zig_zag_order({root}): got: {got}, want: {want}\n"

  print("ALL ZIG-ZAG ORDER TESTS PROVIDED HAVE PASSED.")

#ALL TESTS

def Run_All_Trees_Tests():
    run_aligned_chain_tests()
    run_tree_layout_tests()
    run_aligned_path_tests()
    run_triangle_count_tests()
    run_invert_a_binary_tree_tests()
    run_evaluate_expression_tree_tests()
    run_left_view_tests()
    run_most_prolific_level_tests()
    run_zigzag_order_tests()
    
    print()
    print("--------------------------------------------------")
    print("ALL INCLUDED TREES TESTS IN THE FILE HAVE PASSED. |")
    print("--------------------------------------------------")
    
if __name__ == "__main__":
    run_zigzag_order_tests()