from collections import defaultdict

class Node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


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
  
#ALL TESTS

def Run_All_Trees_Tests():
    run_aligned_chain_tests()
    run_tree_layout_tests()
    
    print()
    print("--------------------------------------------------")
    print("ALL INCLUDED TREES TESTS IN THE FILE HAVE PASSED. |")
    print("--------------------------------------------------")
    
if __name__ == "__main__":
    run_tree_layout_tests()