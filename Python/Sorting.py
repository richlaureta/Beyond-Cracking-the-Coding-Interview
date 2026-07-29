from collections import defaultdict
from operator import itemgetter
from operator import attrgetter
import copy
import heapq
import random

def letterOccurrences(word: str) -> list[str]:
    #Problem 31.1 - Sorting by Frequency
    
    letterFrequencyDictionary = defaultdict(int)
    
    for letter in word:
        letterFrequencyDictionary[letter] += 1
    
    willSortList = []
 
    for key in letterFrequencyDictionary:
        willSortList.append((-letterFrequencyDictionary[key], key))
    
    willSortList.sort()
    
    sortedLetterByFrequencyList = []
    
    for index in range(len(willSortList)):
        sortedLetterByFrequencyList.append(willSortList[index][1])
    
    return sortedLetterByFrequencyList

def areCirclesNested(circles: list[tuple]) -> bool:
    #Problem 31.2 - Nested Circles
    
    if len(circles) == 1 or len(circles) == 0:
        return True
    
    circles.sort(key = itemgetter(1))
    
    previousX = circles[0][0][0]
    previousY = circles[0][0][1]
    previousRadius = abs(circles[0][1])
    
    for index in range(1, len(circles)):
        if previousX + previousRadius >= circles[index][0][0] + abs(circles[index][1]):
            return False
        
        if previousX - previousRadius <= circles[index][0][0] - abs(circles[index][1]):
            return False

        if previousY + previousRadius >= circles[index][0][1] + abs(circles[index][1]):
            return False
        
        if previousY - previousRadius <= circles[index][0][1] - abs(circles[index][1]):
            return False
        
        previousX = circles[index][0][0]
        previousY = circles[index][0][1]
        previousRadius = abs(circles[index][1])
    
    return True

def processOperations(nums: list[int], operations: list[int]) -> list[int]:
    #Problem 31.3 Delete Operations

    if len(operations) == 0:
        return nums
    
    numberIndexList = []
    for index in range(len(nums)):
        numberIndexList.append((nums[index], index))
    
    numberIndexList.sort()
    minimumIndex = 0
    removeIndexSet = set()
    
    for index in range(len(operations)):
        if operations[index] == -1:
            while numberIndexList[minimumIndex][1] in removeIndexSet:
                minimumIndex += 1
            removeIndexSet.add(numberIndexList[minimumIndex][1])
            minimumIndex += 1
        else:
            removeIndexSet.add(operations[index])
    
    outputNumberList = []
    
    for index in range(len(nums)):
        if index not in removeIndexSet:
            outputNumberList.append(nums[index])
            
    return outputNumberList

class Spreadsheet:
    #Problem 31.4 - Spreadsheet
    
    def __init__(self, rows: int = 0, cols: int = 0):
        self.spreadsheetTemplate = [[0 for square in range(cols)] for row in range(rows)]
    
    def new(self, rows: int, cols: int):
        if rows < 1 or rows > 100 or cols < 1 or cols > 100:
            raise ValueError("Rows and columns have to be more than 0 and less than 101.")
        
        self.spreadsheetTemplate = [[0 for square in range(cols)] for row in range(rows)]
    
    def set(self, row: int, col: int, value: int):
        if self.spreadsheetTemplate == []:
            raise ValueError("You have to set a new matrix template using the new() function.")
        
        if row < 0 or row > len(self.spreadsheetTemplate) - 1 or col < 0 or col > len(self.spreadsheetTemplate[0]) - 1:
            raise ValueError("row value or col value are out of range.")
        
        self.spreadsheetTemplate[row][col] = value
    
    def get(self, row: int, col: int) -> int:
        if self.spreadsheetTemplate == []:
            raise ValueError("You have to set a new matrix template using the new() funtion.")
        
        if row < 0 or row > len(self.spreadsheetTemplate) - 1 or col < 0 or col > len(self.spreadsheetTemplate[0]) - 1:
            raise ValueError("row value or col value are out of range.")
        
        return self.spreadsheetTemplate[row][col]

    def sortColumnsByRow(self, row: int):
        if self.spreadsheetTemplate == []:
            raise ValueError("You have to set a new matrix template using the new() funtion.")
        
        if row < 0 or row > len(self.spreadsheetTemplate) - 1:
            raise ValueError("row value out of range.")
        
        columnSortList = []
        for index in range(len(self.spreadsheetTemplate[row])):
            columnSortList.append((self.spreadsheetTemplate[row][index], index))
        
        columnSortList.sort()
        
        temporaryCopySpreadsheet = copy.deepcopy(self.spreadsheetTemplate)
        
        columnIndex = 0
        for value, index in columnSortList:
            for index1 in range(len(self.spreadsheetTemplate)):
                self.spreadsheetTemplate[index1][columnIndex] = temporaryCopySpreadsheet[index1][index]
            columnIndex += 1

        del temporaryCopySpreadsheet

    def sortRowsByColumn(self, col: int):
        if self.spreadsheetTemplate == []:
            raise ValueError("You have to set a new matrix template using the new() funtion.")
        
        if col < 0 or col > len(self.spreadsheetTemplate[0]) - 1:
            raise ValueError("col value out of range.")
        
        rowSortList = []
        for index in range(len(self.spreadsheetTemplate)):
            rowSortList.append((self.spreadsheetTemplate[index][col], index))
        
        rowSortList.sort()
        
        temporayCopySpreadsheet = copy.deepcopy(self.spreadsheetTemplate)
        
        rowIndex = 0
        for value, index in rowSortList:
            for index1 in range(len(self.spreadsheetTemplate[index])):
                self.spreadsheetTemplate[rowIndex][index1] = temporayCopySpreadsheet[index][index1]
            rowIndex += 1
        
        del temporayCopySpreadsheet

class Book:
    #Problem 31.5 - Sort by Publication Year
    
    def __init__(self, title: str, author: str, page_count: int, genre: str, year_published: int):
        self.title = title
        self.author = author
        self.page_count = page_count
        self.genre = genre
        self.year_published = year_published

def bucketSort(books: list[Book]) -> list[Book]:
    #Problem 31.5 - Sort by Publication Year
    
    sortedByYearBooks = sorted(books, key=attrgetter('year_published'))
    
    return sortedByYearBooks

def first_k_sorting(arr: list[int], k: int) -> list[int]:
    #Problem 31.6 - First K

    arr.sort()
    
    firstKList = []
    for index in range(k):
        firstKList.append(arr[index])
        
    return firstKList

#TESTS

def letter_occurrences_lambda(word):
    #Part of 31.1 - Sorting by Frequency Problem Tests
    
    letter_to_count = dict()
    res = []
    
    for c in word:
        if c not in letter_to_count:
            letter_to_count[c] = 0
            res.append(c)
        letter_to_count[c] += 1
    res.sort(key=lambda x: (-letter_to_count[x], x))
    return res

def runSortByFrequencyTests():
    tests = [
        # Example from the book
		("supercalifragilisticexpialidocious",
		['i', 'a', 'c', 'l', 's', 'e', 'o', 'p', 'r', 'u', 'd', 'f', 'g', 't', 'x']),
		# Edge case - empty string
		("", []),
		# Edge case - single character
		("a", ["a"]),
		# Edge case - all same frequency
		("abc", ["a", "b", "c"]),
		# Multiple frequencies with ties
		("aabbbcccc", ["c", "b", "a"]),
		# All same character
		("zzzzz", ["z"]),
		# Alternating characters
		("ababab", ["a", "b"]),
		# Reverse alphabetical order but same frequency
		("zyxwv", ["v", "w", "x", "y", "z"]),
		# Long string with many frequencies
		("aaaaabbbbbbbcccccccccdddddddddddeeeeeeeeeeee",
			["e", "d", "c", "b", "a"]),
  	]
    
    for word, want in tests:
        got1 = letterOccurrences(word)
        assert got1 == want, (
			f"\nletter_occurrences({word}): got: {got1}, want: {want}\n")
        got2 = letter_occurrences_lambda(word)
        assert got2 == want, (
			f"\nletter_occurrences_lambda({word}): got: {got2}, want: {want}\n")
    
    print("ALL SORT BY FREQUENCY TESTS PROVIDED HAVE PASSED.")

def runNestedCirclesTests():
    tests = [
        # Example 1 from the book
        ([((4, 4), 5), ((8, 4), 2)], False),
        # Example 2 from the book
        ([((5, 3), 3), ((5, 3), 2), ((4, 4), 5)], True),
        # Example 3 from the book
        ([((5, 3), 3)], True),
        # Edge case - two identical circles
        ([((1, 1), 2), ((1, 1), 2)], False),
        # Edge case - touching circles
        ([((0, 0), 4), ((0, 0), 2)], True),
        # Edge case - empty list
        ([], True),
        # Edge case - negative coordinates
        ([((-5, -3), 4), ((-5, -3), 2)], True),
        # Edge case - negative radius
        ([((0, 0), -2)], True),
        # Edge case - max coordinate values
        ([((10000, 10000), 10000), ((0, 0), 100)], False),
        # Edge case - min coordinate values
        ([((-10000, -10000), 10000), ((0, 0), 100)], False),
        # Edge case - multiple circles with same center
        ([((1, 1), 5), ((1, 1), 4), ((1, 1), 3), ((1, 1), 2)], True),
        # Edge case - circles not sorted by radius
        ([((0, 0), 2), ((0, 0), 4), ((0, 0), 3)], True),
    ]
    
    for circles, want in tests:
        got = areCirclesNested(circles)
        assert got == want, f"\nare_circles_nested({circles}): got: {got}, want: {want}\n"
    
    print("ALL NESTED CIRCLES TESTS PROVIDED HAVE PASSED.")

def runDeleteOperationsTests():
    tests = [
        # Example 1 from the book
        ([50, 30, 70, 20, 80], [2, -1, 4, -1], [50]),
        # Example 2 from the book
        ([1, 2, 3], [], [1, 2, 3]),
        # Example 3 from the book
        ([1, 2, 3], [-1, -1, -1], []),
        # Edge case - delete all indices
        ([1, 2, 3], [0, 1, 2], []),
        # Edge case - single element
        ([1], [-1], []),
        # Edge case - duplicates
        ([5, 5, 5], [-1, -1], [5]),
        # Edge case - negative numbers
        ([-3, -2, -1], [-1, -1], [-1]),
        # Mixed operations with duplicates
        ([10, 10, 20, 20], [1, -1, -1], [20]),
        # Operations targeting same index
        ([1, 2, 3], [0, 0, 0], [2, 3]),
        # Alternating index and min operations
        ([5, 4, 3, 2, 1], [2, -1, 0, -1], [4]),
        # Large numbers within constraints
        ([10**9, -(10**9), 0], [-1, -1], [10**9])
    ]
    
    for nums, operations, want in tests:
        got = processOperations(nums, operations)
        assert got == want, f"\nprocessOperations({nums}, {operations}): got: {got}, want: {want}\n"

    print("ALL DELETE OPERATIONS TESTS PROVIDED HAVE PASSED.")

def runSpreadsheetTests():
    tests = [
        # Example from the book
        (lambda s: [
            s.new(3, 3),
            s.set(0, 0, 5),
            s.set(0, 1, 3),
            s.set(0, 2, 8),
            s.set(1, 0, 6),
            s.set(2, 1, 1),
            s.sortColumnsByRow(0),
            s.sortRowsByColumn(1)
        ], [
            [1, 0, 0],
            [3, 5, 8],
            [0, 6, 0],
        ]),
        # Edge case - 1x1 spreadsheet
        (lambda s: [
            s.new(1, 1),
            s.set(0, 0, 42)
        ], [
            [42],
        ]),
        # Edge case - sort empty rows
        (lambda s: [
            s.new(3, 2),
            s.sortRowsByColumn(0)
        ], [
            [0, 0],
            [0, 0],
            [0, 0],
        ]),
    ]
    
    for operations, want in tests:
        s = Spreadsheet(0, 0)
        operations(s)
        for r in range(len(want)):
            for c in range(len(want[0])):
                got = s.get(r, c)
                expect = want[r][c]
                assert got == expect, f"\nget({r}, {c}): got: {got}, want: {expect}\n"
    
    print("ALL SPREADSHEET TESTS PROVIDED HAVE PASSED.")

def runSortByPublicationYearTests():
    tests = [
        # Example from the book
        ([
        Book("Shadow of Tomorrow", "Elliot Greyson", 350, "Science Fiction", 2020),
        Book("Whispers in the Wind", "Lila Hart", 280, "Romance", 2018),
        Book("Echoes of Eternity", "Mara Vance", 420, "Fantasy", 2018),
        Book("Fragments of Dawn", "Cora Blake", 310, "Mystery", 2019),
        Book("Beneath the Starlit Sky", "Aria Monroe", 270, "Drama", 2020)
        ], [2018, 2018, 2019, 2020, 2020]),
        # Edge case - empty list
        ([], []),
        # Edge case - single book
        ([Book("Solo", "Author", 100, "Genre", 2000)], [2000]),
        # Multiple books with the same year
        ([
        Book("A", "Author1", 100, "Genre", 2000),
        Book("B", "Author2", 200, "Genre", 2000),
        ], [2000, 2000]),
        # Reverse sorted years
        ([
        Book("A", "Author1", 100, "Genre", 2020),
        Book("B", "Author2", 200, "Genre", 2019),
        Book("C", "Author3", 300, "Genre", 2018),
        ], [2018, 2019, 2020]),
        # Large gap between years
        ([
        Book("A", "Author1", 100, "Genre", 1000),
        Book("B", "Author2", 200, "Genre", 2025),
        ], [1000, 2025]),
        # Many books same year
        ([Book(f"Book{i}", f"Author{i}", 100, "Genre", 2000) for i in range(10)],
        [2000] * 10),
    ]
    
    for books, want_years in tests:
        got = bucketSort(books)
        got_years = [book.year_published for book in got]
        assert got_years == want_years, f"\nbucket_sort({[b.title for b in books]}): got years: {got_years}, want years: {want_years}\n"
        # Verify that all books are preserved
        assert len(got) == len(books), f"\nbucket_sort: got length {len(got)}, want length {len(books)}\n"
        assert set(b.title for b in got) == set(b.title for b in books), f"\nbucket_sort: some books were lost or duplicated\n"

    print("ALL SORT BY PUBLICATION YEAR TESTS PROVIDED HAVE PASSED.")

def first_k_min_heap(arr, k):
    #Part of the 31.6 - First K Problem
     
    heapq.heapify(arr)
    return [heapq.heappop(arr) for _ in range(k)]

def first_k_max_heap(arr, k):
    #Part of the 31.6 - First K Problem
    
    max_heap = []
    for num in arr:
        heapq.heappush(max_heap, -num)  # Negate values to simulate a max-heap
        if len(max_heap) > k:
            heapq.heappop(max_heap)
    return [-x for x in max_heap]

def partition(arr):
    pivot = random.choice(arr)
    smaller, equal, larger = [], [], []
    for x in arr:
        if x < pivot:
            smaller.append(x)
        elif x == pivot:
            equal.append(x)
        else:
            larger.append(x)
    return smaller, equal, larger

def quickselect(arr, k):
    #Part of the 31.6 - First K Problem
    
    smaller, equal, larger = partition(arr)
    S, E = len(smaller), len(equal)

    if k <= S:
        return quickselect(smaller, k)
    elif k <= S + E:
        return equal[0]
    else:
        return quickselect(larger, k - S - E)

def first_k_quickselect(arr, k):
    #Part of the 31.6 - First K Problem
    if not arr:
        return []
    kth_val = quickselect(arr, k)
    return [x for x in arr if x <= kth_val]

def run_first_k_tests():
    tests = [
        # Example from the book
        ([15, 4, 13, 8, 10, 5, 2, 20, 3, 9, 11, 27], 5, [2, 3, 4, 5, 8]),
        # Edge case - k = 1
        ([5, 2, 1, 3, 4], 1, [1]),
        # Edge case - k = length of array
        ([3, 1, 2], 3, [1, 2, 3]),
        # Edge case - array of length 1
        ([42], 1, [42]),
        # Reverse sorted array
        ([5, 4, 3, 2, 1], 4, [1, 2, 3, 4]),
        # Already sorted array
        ([1, 2, 3, 4, 5], 3, [1, 2, 3]),
        # Edge case - empty array
        ([], 0, []),
        # Array with negative numbers
        ([-3, -1, -4, -2], 3, [-4, -3, -2]),
        # Mix of positive and negative
        ([-5, 3, -2, 8, -1], 4, [-5, -2, -1, 3]),
        # Large numbers
        ([10**9, -(10**9), 0], 2, [-(10**9), 0])
    ]
    
    solutions = [
        ('first_k_sorting', first_k_sorting),
        ('first_k_max_heap', first_k_max_heap),
        ('first_k_min_heap', first_k_min_heap),
        ('first_k_quickselect', first_k_quickselect)
    ]
    
    for name, solution in solutions:
        for arr, k, want in tests:
            got = solution(arr.copy(), k)
            assert sorted(got) == sorted(
            want), f"\n{name}({arr}, {k}): got: {got}, want: {want} (in any order)\n"
    
    print("ALL FIRST K TESTS PROVIDED HAVE PASSED.")
       
#ALL TESTS

def RunAllSortingTests():
    runSortByFrequencyTests()
    runNestedCirclesTests()
    runDeleteOperationsTests()
    runSpreadsheetTests()
    runSortByPublicationYearTests()
    run_first_k_tests()
    
    print()
    print("----------------------------------------------------")
    print("ALL INCLUDED SORTING TESTS IN THE FILE HAVE PASSED. |")
    print("----------------------------------------------------")
  
if __name__ == "__main__":
    RunAllSortingTests()