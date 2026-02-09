from collections import defaultdict
def palindrome(s: str) -> bool:
    #Problem 27.1 Palindrome Check
    
    leftPointer = 0
    rightPointer = len(s) - 1
    
    while leftPointer < rightPointer:
        if s[leftPointer] != s[rightPointer]:
            return False
        leftPointer += 1
        rightPointer -= 1
    
    return True

def smallerPrefixes(arr: list[int]) -> bool:
    #Problem 27.2 Smaller Prefixes - Incomplete Solution
    
    for index in range(1, len(arr)):
        arr[index]  += arr[index - 1]
        if arr[index] < arr[index - 1] and index + 1 <= len(arr)//2:
            return False
        if index + 1 > len(arr)//2 and arr[index] < arr[len(arr)//2 - 1]:
            return False
    
    return True

def commonElements(arr1, arr2) -> list[int]:
    #Problem 27.3 Array Intersection
    
    arr1Pointer = 0
    arr2Pointer = 0
    
    intersectionList = []
    
    while(arr1Pointer < len(arr1) and arr2Pointer < len(arr2)):
        if arr1[arr1Pointer] == arr2[arr2Pointer]:
            intersectionList.append(arr1[arr1Pointer])
            arr1Pointer += 1
            arr2Pointer += 1
        elif arr1[arr1Pointer] < arr2[arr2Pointer]:
            arr1Pointer += 1
        else:
            arr2Pointer += 1
    
    return intersectionList
 
def palindromicSentence(s: str) -> bool:
    #Problem 27.4 Palindromic Sentence
    
    leftPointer = 0
    rightPointer = len(s) - 1
    
    while leftPointer < rightPointer:
        while leftPointer < rightPointer and not s[leftPointer].isalnum():
            leftPointer += 1
        while leftPointer < rightPointer and not s[rightPointer].isalnum():
            rightPointer -= 1
        
        if s[leftPointer].lower() != s[rightPointer].lower():
            return False
        leftPointer += 1
        rightPointer -= 1
    
    return True

def reverseCaseMatch(s: str) -> bool:
    #Problem 27.5 Reverse Case Match
    
    leftPointer = 0
    rightPointer = len(s) - 1
    
    while True:
        while leftPointer < len(s) and s[leftPointer].isupper():
            leftPointer += 1
            
        while rightPointer > -1 and s[rightPointer].islower():
            rightPointer -= 1
        
        if leftPointer >= len(s) or rightPointer < 0:
            break
        
        if s[leftPointer] != s[rightPointer].lower():
            return False

        leftPointer += 1
        rightPointer -= 1
    
    return True

def merge(arr1: list[int], arr2: list[int]) -> list[int]:
    #Problem 27.6 Merge Two Sorted Arrays
    
    arr1Pointer = 0
    arr2Pointer = 0
    
    mergedList = []
    
    while arr1Pointer < len(arr1) and arr2Pointer < len(arr2):
        if arr1[arr1Pointer] < arr2[arr2Pointer]:
            mergedList.append(arr1[arr1Pointer])
            arr1Pointer += 1
        elif arr1[arr1Pointer] > arr2[arr2Pointer]:
            mergedList.append(arr2[arr2Pointer])
            arr2Pointer += 1
        else:
            mergedList.append(arr1[arr1Pointer])
            mergedList.append(arr2[arr2Pointer])
            arr1Pointer += 1
            arr2Pointer += 1
    
    while arr1Pointer < len(arr1):
        mergedList.append(arr1[arr1Pointer])
        arr1Pointer += 1
    
    while arr2Pointer < len(arr2):
        mergedList.append(arr2[arr2Pointer])
        arr2Pointer += 1
        
    return mergedList

def twoSum(arr: list[int]) -> bool:
    #Problem 27.7 2-Sum
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    while leftPointer < rightPointer:
        if arr[leftPointer] + arr[rightPointer] > 0:
            rightPointer -= 1
        elif arr[leftPointer] + arr[rightPointer] < 0:
            leftPointer += 1
        else:
            return True
    
    return False

def runReverseCaseMatchTests():
    tests = [
        # Example 1 from the book
        ("haDrRAHd", True),
        # Example 2 from the book
        ("haHrARDd", False),
        # Additional test cases
        ("", True),
        ("aA", True),
        ("Aa", True),
        ("BbbB", True),
        ("abAB", False),
        ("abBA", True),
        ("helloworldHELLOWORLD", False),
    ]
    
    for s, want in tests:
        got = reverseCaseMatch(s)
        assert got == want, f"\nreverse_case_match({s}): got: {got}, want: {want}\n"

    print("ALL REVERSE CASE MATCH TESTS PASSED.")

def runMergeTests():
    tests = [
      # Example 1 from the book
      ([1, 3, 4, 5], [2, 4, 4], [1, 2, 3, 4, 4, 4, 5]),
      # Example 2 from the book
      ([-1], [], [-1]),
      # Additional test cases
      ([], [], []),
      ([1], [], [1]),
      ([], [1], [1]),
      ([1, 3, 5], [2, 4, 6], [1, 2, 3, 4, 5, 6]),
      ([1, 1, 1], [1, 1, 1], [1, 1, 1, 1, 1, 1]),
  ]
    for arr1, arr2, want in tests:
        got = merge(arr1, arr2)
        assert got == want, f"\nmerge({arr1}, {arr2}): got: {got}, want: {want}\n"

    print("ALL MERGE TESTS PASSED.")

def runTwoSumTests():
    tests = [
        # Example 1 from the book
        ([-5, -2, -1, 1, 1, 10], True),
        # Example 2 from the book
        ([-3, 0, 0, 1, 2], True),
        # Example 3 from the book
        ([-5, -3, -1, 0, 2, 4, 6], False),
        # Additional test cases
        ([], False),
        ([0], False),
        ([-1, 1], True),
        ([-2, -1, 0, 1], True),
        ([1, 2, 3, 4], False),
    ]
    
    for arr, want in tests:
        got = twoSum(arr)
        assert got == want, f"\ntwo_sum({arr}): got: {got}, want: {want}\n"

    print("ALL TWO SUM TESTS PASSED.")
    
if __name__ =="__main__":
    runReverseCaseMatchTests()
    runMergeTests()
    runTwoSumTests()