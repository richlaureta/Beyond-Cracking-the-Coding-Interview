from collections import defaultdict
from operator import itemgetter

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
        addPreviousX = previousX + previousRadius
        addCurrentX = circles[index][0][0] + abs(circles[index][1])
        if previousX + previousRadius >= circles[index][0][0] + abs(circles[index][1]):
            return False
        
        subtractPreviousX = previousX - previousRadius
        subtractCurrentX = circles[index][0][0] - abs(circles[index][1])
        if previousX - previousRadius <= circles[index][0][0] - abs(circles[index][1]):
            return False
        
        addPreviousY = previousY + previousRadius
        addCurrentY = circles[index][0][1] + abs(circles[index][1])
        if previousY + previousRadius >= circles[index][0][1] + abs(circles[index][1]):
            return False
        
        subtractPreviousY = previousY - previousRadius
        subtractcurrentY = circles[index][0][1] - abs(circles[index][1])
        if previousY - previousRadius <= circles[index][0][1] - abs(circles[index][1]):
            return False
        
        previousX = circles[index][0][0]
        previousY = circles[index][0][1]
        previousRadius = abs(circles[index][1])
    
    return True

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
    
    print("ALL SORT BY FREQUENCY TESTS PROVIDED PASSED.")

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
    
    print("ALL NESTED CIRCLES TESTS PROVIDED PASSED.")

#ALL TESTS

def RunAllSortingTests():
    runSortByFrequencyTests()
    runNestedCirclesTests()
    
    print()
    print("------------------------------------------------")
    print("ALL INCLUDED SORTING TESTS IN THE FILE PASSED. |")
    print("------------------------------------------------")
  
if __name__ == "__main__":
    runNestedCirclesTests()