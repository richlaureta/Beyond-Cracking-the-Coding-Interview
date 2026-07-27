def moves(seq: str) -> str:
    #Problem 33.1 - Robot Instructions
    
    character_list = []
    
    def recursive_moves(index: int):
        if index == len(seq):
            return
        
        if seq[index] == "2":
            recursive_moves(index + 1)
            recursive_moves(index + 2)
        else:
            character_list.append(seq[index])
            recursive_moves(index + 1)
            
    recursive_moves(0)
    
    return "".join(character_list)

def nested_array_sum(arr: list):
    #Problem 33.2 Nested Sum Array
    
    sum = [0]
    
    def recursion_nested_array(array: list):
        for index1 in range(len(array)):
            if isinstance(array[index1], int):
                sum[0] += array[index1]
            else:
                recursion_nested_array(array[index1])
                
    for iteration in arr:
        if isinstance(iteration, int):
            sum[0] += iteration
        else:
            recursion_nested_array(iteration)
    
    return sum[0]

#TESTS

def run_robot_instructions_tests():
    tests = [
        # Example 1 from book
		("LL", "LL"),
		# Example 2 from book
		("2LR", "LRR"),
		# Example 3 from book
		("2L", "L"),
		# Example 4 from book
		("22LR", "LRRLR"),
		# Example 5 from book
		("LL2R2L", "LLRLL"),
		# Edge case - empty string
		("", ""),
		# Edge case - single character
		("L", "L"),
		# Multiple 2s in a row
		("2222LR", "LRRLRLRRLRRLR"),
  	]
    
    for seq, want in tests:
        got = moves(seq)
        assert got == want, f"\nmoves({seq}): got: {got}, want: {want}\n"
    
    print("ALL ROBOT INSTRUCTIONS TESTS PROVIDED PASSED.")

def run_nested_array_sum_tests():
    tests = [
        # Example 1 from book
        ([1, [2, 3], [4, [5]], 6], 21),
        # Example 2 from book
        ([[[[1]], 2]], 3),
        # Example 3 from book
        ([], 0),
        # Edge case - all nested single numbers
        ([[[[[1]]]]], 1),
        # Edge case - multiple empty arrays
        ([[], [], []], 0),
        # Edge case - mixed empty and non-empty arrays
        ([[], [1, 2], [], [3]], 6),
        # Edge case - deeply nested mixed arrays
        ([1, [2, [], [3, []], []], [4, [5, []]]], 15),
        # Edge case - all zeros
        ([0, [0, 0], [0, [0]], 0], 0),
        # Edge case - negative numbers
        ([-1, [-2, 3], [4, [-5]], 6], 5),
        # Stress test - large deeply nested array
        ([list(range(10)), [list(range(10, 20)), list(range(20, 30))],
            [list(range(30, 40)), [list(range(40, 50))]], list(range(50, 60))],
            sum(range(60)))
    ]
    
    # Test both implementations to verify they produce the same results
    for arr, want in tests:
        got = nested_array_sum(arr)
        assert got == want, f"\nnested_array_sum({arr}): got: {got}, want: {want}\n"
        # got_eager = nested_array_sum_eager(arr)
        # assert got_eager == want, \
        #     f"\nnested_array_sum_eager({arr}): got: {got_eager}, want: {want}\n"
        

#ALL TESTS
def Run_All_Recursion_Tests():
    run_robot_instructions_tests()
    
    print()
    print("----------------------------------------------------------")
    print("ALL INCLUDED RECURSION TESTS IN THE FILE PASSED. |")
    print("----------------------------------------------------------")

if __name__ == "__main__":
    run_nested_array_sum_tests()