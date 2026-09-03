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
  
#ALL TESTS

def Run_All_Trees_Tests():
    run_aligned_chain_tests()
    
    print()
    print("--------------------------------------------------")
    print("ALL INCLUDED TREES TESTS IN THE FILE HAVE PASSED. |")
    print("--------------------------------------------------")
    
if __name__ == "__main__":
    run_aligned_chain_tests()
    
    # node7 = Node(7)
    # node1 = Node(1)
    # node3 = Node(3)
    # node2 = Node(2)
    # node8 = Node(8)
    # node_other_2 = Node(2)
    # node4 = Node(4)
    # node_other_3 = Node(3)
    # node_other_other_3 = Node(3)
    # node_other_other_other_3 = Node(3)
    
    # node7.left = node1
    # node7.right = node3
    # node1.left = node2
    # node1.right = node8
    # node3.right = node_other_2
    # node_other_2.left = node_other_other_3
    # node_other_2.right = node_other_other_other_3
    # node2.left = node4
    # node2.right = node_other_3
    
    # root = node7
    # print(longest_aligned_chain(root))