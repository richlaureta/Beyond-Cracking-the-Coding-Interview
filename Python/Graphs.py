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
    #Problem 36.2 - Connectivity
    
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
    
#TESTS

def path_bfs(graph, node1, node2):
    #Problem 36.2 - Connectivity - Part of Tests
    
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
  
#ALL TESTS

def Run_All_Graphs_Tests():
    run_validate_tests()
    run_connectivity_tests()
      
    print()
    print("------------------------------------------")
    print("ALL GRAPHS TESTS IN THE FILE HAVE PASSED. |")
    print("------------------------------------------")

if __name__ == "__main__":
    run_connectivity_tests()