from collections import defaultdict
 
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
    
    currentMaxX = float('-inf')
    currentMaxXIndex = None
    currentMinimumX = float('inf')
    currentMinimumXIndex = None
    
    currentMaxY = float('-inf')
    currentMaxYIndex = None
    currentMinimumY = float('inf')
    currentMinimumYIndex = None
    
    currentMaxRadiusHigherX = None
    currentMaxRadiusHigherY = None
    currentMaxRadiusLowerX = None
    currentMaxRadiusLowerY = None
    currentMaxRadiusIndex = None
    
    currentMaxRadius = float('-inf')
    
    
    for index in range(len(circles)):
        if currentMaxRadius < abs(circles[index][1]):
            currentMaxRadius = abs(circles[index][1])
            currentMaxRadiusIndex = index
            currentMaxRadiusHigherX = circles[index][0][0] + abs(circles[index][1])
            currentMaxRadiusHigherY = circles[index][0][1] + abs(circles[index][1])
            currentMaxRadiusLowerX = circles[index][0][0] - abs(circles[index][1])
            currentMaxRadiusLowerY = circles[index][0][1] - abs(circles[index][1])
        
        if circles[index][0][0] + abs(circles[index][1]):
            currentMaxX = circles[index][0][0] + abs(circles[index][1])
            currentMaxXIndex = index
            
        if currentMinimumX >= circles[index][0][0] - abs(circles[index][1]):
            currentMinimumX = circles[index][0][0] - abs(circles[index][1])
            currentMinimumXIndex = index
        
        if currentMaxY <= circles[index][0][1] + abs(circles[index][1]):
            currentMaxY = circles[index][0][1] + abs(circles[index][1])
            currentMaxYIndex = index
        
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

#ALL TESTS

def RunAllSortingTests():
    runSortByFrequencyTests()
    
    print()
    print("------------------------------------------------")
    print("ALL INCLUDED SORTING TESTS IN THE FILE PASSED. |")
    print("------------------------------------------------")
  
if __name__ == "__main__":
    circles = [
        ((4, 4), 5),
        ((8, 4), 2)
    ]
    
    print(areCirclesNested(circles))