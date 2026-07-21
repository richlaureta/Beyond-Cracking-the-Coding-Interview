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

def compress_array_k(arr: list[int], k: int) -> list[int]:
    #Problem 32.2 - Compress Array by K
    
    numberStack = []
    kCount = 1
    
    for number in arr:
        if numberStack and numberStack[-1] == number:
            kCount += 1
            if kCount == k:
                for index in range(k - 1):
                    numberStack.pop()
                kProduct = number * k
                lastIndex = len(numberStack) - 1
                kBacktrackCount = 1
                while lastIndex > -1 and kProduct == numberStack[lastIndex]:
                    kBacktrackCount += 1
                    if kBacktrackCount == k:
                        for index in range(k - 1):
                            numberStack.pop()
                        kProduct *= k
                        kBacktrackCount = 1
                    lastIndex -= 1
                numberStack.append(kProduct)
                kCount = 1
                continue 
            numberStack.append(number)
            continue
        
        numberStack.append(number)
        kCount = 1
    
    return numberStack

#TESTS

def run_compress_array_tests():
    tests = [
        # Examples from problem description //TESTING GITHUB
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

def run_compress_array_by_k_tests():
    tests = [
        ([1, 9, 9, 3, 3, 3, 4], 3, [1, 27, 4]),
        ([8, 4, 2, 2], 2, [16]),
        ([4, 4, 4, 4], 5, [4, 4, 4, 4]),
        ([], 2, []),
        ([0, 0, 0, 0], 2, [0]),
    ]
    
    for arr, k, want in tests:
        got = compress_array_k(arr, k)
        assert got == want, f"\ncompress_array_k({arr}, {k}): got: {got}, want: {want}\n"

    print("ALL COMPRESS ARRAY BY K TESTS PROVIDED PASSED.")
    
#ALL TESTS

def Run_All_Stacks_And_Queues_Tests():
    run_compress_array_tests()
    run_compress_array_by_k_tests()
    
    print()
    print("----------------------------------------------------------")
    print("ALL INCLUDED STACKS AND QUEUES TESTS IN THE FILE PASSED. |")
    print("----------------------------------------------------------")

if __name__ == "__main__":
    Run_All_Stacks_And_Queues_Tests()