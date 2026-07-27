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

#ALL TESTS
def Run_All_Recursion_Tests():
    run_robot_instructions_tests()
    
    print()
    print("----------------------------------------------------------")
    print("ALL INCLUDED STACKS AND QUEUES TESTS IN THE FILE PASSED. |")
    print("----------------------------------------------------------")

if __name__ == "__main__":
    run_robot_instructions_tests()