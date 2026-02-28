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
    
    while leftPointer < len(arr) and startingRange < arr[leftPointer]:
        for index in range(startingRange, arr[leftPointer]):
            missingNumberList.append(index)
        startingRange = arr[leftPointer]
    
    while leftPointer < len(arr) and startingRange < high:
        for index in range(arr[leftPointer] - startingRange - 1):
            startingRange += 1
            missingNumberList.append(startingRange)
        
        if startingRange < arr[leftPointer] and leftPointer == len(arr):
            for index in range(startingRange, arr[leftPointer]):
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
    
    if len(arr) == 0:
        for index in range(low, high + 1):
            missingNumberList.append(index)
            
    return missingNumberList

def intervalIntersection(arr1: list[list[int]], arr2: list[list[int]]) -> list[list[int]]:
    #Problem 27.11 Interval Intersection
    
    arr1Pointer = 0
    arr2Pointer = 0
    
    intervalOverlapList = []
    
    while arr1Pointer < len(arr1) and arr2Pointer < len(arr2):
        if arr1[arr1Pointer][1] < arr2[arr2Pointer][0]:
            arr1Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr1[arr1Pointer][0] > arr2[arr2Pointer][1]):
            arr2Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr1[arr1Pointer][1] < arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] < arr2[arr2Pointer][0]):
            intervalOverlapList.append([arr2[arr2Pointer][0], arr1[arr1Pointer][1]])
            arr1Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr1[arr1Pointer][1] < arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] > arr2[arr2Pointer][0]):
            intervalOverlapList.append([arr1[arr1Pointer][0], arr1[arr1Pointer][1]])
            arr1Pointer += 1

        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr1[arr1Pointer][1] > arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] < arr2[arr2Pointer][0]):
            intervalOverlapList.append([arr2[arr2Pointer][0], arr2[arr2Pointer][1]])
            arr2Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr2[arr2Pointer][0] == arr1[arr1Pointer][1]):
            intervalOverlapList.append([arr1[arr1Pointer][1], arr2[arr2Pointer][0]])
            arr1Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr2[arr2Pointer][1] == arr1[arr1Pointer][0]):
            intervalOverlapList.append([arr2[arr2Pointer][1], arr1[arr1Pointer][0]])
            arr2Pointer += 1
        
        if (arr1Pointer < len(arr1) and
            arr2Pointer < len(arr2) and
            arr1[arr1Pointer][1] > arr2[arr2Pointer][1] and
            arr1[arr1Pointer][0] > arr2[arr2Pointer][0]):
            intervalOverlapList.append([arr1[arr1Pointer][0], arr2[arr2Pointer][1]])
            arr2Pointer += 1
        
    return intervalOverlapList

def reverse(arr: list[str]) -> list[str]:
    #Problem 27.12 Array Reversal 
    
    leftPointer, rightPointer = 0, len(arr) - 1
    
    while leftPointer < rightPointer:
        arr[leftPointer], arr[rightPointer] = arr[rightPointer], arr[leftPointer]
        leftPointer += 1
        rightPointer -= 1
        
def sortEven(arr: list[int]):
    #Problem 27.13 Parity Sorting
    
    index, oddIndex = 0, len(arr) - 1
    
    while index < oddIndex:
        if arr[index] % 2 != 0:
            while oddIndex > 0 and arr[oddIndex] % 2 != 0:
                oddIndex -= 1
            if oddIndex > index:
                arr[index], arr[oddIndex] = arr[oddIndex], arr[index]
        
        index += 1

def removeDuplicates(arr: list[int]) -> int:
    #Problem 27.14 In-Place Duplicate Removal
    
    if len(arr) == 0:
        return 0
    
    uniqueCount = 1
    
    for index in range(1, len(arr)):
        if arr[index] != arr[index - 1]:
            arr[uniqueCount] = arr[index]
            uniqueCount += 1
            
    return uniqueCount

def partition(arr: list[int], pivot: int):
    #Problem 27.15 QuickSort Partition
    
    index = 0
    lessThanPivotIndex = 0
    greaterThanPivotIndex = len(arr) - 1
    
    while index <= greaterThanPivotIndex:
        if arr[index] > pivot:
            while greaterThanPivotIndex > -1 and arr[greaterThanPivotIndex] > pivot:
                greaterThanPivotIndex -= 1
            if greaterThanPivotIndex > -1 and index < greaterThanPivotIndex:
                arr[index], arr[greaterThanPivotIndex] = arr[greaterThanPivotIndex], arr[index]
                greaterThanPivotIndex -= 1
            if arr[index] < pivot:
                while lessThanPivotIndex < len(arr) and arr[lessThanPivotIndex] < pivot:
                    lessThanPivotIndex += 1
                    index += 1
                if lessThanPivotIndex < index:
                    arr[index], arr[lessThanPivotIndex] = arr[lessThanPivotIndex], arr[index]
        elif arr[index] < pivot:
            while lessThanPivotIndex < len(arr) and arr[lessThanPivotIndex] < pivot:
                lessThanPivotIndex += 1
            if lessThanPivotIndex < index:
                arr[index], arr[lessThanPivotIndex] = arr[lessThanPivotIndex], arr[index]
        index += 1

def sortColors(arr: list[int]):
    #Problem 27.16 Dutch Flag Problem 
    
    index = 0
    rIndex = 0
    bIndex = len(arr) - 1
    
    while index <= bIndex:
        if arr[index] == 'B':
            while bIndex > -1 and arr[bIndex] == 'B':
                bIndex -= 1
            if bIndex > -1 and index < bIndex:    
                arr[index], arr[bIndex] = arr[bIndex], arr[index]
                bIndex -= 1
            if arr[index] == 'R':
                while rIndex < len(arr) and arr[rIndex] == 'R':
                    rIndex += 1
                    index += 1
                if rIndex < index:
                    arr[index], arr[rIndex] = arr[rIndex], arr[index]
                    rIndex += 1
        elif arr[index] == 'R':
            while rIndex < len(arr) and arr[rIndex] == 'R':
                rIndex += 1
            if rIndex < index:
                arr[index], arr[rIndex] = arr[rIndex], arr[index]
                rIndex += 1
        index += 1

def swapPrefixSuffix(arr: list[str]):
    #Problem 27.17 Prefix-Suffix Swap
    
    prefixLength = int(len(arr)/3) 

    initialSwapIndex = prefixLength
    
    for index in range(prefixLength):
        arr[index], arr[initialSwapIndex] = arr[initialSwapIndex], arr[index]
        initialSwapIndex += 1
    
    endSwapIndex = len(arr) - prefixLength
    
    for index in range(prefixLength, prefixLength + prefixLength):
        arr[index], arr[endSwapIndex] = arr[endSwapIndex], arr[index]
        endSwapIndex += 1


def moveWord(arr: list[str], word: str):
    #Problem 27.18 Shift Word to Back
    
    arrPointer = 0
    wordPointer = 0
    backIndex = len(arr) - len(word)
    goBackDifference = 0
    
    wordPointerEdit = 0
    
    while arrPointer < len(arr):
        letterMatchFlag = False
        
        while wordPointer < len(word) and arrPointer < len(arr) and arr[arrPointer] == word[wordPointer]:
            if wordPointerEdit < len(word) and arrPointer >= backIndex:
                arr[arrPointer] = word[wordPointerEdit]
                wordPointerEdit += 1
            letterMatchFlag = True
            wordPointer += 1
            arrPointer += 1
            goBackDifference += 1
        if letterMatchFlag == True:
            while wordPointer < len(word) and arrPointer < len(arr) and arr[arrPointer] != word[wordPointer]:
                arr[arrPointer - goBackDifference] = arr[arrPointer]
                if wordPointerEdit < len(word) and arrPointer >= backIndex:
                    arr[arrPointer] = word[wordPointerEdit]
                    wordPointerEdit += 1
                arrPointer += 1
            
            while (arrPointer < len(arr) and 
                   wordPointer == len(word) and 
                   arrPointer <= backIndex):
                arr[arrPointer - goBackDifference] = arr[arrPointer]
                if wordPointerEdit < len(word) and arrPointer >= backIndex:
                    arr[arrPointer] = word[wordPointerEdit]
                    wordPointerEdit += 1
                arrPointer += 1
                
            while wordPointerEdit < len(word) and arrPointer < len(arr) and wordPointer == len(word):
                arr[arrPointer - goBackDifference] = arr[arrPointer]
                arr[arrPointer] = word[wordPointerEdit]
                arrPointer += 1
                wordPointerEdit += 1
        if letterMatchFlag == False:
            arrPointer += 1    
        
def runReverseCaseMatchTests():
    #Problem 27.5 Reverse Case Match Tests
    
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

def runMergeTests():
    #Problem 27.6 Merge Two Sorted Arrays Tests
    
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
    #Problem 27.7 2-Sum Tests
    
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
    #Problem 27.8 Three-Way Merge Tests
    
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
    #Problem 27.9 Sort Valley-Shaped Array Tests
    
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
    #Problem 27.10 Missing Numbers in Range Tests
    
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

def runIntervalIntersectionTests():
    #Problem 27.11 Interval Intersection Tests
    
    tests = [
        # Example 1 from the book
        ([[0, 1], [4, 6], [7, 8]], [[2, 3], [5, 9], [10, 11]], [[5, 6], [7, 8]]),
        # Example 2 from the book
        ([[2, 4], [5, 8]], [[3, 3], [4, 7]], [[3, 3], [4, 4], [5, 7]]),
        # Additional test cases
        ([], [], []),
        ([[1, 2]], [], []),
        ([[1, 3]], [[2, 4]], [[2, 3]]),
        ([[1, 5]], [[2, 3]], [[2, 3]]),
        ([[1, 2], [3, 4]], [[2, 3]], [[2, 2], [3, 3]]),
    ]
    for arr1, arr2, want in tests:
        got = intervalIntersection(arr1, arr2)
        assert got == want, f"\ninterval_intersection({arr1}, {arr2}): got: {
        got}, want: {want}\n"
    
    print("ALL INTERVAL INTERSECTION TEST PROVIDED PASSED.")

def runReverseTests():
    #Problem 27.12 Array Reversal Tests
    
    tests = [
        # Test cases
        # (list("hello"), list("olleh")),
        (list(""), list("")),
        (list("a"), list("a")),
        (list("ab"), list("ba")),
        (list("abc"), list("cba")),
        (list("abcd"), list("dcba")),
    ]
    for arr, want in tests:
        arr_copy = arr.copy()  # Make a copy since reverse modifies in place
        reverse(arr_copy)
        assert arr_copy == want, f"\nreverse({arr}): got: {
        arr_copy}, want: {want}\n"
    
    print("ALL REVERSE TEST PROVIDED PASSED.")

def isValidSolutionParitySorting(arr, original):
    #Problem 27.13 Parity Sorting Tests
    
    # Check that we have the same elements
    if sorted(arr) != sorted(original):
        return False

    # Find the boundary between even and odd numbers
    boundary = 0
    while boundary < len(arr) and arr[boundary] % 2 == 0:
        boundary += 1

    # Check that all numbers before boundary are even
    # and all numbers after are odd
    for i in range(boundary):
        if arr[i] % 2 != 0:
            return False
    for i in range(boundary, len(arr)):
        if arr[i] % 2 != 1:
            return False
        
    return True

def runParitySortingTests():
    #Problem 27.13 Parity Sorting Tests
    
    tests = [
        # Example 1 from the book
        ([1, 2, 3, 4, 5], [2, 4, 1, 3, 5]),
        # Example 2 from the book
        ([5, 1, 3, 1, 5], [5, 1, 3, 1, 5]),
        # Additional test cases
        ([], []),
        ([1], [1]),
        ([2], [2]),
        ([1, 2], [2, 1]),
        ([2, 1], [2, 1]),
        ([1, 3, 2, 4], [2, 4, 1, 3]),
    ]
    
    for arr, example_solution in tests:
        arr_copy = arr.copy()  # Make a copy since sort_even modifies in place
        sortEven(arr_copy)
        assert isValidSolutionParitySorting(arr_copy, arr), \
            f"\nsort_even({arr}): got: {arr_copy}, example solution: {
            example_solution}\n"
    
    print("ALL PARITY SORTING TEST PROVIDED PASSED.")

def runRemoveDuplicatesTests():
    #Problem 27.14 In-Place Duplicate Removal Tests
    
    tests = [
        # Example from the book
        ([1, 2, 2, 3, 3, 3, 5], 4, [1, 2, 3, 5]),
        # Additional test cases
        ([], 0, []),
        ([1], 1, [1]),
        ([1, 1], 1, [1]),
        ([1, 2], 2, [1, 2]),
        ([1, 1, 1], 1, [1]),
        ([1, 2, 2, 2, 3], 3, [1, 2, 3]),
    ]
    for arr, want_len, want_prefix in tests:
        arr_copy = arr.copy()  # Make a copy since remove_duplicates modifies in place
        got_len = removeDuplicates(arr_copy)
        assert got_len == want_len, \
            f"\nremove_duplicates({arr}): got length: {
            got_len}, want length: {want_len}\n"
        assert arr_copy[:want_len] == want_prefix, \
            f"\nremove_duplicates({arr}): got prefix: {
            arr_copy[:want_len]}, want prefix: {want_prefix}\n"

    print("ALL IN-PLACE DUPLICATE REMOVAL TEST PROVIDED PASSED. TESTING.")

def runPartitionTests():
    #Problem 27.15 QuickSort Partition Tests
    
    def is_valid_partition(arr, pivot):
    # Find boundaries between sections
        first = 0
        while first < len(arr) and arr[first] < pivot:
            first += 1
        second = first
        while second < len(arr) and arr[second] == pivot:
            second += 1

        # Check that all elements are in their correct sections
        for i in range(first):
            if arr[i] >= pivot:
                return False
        for i in range(first, second):
            if arr[i] != pivot:
                return False
        for i in range(second, len(arr)):
            if arr[i] <= pivot:
                return False
        return True

    tests = [
        # Example 1 from the book
        ([1, 7, 2, 3, 3, 5, 3], 4),
        # Example 2 from the book
        ([1, 7, 2, 3, 3, 5, 3], 3),
        # Additional test cases
        ([], 1),
        ([1], 1),
        ([1, 2], 1),
        ([2, 1], 1),
        ([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5], 4),
    ]
    for arr, pivot in tests:
        arr_copy = arr.copy()  # Make a copy since partition modifies in place
        partition(arr_copy, pivot)
        assert is_valid_partition(arr_copy, pivot), \
            f"\npartition({arr}, {pivot}): got: {arr_copy}\n"
    
    print("ALL PARTITION TEST PROVIDED PASSED.")
    
def runSortColorTests():
    #Problem 27.16 Dutch Flag Problem Tests
    
    tests = [
        # Example from the book
        (list("RWBBWRW"), list("RRWWWBB")),
        # Additional test cases
        ([], []),
        (list("R"), list("R")),
        (list("W"), list("W")),
        (list("B"), list("B")),
        (list("RW"), list("RW")),
        (list("WR"), list("RW")),
        (list("RWB"), list("RWB")),
        (list("RRRWWBBB"), list("RRRWWBBB")),
        (list("BBBWWRRR"), list("RRRWWBBB")),
    ]
    
    for arr, want in tests:
        arr_copy = arr.copy()  # Make a copy since function modifies in place
        sortColors(arr_copy)
        assert arr_copy == want, f"\nsort_colors({arr}): got: {
            arr_copy}, want: {want}\n"
            
    print("ALL DUTCH FLAG PROBLEM TEST PROVIDED PASSED.")

def runPrefixSuffixSwapTests():
    tests = [
        # Example from the book
        (list("badreview"), list("reviewbad")),
        # Additional test cases
        ([], []),
        (list("abc"), list("bca")),
        (list("abcdef"), list("cdefab")),
        (list("123456789"), list("456789123")),
        (list("aaabbbccc"), list("bbbcccaaa")),
    ]
    for arr, want in tests:
        arr_copy = arr.copy()  # Make a copy since swap_prefix_suffix modifies in place
        swapPrefixSuffix(arr_copy)
        assert arr_copy == want, f"\nswap_prefix_suffix({arr}): got: {
            arr_copy}, want: {want}\n"
    
    print("ALL PREFIX-SUFFIX SWAP TEST PROVIDED PASSED.")
    
def runShiftWordToBackTests():
    tests = [
        # Example 1 from the book
        (list("seekerandwriter"), "edit", list("sekeranwreredit")),
        # Example 2 from the book
        (list("bacb"), "ab", list("bcab")),
        # Example 3 from the book
        (list("babc"), "b", list("abcb")),
        # Additional test cases
        ([], "", []),
        (list("a"), "a", list("a")),
        (list("abc"), "", list("abc")),
        (list("hello"), "ho", list("ellho")),
        (list("abcabc"), "abc", list("abcabc")),
    ]
    for arr, word, want in tests:
        arr_copy = arr.copy()  # Make a copy since move_word modifies in place
        moveWord(arr_copy, word)
        assert arr_copy == want, f"\nmove_word({arr}, {word}): got: {
            arr_copy}, want: {want}\n"
    
    print("ALL SHIFT WORD TO BACK TEST PROVIDED PASSED.")
    
if __name__ =="__main__":
    # arr = list("babc")
    # word = "b"
    
    # moveWord(arr, word)
    runShiftWordToBackTests()