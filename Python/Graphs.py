from collections import defaultdict
from collections import deque

def validate(graph):
    #Problem 36.1 - Adjacency List Validation
    
    node_set_dictionary = defaultdict(set)
    for index, node in enumerate(graph):
        for number in node:
            if (number > len(graph) - 1 or 
                number < 0 or 
                number == index or
                number in node_set_dictionary[index]):
                return False
            
            node_set_dictionary[index].add(number)
    
    for index, node in enumerate(graph):
        for number in node:
            if index not in node_set_dictionary[number]:
                return False
    
    return True

def path(graph, node1, node2):
    #Problem 36.2 - Graph Path
    
    if node1 == node2:
        return [node1]
    
    path_list = [node1]
    temporary_path_list = []
    path_set = set([node1])
    found_flag = [False]
    
    def path_dfs(graph, node_index, node2):
        for index in range(len(graph[node_index])):
            if graph[node_index][index] == node2:
                path_list.extend(temporary_path_list)
                path_list.append(graph[node_index][index])
                found_flag[0] = True
                return 
            
            if graph[node_index][index] in path_set:
                continue
            
            path_set.add(graph[node_index][index])
            temporary_path_list.append(graph[node_index][index])
            
            path_dfs(graph, graph[node_index][index], node2)
            
            if found_flag[0] == True:
                return
            
            temporary_path_list.pop()
            
    for index in range(len(graph[node1])):
        if graph[node1][index] == node2:
            path_list.append(graph[node1][index])
            return path_list
        
        path_set.add(graph[node1][index])
        temporary_path_list.append(graph[node1][index])
        
        path_dfs(graph, graph[node1][index], node2)
        
        if found_flag[0] == True:
            break
        
        temporary_path_list.pop()
    
    if found_flag[0] == False:
        return [] 
    
    return path_list

def is_tree(graph):
    #Problem 36.3 - Tree Check
    
    if not graph:
        return True
    
    node_dequeue = deque([(0, -1)])
    node_set = set()
    
    while node_dequeue:
        popped_node, connection_node = node_dequeue.popleft()
        
        node_set.add(popped_node)
        for node_point in graph[popped_node]:
            if node_point not in node_set:
                node_dequeue.append((node_point, popped_node))
            elif node_point != connection_node:
                return False
            
    if len(graph) == len(node_set):
        return True
    
    return False

def spanning_tree(graph):
    #Problem 36.4 - Spanning Tree
    
    node_set = set()
    spanning_connection_list = []
    
    def dfs_spanning(node):
        for node_index in graph[node]:
            if node_index in node_set:
                continue
            
            node_set.add(node_index)
            spanning_connection_list.append([node, node_index])
            dfs_spanning(node_index)
        
    node_set.add(0)
        
    dfs_spanning(0)
    
    return spanning_connection_list    

def connected_component_queries(graph, queries):
    #Problem 36.5 - Reachability Queries
    
    visited_node_set = set()
    node_can_be_visited_dictionary = defaultdict(set)
    node_path = []

    def dfs_connection(node):
        if node in visited_node_set:
            return
        
        visited_node_set.add(node)
        node_path.append(node)
        
        for index in range(len(graph[node])):
            dfs_connection(graph[node][index])
    
    for index0 in range(len(graph)):
        if index0 in visited_node_set:
            continue
        
        dfs_connection(index0)
    
        for node_1 in node_path:
            for index2 in range(len(node_path)):
                node_can_be_visited_dictionary[node_1].add(node_path[index2])
                
        node_path = []
    
    is_query_connected_list = []
    for query in queries:
        if query[1] in node_can_be_visited_dictionary[query[0]]:
            is_query_connected_list.append(True)
        else:
            is_query_connected_list.append(False)
    
    return is_query_connected_list

def strongly_connected(graph):
    #Problem 36.6 - Strongly Connected Graph
    
    if len(graph) == 1 and not graph[0]:
        return True
    
    strongly_connected_flag = [True]
    node_set = set()
    
    def dfs_stongly_connected(node, connected_node):
        if not graph[node]:
            strongly_connected_flag[0] = False
            return 
        
        if node in node_set:
            return
        
        node_set.add(node)
        
        for node1 in graph[node]:            
            dfs_stongly_connected(node1, node)
    
    dfs_stongly_connected(0, -1)

    return strongly_connected_flag[0]

#TESTS

def path_bfs(graph, node1, node2):
    #Problem 36.2 - Graph Path - Part of Tests
    
  Q = deque()
  Q.append(node2)
  predecessors = {node2: None}
  while Q:
    node = Q.popleft()
    for nbr in graph[node]:
      if nbr not in predecessors:
        predecessors[nbr] = node
        Q.append(nbr)
  if node1 not in predecessors:
    return []
  path = [node1]
  while path[len(path) - 1] != node2:
    path.append(predecessors[path[len(path) - 1]])
  return path

def run_validate_tests():
  tests = [
      # Valid cases
      [[[1], [0]], True],  # Simple valid graph
      [[[1, 2], [0, 2], [0, 1]], True],  # Triangle graph
      [[], True],  # Empty graph
      [[[]], True],  # Single isolated node

      # Invalid node index cases
      [[[2], [0]], False],  # Node index too large
      [[[-1], []], False],  # Negative node index

      # Self-loop cases
      [[[0], []], False],  # Self loop
      [[[1], [1]], False],  # Self loop in second node

      # Parallel edge cases
      [[[1, 1], [0, 0]], False],  # Same edge twice from first node
      [[[1], [0, 2, 0], [1]], False],  # Same edge twice from second node

      # Unmatched edge cases
      [[[1], []], False],  # Edge only in one direction
      [[[1, 2], [0], []], False],  # Some edges missing their pairs
      [[[1], [2], [0]], False],  # Cycle with unmatched edges
  ]
  
  for graph, want in tests:
    got = validate(graph)
    assert got == want, f"\nvalidate({graph}): got: {got}, want: {want}\n"

  print("ALL VALIDATE TESTS PROVIDED HAVE PASSED.")

def run_connectivity_tests():
  tests = [
      # Example 1 from book - graph from Figure 8
      [[[1], [0, 2, 5, 4], [1, 4, 5], [], [5, 2, 1], [1, 2, 4]], 0, 4, [0, 1, 4]],
      # Example 2 from book - graph from Figure 8, no path exists
      [[[1], [0, 2, 5, 4], [1, 4, 5], [], [5, 2, 1], [1, 2, 4]], 0, 3, []],
      # Simple line graph
      [[[1], [0, 2], [1]], 0, 2, [0, 1, 2]],
      # Cycle graph
      [[[1, 3], [0, 2], [1, 3], [0, 2]], 0, 2, [0, 1, 2]],
      # Disconnected graph
      [[[1], [0], [3], [2]], 0, 2, []],
      # Complete graph
      [[[1, 2], [0, 2], [0, 1]], 0, 2, [0, 2]]
  ]
  for graph, node1, node2, want in tests:
    got = path(graph, node1, node2)
    got_bfs = path_bfs(graph, node1, node2)
    # For this problem, there can be multiple valid paths
    # So we need to verify:
    # 1. If want is empty, got should be empty
    # 2. If want is not empty:
    #    - got should start with node1 and end with node2
    #    - got should be a valid path in the graph
    #    - got should not have duplicates
    if not want:
      assert not got, f"\npath({graph}, {node1}, {node2}): got: {
          got}, want empty path\n"
      assert not got_bfs, f"\npath_bfs({graph}, {node1}, {node2}): got: {
          got_bfs}, want empty path\n"
      continue

    assert got[0] == node1 and got[-1] == node2, \
        f"\npath({graph}, {node1}, {node2}): path {
        got} should start with {node1} and end with {node2}\n"
    assert got_bfs[0] == node1 and got_bfs[-1] == node2, \
        f"\npath_bfs({graph}, {node1}, {node2}): path {
        got_bfs} should start with {node1} and end with {node2}\n"

    # Verify path is valid
    for i in range(len(got) - 1):
      assert got[i + 1] in graph[got[i]], \
          f"\npath({graph}, {node1}, {node2}): invalid path {
          got} - no edge between {got[i]} and {got[i + 1]}\n"
    for i in range(len(got_bfs) - 1):
      assert got_bfs[i + 1] in graph[got_bfs[i]], \
          f"\npath_bfs({graph}, {node1}, {node2}): invalid path {
          got_bfs} - no edge between {got_bfs[i]} and {got_bfs[i + 1]}\n"

    # Verify no duplicates
    assert len(got) == len(set(got)), \
        f"\npath({graph}, {node1}, {node2}): path {got} contains duplicates\n"
    assert len(got_bfs) == len(set(got_bfs)), \
        f"\npath_bfs({graph}, {node1}, {node2}): path {got_bfs} contains duplicates\n"

  print("ALL CONNECTIVITY TESTS PROVIDED HAVE PASSED.")

def run_tree_check_tests():
  tests = [
    # Example 1 from the book
    ([[2], [2, 5], [0, 1, 3, 4], [2], [2], [1]], True),
    # Example 2 from the book
    ([[2], [5], [0, 3], [2], [], [1]], False),
    # Example 3 from the book
    ([[1], [0, 2, 5], [1, 3, 4], [2], [2, 5], [1, 4]], False),
    # Single node
    ([[]], True),
    # Two nodes connected
    ([[1], [0]], True),
    # Two nodes disconnected
    ([[], []], False),
    # Line graph (valid tree)
    ([[1], [0, 2], [1, 3], [2]], True),
    # Cycle
    ([[1, 3], [2, 0], [3, 1], [0, 2]], False),
    # Complete graph K4 (not a tree)
    ([[1, 2, 3], [0, 2, 3], [0, 1, 3], [0, 1, 2]], False),
    # Star graph
    ([[1, 2, 3, 4], [0], [0], [0], [0]], True),
  ]
  
  for graph, want in tests:
    got = is_tree(graph)
    assert got == want, f"\nis_tree({graph}): got: {got}, want: {want}\n"
  
  print("ALL TREE CHECK TESTS PROVIDED HAVE PASSED.")

def run_spanning_tree_tests():
  tests = [
      # Example from the book
      [[1], [0, 2, 5], [1, 3, 4], [2], [2, 5], [1, 4]],
      # Single edge
      [[1], [0]],
      # Line graph
      [[1], [0, 2], [1]],
      # Star graph
      [[1, 2, 3], [0], [0], [0]],
      # Complete graph
      [[1, 2], [0, 2], [0, 1]],
      # Single node graph
      [[]]
  ]

  for graph in tests:
    got = spanning_tree(graph)
    # Since there can be multiple valid spanning trees,
    # we check that:
    # 1. We have V-1 edges
    # 2. Each edge connects valid nodes
    # 3. The edges form a tree (no cycles)
    V = len(graph)
    assert len(got) == V - 1, \
        f"\nspanning_tree({graph}): got wrong number of edges: {got}"

    # Check edges are valid
    for u, v in got:
      assert 0 <= u < V and 0 <= v < V, \
          f"\nspanning_tree({graph}): invalid node in edge {[u, v]}"
      assert v in graph[u] and u in graph[v], \
          f"\nspanning_tree({graph}): invalid edge {[u, v]}"

    # Check no cycles by counting reachable nodes
    adj = [[] for _ in range(V)]
    for u, v in got:
      adj[u].append(v)
      adj[v].append(u)

    visited = set()

    def dfs_check(node, parent):
      visited.add(node)
      for nbr in adj[node]:
        if nbr != parent:
          if nbr in visited:
            return False
          if not dfs_check(nbr, node):
            return False
      return True

    assert dfs_check(0, -1) and len(visited) == V, \
        f"\nspanning_tree({graph}): edges do not form a tree: {got}"
    
  print("ALL SPANNING TREE TESTS PROVIDED HAVE PASSED.")

def run_reachability_queries_tests():
  tests = [
      # Cycle graph with 6 nodes
      [[[1, 5], [0, 2, 4], [1, 3, 5], [2, 4], [1, 3, 5], [0, 2, 4]],
       [(0, 4), (0, 3)],
          [True, True]],
      # Example
      [[[1], [0, 2, 5, 4], [1, 4, 5], [], [5, 2, 1], [1, 2, 4]],
       [(0, 4), (0, 3)],
          [True, False]],
      # Simple line graph
      [[[1], [0, 2], [1]],
          [(0, 2), (0, 1)],
          [True, True]],
      # Disconnected components
      [[[1], [0], [3], [2]],
          [(0, 1), (0, 2), (2, 3)],
          [True, False, True]],
      # Complete graph
      [[[1, 2], [0, 2], [0, 1]],
          [(0, 1), (1, 2), (0, 2)],
          [True, True, True]],
      # Single node
      [[[]],
          [(0, 0)],
          [True]],
      # Empty queries
      [[[1], [0]],
          [],
          []]
  ]
  
  for graph, queries, want in tests:
    got = connected_component_queries(graph, queries)
    assert got == want, f"\nconnected_component_queries({graph}, {queries}): got: {
        got}, want: {want}\n"
    
  print("ALL REACHABILITY QUERIES TESTS PROVIDED PASSED.")
  

def run_strongly_connected_graph_tests():
  tests = [
      # Example strongly connected
      [[[1], [2], [0]], True],
      # Example not strongly connected
      [[[1], [2], []], False],
      # Single node
      [[[]], True],
      # Two nodes, strongly connected
      [[[1], [0]], True],
      # Two nodes, not strongly connected
      [[[1], []], False],
      # Cycle of 4 nodes
      [[[1], [2], [3], [0]], True],
      # Almost cycle of 4 nodes, missing one edge
      [[[1], [2], [3], []], False],
      # Complete graph
      [[[1, 2], [0, 2], [0, 1]], True],
  ]
  
  for graph, want in tests:
    got = strongly_connected(graph)
    assert got == want, f"\nstrongly_connected({graph}): got: {
        got}, want: {want}\n"

  print("ALL STRONGLY CONNECTED GRAPH TESTS PROVIDED HAVE PASSED.")
  
#ALL TESTS

def Run_All_Graphs_Tests():
    run_validate_tests()
    run_connectivity_tests()
    run_tree_check_tests()
    run_spanning_tree_tests()
    run_reachability_queries_tests()
    run_strongly_connected_graph_tests()
    
    print()
    print("------------------------------------------")
    print("ALL GRAPHS TESTS IN THE FILE HAVE PASSED. |")
    print("------------------------------------------")

if __name__ == "__main__":
    run_strongly_connected_graph_tests()