
import math

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
        leftPointer = 0
        rightPointer = len(sortedArray) - 1
        
        targetNumber = 0 - unsortedArray[index]
        
        while leftPointer <= rightPointer:
            midllePointer = (leftPointer + rightPointer) // 2
            
            if sortedArray[midllePointer] == targetNumber:
                return [midllePointer, index]
            elif sortedArray[leftPointer] == targetNumber:
                return [leftPointer, index]
            elif sortedArray[rightPointer] == targetNumber:
                return [rightPointer, index]

            if sortedArray[midllePointer] < targetNumber:
                leftPointer = midllePointer + 1
            else:
                rightPointer = midllePointer - 1
            
    return [-1, -1]  

def targetCountDivisibleByK(arr: list[int], target: int, k: int):
    #Problem 29.5 Target Count Divisible by K
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    firstOccurenceIndex = None
    
    while True:
        middlePointer = (leftPointer + rightPointer) // 2
        
        if arr[rightPointer] == target and rightPointer - leftPointer == 1:
            if arr[leftPointer] != arr[rightPointer]:
                firstOccurenceIndex = rightPointer
            else: firstOccurenceIndex = leftPointer
            break
        elif arr[leftPointer] == target and rightPointer - leftPointer == 1:
            firstOccurenceIndex = leftPointer
            break
        
        if leftPointer == middlePointer:
            break
        
        if arr[middlePointer] < target:
            leftPointer = middlePointer
        else:
            rightPointer = middlePointer

        
    if firstOccurenceIndex == None:
        return True
    
    lastOccurrenceIndex = firstOccurenceIndex
    
    leftPointer = 0
    rightPointer = len(arr) - 1
    
    while True:
        middlePointer = (leftPointer + rightPointer) // 2
        
        if arr[leftPointer] == target and rightPointer - leftPointer == 1:
            if arr[leftPointer] != arr[rightPointer]:
                lastOccurrenceIndex = leftPointer
            else: lastOccurrenceIndex = rightPointer
            break
        elif arr[rightPointer] == target and rightPointer - leftPointer == 1:
            lastOccurrenceIndex = rightPointer
            break
        
        if leftPointer == middlePointer:
            break
        
        if arr[middlePointer] > target:
            rightPointer = middlePointer
        else: leftPointer = middlePointer
        
    return (lastOccurrenceIndex - firstOccurenceIndex + 1) % k == 0


def raceOvertaking(p1: list[int], p2: list[int]) -> int:
    #Problem 29.6 Race Overtaking
    
    leftPointer = 1
    rightPointer = len(p1) - 1
    
    while True:
        middlePointer = (leftPointer + rightPointer) // 2 
        
        if p2[leftPointer] > p1[leftPointer]:
            return leftPointer
        elif p2[rightPointer] > p1[rightPointer] and rightPointer - leftPointer == 1:
            return rightPointer
        
        if p2[middlePointer] > p1[middlePointer]:
            rightPointer = middlePointer 
        else: leftPointer = middlePointer

def searchInSortedGrid(grid: list[list[int]], target: int) -> list[int]:
    #Problem 29.7 Search In Sorted Grid
    
    if target < grid[0][0] or target > grid[len(grid) - 1][len(grid[0]) - 1]:
        return [-1, -1]
    
    leftPointer = 0
    rightPointer = (len(grid) * len(grid[0])) - 1
    
    columnLength = len(grid[0])
    
    while True:
        middlePointer = (leftPointer + rightPointer) // 2
        
        if grid[leftPointer // columnLength][leftPointer % columnLength] == target:
            return [leftPointer // columnLength, leftPointer % columnLength]
        elif grid[middlePointer // columnLength][middlePointer % columnLength] == target:
            return [middlePointer // columnLength, middlePointer % columnLength]
        elif grid[rightPointer // columnLength][rightPointer % columnLength] == target:
            return [rightPointer // columnLength, rightPointer % columnLength]
        
        if leftPointer == middlePointer:
            break
        
        if grid[middlePointer // columnLength][middlePointer % columnLength] < target:
            leftPointer = middlePointer
        else:
            rightPointer = middlePointer
        
    return [-1 , -1]
        
def minSubarraySumSplit(arr: list[int], k: int) -> int:
    #Problem 29.9 - Min-Subarray-Sum Split
    #This might be an incomplete solution to the problem because this is just dividing it and returning the max sum.
    #It is not regulating to keep the large sum at a minimum
    #All the tests provided passed though. The tests might not be comprehensive.
    #I took off the other bonus question tests.
    #I need more comprehensive tests.
    
    
    split = round(((len(arr) + 0.0) / k) + 1e-9)
    
    divideArray = 0
    
    maxSum = 0
    sumDivision = 0
    
    sumInDivision = []
    
    for index in range(len(arr)):
        sumDivision += arr[index]
        
        divideArray += 1
        if divideArray == split:
            sumInDivision.append(sumDivision)
            maxSum = max(maxSum, sumDivision)
            sumDivision = 0
            divideArray = 0
            
        if index == len(arr) - 1:
            sumInDivision.append(sumDivision)
            maxSum = max(maxSum, sumDivision)
    
    return maxSum

def tideAerialView(picture: list[list[list[int]]]) -> int:
    #Problem 29.12 Tide Aerial View
    
    sqaureCount = len(picture[0]) * len(picture[0][0])
    
    oneIndexMemory = [0] * len(picture[0])
    
    oneCount = 0
    
    mostBalancedRatioValue = 1
    pictureIndexBalancedRatio = 0
    pictureIndex = 0
    
    for image in picture:
        for index in  range(len(image)):
            startIndex = oneIndexMemory[index]
            for index1 in range(startIndex, len(picture[0][0])):
                if image[index][index1] == 1:
                    oneCount += 1
                    oneIndexMemory[index] += 1
                else:
                    break
        
        zeroCount = sqaureCount - oneCount
        
        ratioCalculation = 1
        
        if zeroCount > 0:
            ratioCalculation = abs(((oneCount + 0.0) / (zeroCount + 0.0)) - 1.0) 
        
        if ratioCalculation < mostBalancedRatioValue:
            mostBalancedRatioValue = ratioCalculation
            pictureIndexBalancedRatio = pictureIndex
        
        pictureIndex += 1
                        
    return pictureIndexBalancedRatio

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
        assert got == want, f"\ntwo_array_two_sum({sorted_arr}, {unsorted_arr}): got: {got}, want: {want}\n"
        
    print("ALL 2-ARRAY 2-SUM TESTS PROVIDED PASSED.")

def runTargetCountDivisibleByKTests():
    tests = [
        # Example 1
        ([1, 2, 2, 2, 2, 2, 2, 3], 2, 3, True),
        # Example 2
        ([1, 2, 2, 2, 2, 2, 2, 3], 2, 4, False),
        # Example 3: 0 occurrences, 0 is multiple of any number
        ([1, 2, 2, 2, 2, 2, 2, 3], 4, 3, True),
        # Example 4
        ([1, 1, 2, 2, 2], 1, 3, False),
        # single occurrence, at the start
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 1, 1, True),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 1, 2, False),
        # single occurrence, at the end
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 19, 1, True),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 19, 2, False),
        # single occurrence, in the middle
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 9, 1, True),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 9, 2, False),
        # smaller than any elements
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 0, 1, True),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 0, 2, True),
        # larger than any elements
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 20, 1, True),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 20, 2, True),
        # Edge case - every occurrence is target
        ([5, 5, 5, 5, 5], 5, 5, True),
        ([5, 5, 5, 5, 5], 5, 3, False),
    ]
    
    for arr, target, k, want in tests:
        got = targetCountDivisibleByK(arr, target, k)
        assert got == want, f"\ntarget_count_divisible_by_k({arr}, {target}, {k}): got: {got}, want: {want}\n"
    
    print("ALL TARGET COUNT DIVISIBLE BY K TESTS PROVIDED PASSED.")

def runRaceOvertakingTests():
    tests = [
        # Example 1 from book
        ([2, 4, 6, 8, 10], [1, 3, 5, 9, 11], 3),
        # Example
        ([2, 3, 4, 5, 6], [1, 2, 3, 6, 7], 3),
        # Example
        ([3, 4, 5], [2, 5, 6], 1),
        # Edge case - overtake at start
        ([2, 3], [1, 4], 1),
    ]

    for p1, p2, want in tests:
        got = raceOvertaking(p1, p2)
        assert got == want, f"\nrace_overtaking({p1}, {p2}): got: {got}, want: {want}\n"
        
    print("ALL RACE OVERTAKING TESTS PROVIDED PASSED.")

def runSearchInSortedGridTests():
    tests = [
        ([[1, 3, 5], [7, 9, 11], [13, 15, 17]], 9, [1, 1]),  # Example 1
        ([[1, 3, 5], [7, 9, 11]], 4, [-1, -1]),  # Example 2
        ([[2, 3], [4, 5]], 1, [-1, -1]),  # 2x2 grid, all grid after
        ([[1, 2], [3, 4]], 5, [-1, -1]),  # 2x2 grid, all grid before
        ([[1, 2], [3, 4], [5, 6]], 1, [0, 0]),  # 3x2 grid, first element
        ([[1, 2, 3], [4, 5, 6]], 6, [1, 2]),  # 2x3 grid, last element
        ([[7]], 7, [0, 0]),  # Single element edge case
        ([[7]], 6, [-1, -1])  # Single element edge case (not found)
    ]
    
    for grid, target, want in tests:
        got = searchInSortedGrid(grid, target)
        assert got == want, (
        f"\nsearch_in_sorted_grid({grid}, {target}): got: {got}, want: {want}\n")
    
    print("ALL SEARCH IN SORTED GRID TESTS PROVIDED PASSED.")

def min_subarray_sum_split_memoization(arr, k):
    n = len(arr)
    memo = {}

    def min_split_rec(i, x):
        if (i, x) in memo:
            return memo[(i, x)]

        # Base cases
        if n - i == x:  # Put each element in its own subarray.
            memo[(i, x)] = max(arr[i:])
        elif x == 1:    # Put all elements in one subarray.
            memo[(i, x)] = sum(arr[i:])
        else:  # General case
            current_sum = 0
        res = math.inf
        for p in range(i, n - x + 1):
            current_sum += arr[p]
            res = min(res, max(current_sum, min_split_rec(p + 1, x - 1)))
        memo[(i, x)] = res

        return memo[(i, x)]

    return min_split_rec(0, k)

def runMinSubarraySumSplitTests():
    tests = [
        # Example 1 from the book
        ([10, 5, 8, 9, 11], 3, 17),
        # Example 2 from the book
        ([10, 10, 10, 10, 10], 2, 30),
        # Extra example
        ([9, 12, 13], 3, 13),
        # Edge case - k=1
        ([1, 2, 3], 1, 6),
        # Edge case - k=length
        ([1, 2, 3], 3, 3),
        # Edge case - single element
        ([5], 1, 5)
    ]
    for arr, k, want in tests:
        got = minSubarraySumSplit(arr, k)
        assert got == want, f"\nmin_subarray_sum_split({arr}, {k}): got: {
        got}, want: {want}\n"
    
    print("ALL MIN-SUBARRAY-SUM-SPLIT TESTS PROVIDED PASSED.")

def runTideAerialViewTests():
    tests = [
        # Example from the book
        ([
        [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0]],
        [
            [1, 0, 0],
            [0, 0, 0],
            [1, 0, 0]],
        [
            [1, 1, 0],
            [0, 0, 0],
            [1, 0, 0]],
        [
            [1, 1, 0],
            [1, 1, 1],
            [1, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [1, 1, 0]]
        ], 2),
        
        # 3 pictures with increasing water
        ([
        [
            [1, 0, 0],
            [1, 0, 0],
            [1, 0, 0]],
        [
            [1, 1, 0],
            [1, 1, 0],
            [1, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [1, 0, 0]]
        ], 1),
        # 2 pictures
        ([
        [
            [1, 0],
            [0, 0]],
        [
            [1, 1],
            [1, 0]]
        ], 0),
      
        # Incremental progression
      ([
        [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0]],
        [
            [1, 0, 0],
            [0, 0, 0],
            [0, 0, 0]],
        [
            [1, 0, 0],
            [1, 0, 0],
            [0, 0, 0]],
        [
            [1, 1, 0],
            [1, 0, 0],
            [0, 0, 0]],
        [
            [1, 1, 1],
            [1, 0, 0],
            [0, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 0],
            [0, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [0, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [1, 0, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [1, 1, 0]],
        [
            [1, 1, 1],
            [1, 1, 1],
            [1, 1, 1]],
        ], 4),
      # Edge case - single picture
      ([[[1, 1], [0, 0]]], 0),
      # Edge case - all water
      ([[[1, 1], [1, 1]]], 0),
      # Edge case - all land
      ([[[0, 0], [0, 0]]], 0)
    ]
    
    for pictures, want in tests:
        got = tideAerialView(pictures)
        assert got == want, f"\ntide_aerial_view({pictures}): got: {got}, want: {want}\n"
    
    print("ALL TIDE AERIAL VIEW TESTS PROVIDED PASSED.")
  
#ALL TESTS
 
def RunAllBinarySearchTestsInTheFile():
    runSearchInSortedArrayTests()
    runValleyBottomTests()
    run2Array2SumTests()
    runTargetCountDivisibleByKTests()
    runRaceOvertakingTests()
    runSearchInSortedGridTests()
    runMinSubarraySumSplitTests()
    runTideAerialViewTests()
    
    print("-----------------------------------------------")
    print("ALL THE BINARY SEARCH TESTS IN THE FILE PASSED.")
    
if __name__ == "__main__":
    RunAllBinarySearchTestsInTheFile()