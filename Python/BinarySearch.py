
def searchInSortedArray(arr: list[int], target: int) -> int:
    #Problem 29.1 Search In Sorted Array
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    while leftPointer <= rightPointer:
        middlePointer = (leftPointer + rightPointer) // 2
        
        if arr[middlePointer] == target:
            return middlePointer
        elif arr[leftPointer] == target:
            return leftPointer
        elif arr[rightPointer] == target:
            return rightPointer
        
        if arr[middlePointer] > target:
            rightPointer = middlePointer - 1
        else:
            leftPointer = middlePointer + 1
    
    return -1
def valleyBottom(arr: list[int]) -> int:
    #Problem 29.3 Valley Bottom
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    while True:
        middlePointer = (leftPointer + rightPointer) // 2
        
        if arr[leftPointer] <= arr[middlePointer] <= arr[rightPointer]:
            return arr[leftPointer]
        elif arr[leftPointer] >= arr[middlePointer] >= arr[rightPointer]:
            return arr[rightPointer]

        if arr[middlePointer] > arr[middlePointer + 1]:
            leftPointer = middlePointer
        else:
            rightPointer = middlePointer

def twoArrayTwoSum(sortedArray: list[int], unsortedArray: list[int]) -> list[int]:
    #Problem 29.4 2-Array 2 Sum
    
    for index in range(len(unsortedArray)):
        for index1 in range(len(sortedArray)):
            if unsortedArray[index] + sortedArray[index1] == 0:
                return [index1, index]
    
    return [-1, -1]  

#TESTS

def runSearchInSortedArrayTests():
    tests = [
        # Example 1 from book
        ([-2, 0, 3, 4, 7, 9, 11], 3, 2),
        # Example 2 from book
        ([-2, 0, 3, 4, 7, 9, 11], 2, -1),
        # Edge case - empty array
        ([], 5, -1),
        # Edge case - target at start
        ([1, 2, 3], 1, 0),
        # Edge case - target at end
        ([1, 2, 3], 3, 2),
        # Edge case - single element
        ([5], 5, 0),
        # Edge case - not found
        ([1, 3, 5], 2, -1)
        ]
    for arr, target, want in tests:
       got = searchInSortedArray(arr, target)
       assert got == want, f"\nsearchInSortedArray({arr}, {target}): got: {
        got}, want: {want}\n"
    
    print("ALL SEARCH IN SORTED ARRAY TESTS PROVIDED PASSED.")

def runValleyBottomTests():
    tests = [
        # Example 1 from book
        ([6, 5, 4, 7, 9], 4),
        # Example 2 from book
        ([5, 6, 7], 5),
        # Example 3 from book
        ([7, 6, 5], 5),
        ([2, 1], 1),
        ([3, 2, 4], 2)
    ]
    
    for arr, want in tests:
        got = valleyBottom(arr)
        assert got == want, f"\nvalley_bottom({arr}): got: {got}, want: {want}\n"

    print("ALL VALLEY BOTTOM TESTS PROVIDED PASSED.")

def run2Array2SumTests():
  tests = [
      # Example from book
      ([-5, -4, -1, 4, 6, 6, 7], [-3, 7, 18, 4, 6], [1, 3]),
      # no solution
      ([1, 2, 3], [1, 2, 3], [-1, -1]),
      ([1], [-1], [0, 0]),
      ([1, 2], [-2, -1], [1, 0]),
      ([0, 1, 2, 3], [3, 2, 1, 0], [0, 3]),
  ]

  for sorted_arr, unsorted_arr, want in tests:
    got = twoArrayTwoSum(sorted_arr, unsorted_arr)
    assert got == want, f"\ntwo_array_two_sum({sorted_arr}, {unsorted_arr}): got: {
        got}, want: {want}\n"
        
  print("ALL 2-ARRAY 2-SUM TESTS PROVIDED PASSED.")
    
if __name__ == "__main__":
    run2Array2SumTests()