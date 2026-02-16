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

def threeWayMerge(arr1: list[int], arr2: list[int], arr3: list[int]) -> list[int]:
    #Problem 27.8 Three-Way Merge Without Duplicates

    inThereSet = set()
    uniqueArray = []
    
    arr1Pointer = 0
    arr2Pointer = 0
    arr3Pointer = 0
    
    while arr1Pointer < len(arr1) and arr2Pointer < len(arr2) and arr3Pointer < len(arr3):
        if arr1[arr1Pointer] < arr2[arr2Pointer] and arr1[arr1Pointer] < arr3[arr3Pointer]:
            if arr1[arr1Pointer] not in inThereSet:    
                inThereSet.add(arr1[arr1Pointer])
                uniqueArray.append(arr1[arr1Pointer])
            arr1Pointer += 1
            continue
        elif arr2[arr2Pointer] < arr1[arr1Pointer] and arr2[arr2Pointer] < arr3[arr3Pointer]:
            if arr2[arr2Pointer] not in inThereSet:
                inThereSet.add(arr2[arr2Pointer])
                uniqueArray.append(arr2[arr2Pointer])
            arr2Pointer += 1
            continue
        elif arr3[arr3Pointer] < arr1[arr1Pointer] and arr3[arr3Pointer] < arr2[arr2Pointer]:
            if arr3[arr3Pointer] not in inThereSet:
                inThereSet.add(arr3[arr3Pointer])
                uniqueArray.append(arr3[arr3Pointer])
            arr3Pointer += 1
            continue
        
        if arr1[arr1Pointer] == arr2[arr2Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer]:
            if arr1[arr1Pointer] not in inThereSet:    
                inThereSet.add(arr1[arr1Pointer])
                uniqueArray.append(arr1[arr1Pointer])
            arr1Pointer += 1
            arr2Pointer += 1
            arr3Pointer += 1
        elif arr1[arr1Pointer] < arr2[arr2Pointer] and arr2[arr2Pointer] == arr3[arr3Pointer]:
            if arr1[arr1Pointer] not in inThereSet:
                inThereSet.add(arr1[arr1Pointer])
                uniqueArray.append(arr1[arr1Pointer])
            arr1Pointer += 1
        elif arr2[arr2Pointer] < arr1[arr1Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer]:
            if arr2[arr2Pointer] not in inThereSet:
                inThereSet.add(arr2[arr2Pointer])
                uniqueArray.append(arr2[arr2Pointer])
            arr2Pointer += 1
        elif arr3[arr3Pointer] < arr1[arr1Pointer] and arr1[arr1Pointer] == arr2[arr2Pointer]:
            if arr3[arr3Pointer] not in inThereSet:
                inThereSet.add(arr3[arr3Pointer])
                uniqueArray.append(arr3[arr3Pointer])
            arr3Pointer += 1
        elif arr1[arr1Pointer] < arr3[arr3Pointer] and arr1[arr1Pointer] == arr2[arr2Pointer]:
            if arr1[arr1Pointer] not in inThereSet:
                inThereSet.add(arr1[arr1Pointer])
                uniqueArray.append(arr1[arr1Pointer])
            arr1Pointer += 1
            arr2Pointer += 1
        elif arr1[arr1Pointer] < arr2[arr2Pointer] and arr1[arr1Pointer] == arr3[arr3Pointer]:
            if arr1[arr1Pointer] not in inThereSet:
                inThereSet.add(arr1[arr1Pointer])
                uniqueArray.append(arr1[arr1Pointer])
            arr1Pointer += 1
            arr3Pointer += 1
        elif arr2[arr2Pointer] < arr1[arr1Pointer] and arr2[arr2Pointer] == arr3[arr3Pointer]:
            if arr2[arr2Pointer] not in inThereSet:
                inThereSet.add(arr2[arr2Pointer])
                uniqueArray.append(arr2[arr2Pointer])
            arr2Pointer += 1
            arr3Pointer += 1
        elif arr2[arr2Pointer] < arr3[arr3Pointer] and arr2[arr2Pointer] == arr1[arr1Pointer]:
            if arr2[arr2Pointer] not in inThereSet:
                inThereSet.add(arr2[arr2Pointer])
                uniqueArray.append(arr2[arr2Pointer])
            arr1Pointer += 1
            arr2Pointer += 1
        elif arr3[arr3Pointer] < arr1[arr1Pointer] and arr3[arr3Pointer] == arr2[arr2Pointer]:
            if arr3[arr3Pointer] not in inThereSet:
                inThereSet.add(arr3[arr3Pointer])
                uniqueArray.append(arr3[arr3Pointer])
            arr2Pointer += 1
            arr3Pointer += 1
            #
        elif arr3[arr3Pointer] < arr2[arr2Pointer] and arr3[arr3Pointer] == arr1[arr1Pointer]:
            if arr3[arr3Pointer] not in inThereSet:
                inThereSet.add(arr3[arr3Pointer])
                uniqueArray.append(arr3[arr3Pointer])
            arr1Pointer += 1
            arr3Pointer += 1
    
    pointer1 = 0
    pointer2 = 0
    
    array1 = 0
    array2 = 0
    
    if arr1Pointer > len(arr1) - 1:
        pointer1 = arr2Pointer
        pointer2 = arr3Pointer
        array1 = arr2
        array2 = arr3
    elif arr2Pointer > len(arr2) - 1:
        pointer1 = arr1Pointer
        pointer2 = arr3Pointer
        array1 = arr1
        array2 = arr3
    elif arr3Pointer > len(arr3) - 1:
        pointer1 = arr1Pointer
        pointer2 = arr2Pointer
        array1 = arr1
        array2 = arr2
        
    while pointer1 < len(array1) and pointer2 < len(array2):
        if array1[pointer1] < array2[pointer2]:
            if array1[pointer1] not in inThereSet:
                inThereSet.add(array1[pointer1])
                uniqueArray.append(array1[pointer1])
            pointer1 += 1
        elif array2[pointer2] < array1[pointer1]:
            if array2[pointer2] not in inThereSet:
                inThereSet.add(array2[pointer2])
                uniqueArray.append(array2[pointer2])
            pointer2 += 1
        else:
            if array1[pointer1] not in inThereSet:
                inThereSet.add(array1[pointer1])
                uniqueArray.append(array1[pointer1])
            pointer1 += 1
            pointer2 += 1
    
    while pointer1 < len(array1):
        if array1[pointer1] not in inThereSet:
            inThereSet.add(array1[pointer1])
            uniqueArray.append(array1[pointer1])
        pointer1 += 1
    
    while pointer2 < len(array2):
        if array2[pointer2] not in inThereSet:
            inThereSet.add(array2[pointer2])
            uniqueArray.append(array2[pointer2])
        pointer2 += 1
    
    return uniqueArray

def runReverseCaseMatchTests():
    #Problem 27.5 Reverse Case Match
    
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

    print("ALL REVERSE CASE MATCH TEST PROVIDED PASSED.")

def sortValleyArray(arr: list[int]) -> list[int]:
    #Problem 27.9 Sort Valley-Shaped Array
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    sortedList = [0] * len(arr)
    indexList = len(arr) - 1
    
    while leftPointer <= rightPointer:
        if rightPointer - leftPointer == 1 or rightPointer - leftPointer == 0:
            if rightPointer == leftPointer:
                sortedList[indexList] = arr[rightPointer]
                break
            
            if arr[leftPointer] <  arr[rightPointer]:
                sortedList[indexList] = arr[rightPointer]
                indexList -= 1
                sortedList[indexList] = arr[leftPointer]
            else:
                sortedList[indexList] = arr[leftPointer]
                indexList -= 1
                sortedList[indexList] = arr[rightPointer]
            
            break
                
        if arr[leftPointer] > arr[rightPointer]:
            sortedList[indexList] = arr[leftPointer]
            leftPointer += 1
            indexList -= 1
        elif arr[rightPointer] > arr[leftPointer]:
            sortedList[indexList] = arr[rightPointer]
            rightPointer -= 1
            indexList -= 1
        else:
            sortedList[indexList] = arr[leftPointer]
            indexList -= 1
            leftPointer += 1
            sortedList[indexList] = arr[rightPointer]
            indexList -= 1
            rightPointer -= 1

    return sortedList

def missingNumbers(arr: list[int], low: int, high: int) -> list[int]:
    #Problem 27.10 Missing Numbers in Range
    
    leftPointer = 0
    
    while leftPointer < len(arr)  and arr[leftPointer] < low:
        leftPointer += 1
    
    startingRange = low
    
    missingNumberList = []
    
    if len(arr) == 0:
        for index in range(low, high + 1):
            missingNumberList.append(index)
    
    while leftPointer < len(arr) and startingRange < arr[leftPointer]:
        for index in range(startingRange, arr[leftPointer]):
            missingNumberList.append(index)
        startingRange = arr[leftPointer]
    
    while leftPointer < len(arr) and startingRange < high:
        for index in range(arr[leftPointer] - startingRange - 1):
            startingRange += 1
            missingNumberList.append(startingRange)
        
        if startingRange < arr[leftPointer] and leftPointer == len(arr):
            countHere = startingRange
            for index in range(countHere, arr[leftPointer]):
                missingNumberList.append(index)
        
        startingRange = arr[leftPointer]
        leftPointer += 1
        
        if leftPointer < len(arr) and arr[leftPointer] > high:
            for index in range(high - startingRange):
                startingRange += 1
                missingNumberList.append(startingRange)
        elif leftPointer < len(arr) and arr[leftPointer] == high:
            for index in range(high - startingRange - 1):
                startingRange += 1
                missingNumberList.append(startingRange)
        elif leftPointer >= len(arr) and high > arr[len(arr) - 1]:
            for index in range(arr[len(arr)- 1] + 1, high + 1):
                startingRange += 1
                missingNumberList.append(startingRange)
            
    return missingNumberList
    
def runMergeTests():
    #Problem 27.6 Merge Two Sorted Arrays
    
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

    print("ALL MERGE TEST PROVIDED PASSED.")

def runTwoSumTests():
    #Problem 27.7 2-Sum
    
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

    print("ALL TWO SUM TEST PROVIDED PASSED.")

def runThreeWayMergeTests():
    #Problem 27.8 Three-Way Merge
    
    tests = [
        # Example from the book
        ([2, 3, 3, 4, 5, 7], [3, 3, 9], [3, 3, 9], [2, 3, 4, 5, 7, 9]),
        # Additional test cases
        ([], [], [], []),
        ([1], [], [], [1]),
        ([1], [1], [1], [1]),
        ([1, 2, 3], [2, 3, 4], [3, 4, 5], [1, 2, 3, 4, 5]),
        ([1, 1, 1], [1, 1], [1], [1]),
        ([1, 2, 3], [4, 5, 6], [7, 8, 9], [1, 2, 3, 4, 5, 6, 7, 8, 9]),
    ]
    for arr1, arr2, arr3, want in tests:
        got = threeWayMerge(arr1, arr2, arr3)
        assert got == want, f"\nthree_way_merge({arr1}, {arr2}, {arr3}): got: {got}, want: {want}\n"

    print("ALL THREE-WAY MERGE TEST PROVIDED PASSED.")

def runSortValleyArrayTests():
    #Problem 27.9 Sort Valley-Shaped Array
    
    tests = [
        # Example 1 from the book
        ([8, 4, 2, 6], [2, 4, 6, 8]),
        # Example 2 from the book
        ([1, 2], [1, 2]),
        # Example 3 from the book
        ([2, 2, 1, 1], [1, 1, 2, 2]),
        # Additional test cases
        ([], []),
        ([1], [1]),
        ([3, 2, 1, 4], [1, 2, 3, 4]),
        ([5, 4, 3, 2, 1, 2, 3], [1, 2, 2, 3, 3, 4, 5]),
        ([1, 1, 1, 1], [1, 1, 1, 1]),
    ]
    for arr, want in tests:
        got = sortValleyArray(arr)
        assert got == want, f"\nsort_valley_array({arr}): got: {
            got}, want: {want}\n"
            
    print("ALL SORT VALLEY-SHAPED ARRAY TEST PROVIDED PASSED.")

def runMissingNumbersTests():
    tests = [
      # Example 1 from the book
      ([6, 9, 12, 15, 18], 9, 13, [10, 11, 13]),
      # Example 2 from the book
      ([], 9, 9, [9]),
      # Example 3 from the book
      ([6, 7, 8, 9], 7, 8, []),
      # Additional test cases
      ([], 1, 5, [1, 2, 3, 4, 5]),
      ([1, 2, 3, 4, 5], 1, 5, []),
      ([1, 3, 5], 1, 5, [2, 4]),
      ([1], 1, 1, []),
      ([2], 1, 3, [1, 3]),
    ]
    for arr, low, high, want in tests:
        got = missingNumbers(arr, low, high)
        assert got == want, f"\nmissing_numbers({arr}, {low}, {high}): got: {
        got}, want: {want}\n"

    print("ALL MISSING NUMBERS IN RANGE TEST PROVIDED PASSED.")
    
if __name__ =="__main__":

    runMissingNumbersTests()