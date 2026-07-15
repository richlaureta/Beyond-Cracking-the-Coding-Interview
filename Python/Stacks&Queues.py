def compress_array(arr: list[int]) -> list[int]:
    #Problem 32.1 - Compress Array
    
    if not arr:
        return []
    
    numberStack = []
    numberStack.append(arr[0])
    
    for number in arr[1:]:
        if number == numberStack[-1]:
            poppedNumber = numberStack.pop()
            while numberStack and numberStack[-1] == poppedNumber * 2:
                poppedNumber = numberStack.pop()
            numberStack.append(poppedNumber * 2)
            continue

        numberStack.append(number)
    
    return numberStack

#TESTS

def run_compress_array_tests():
    tests = [
        # Examples from problem description
		([8, 4, 2, 2, 2, 4], [16, 2, 4]),
		([4, 4, 4, 4], [16]),
		([1, 2, 3, 4], [1, 2, 3, 4]),
		
		# Edge cases
		([], []),
		([1], [1]),
		([0, 0], [0]),
		([0, 0, 0, 0], [0]),
		
		# Multiple compression chains
		([1, 1, 2, 2, 3, 3], [4, 2, 6]),
		([2, 2, 2, 2, 2, 2], [8, 4]),
		
		# Alternating numbers
		([1, 2, 1, 2, 1, 2], [1, 2, 1, 2, 1, 2]),
		
		# Numbers that sum to equal another number
		([2, 2, 4], [8]),
		([3, 3, 6, 6], [12, 6]),
		
		# Large numbers within constraints
		([999, 999], [1998]),
		([500, 500, 500, 500], [2000]),
		
		# Mix of different scenarios
		([5, 5, 5, 1, 1, 5], [10, 5, 2, 5]),
  	]
    
    for arr, want in tests:
        got = compress_array(arr)
        assert got == want, f"\ncompress_array({arr}): got: {got}, want: {want}\n"
    
    print("ALL COMPRESS ARRAY TESTS PROVIDED PASSED.")

#ALL TESTS

def Run_All_Stacks_And_Queues_Tests():
    run_compress_array_tests()
    
    print()
    print("----------------------------------------------------------")
    print("ALL INCLUDED STACKS AND QUEUES TESTS IN THE FILE PASSED. |")
    print("----------------------------------------------------------")

if __name__ == "__main__":
    run_compress_array_tests()