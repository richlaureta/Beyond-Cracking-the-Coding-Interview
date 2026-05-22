
def searchInSortedArray(arr: list[int], target: int) -> int:
    #Problem 29.1 Search In Sorted Array
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    middlePointer = -1
    
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
    assert got == want, f"\nsearch_in_sorted_array({arr}, {target}): got: {
        got}, want: {want}\n"
        
  print("ALL SEARCH IN SORTED ARRAY TESTS PROVIDED PASSED.")
  
if __name__ == "__main__":
    runSearchInSortedArrayTests()