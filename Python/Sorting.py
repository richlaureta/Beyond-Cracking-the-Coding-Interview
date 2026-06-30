import heapq
from collections import defaultdict
 
def letterOccurrences(word: str) -> list[str]:
    #Problem 31.1 - Sorting by Frequency
    
    letterFrequencyDictionary = defaultdict(int)
    
    for letter in word:
        letterFrequencyDictionary[letter] += 1
    
    maxHeap = []
 
    for key in letterFrequencyDictionary:
        heapq.heappush(maxHeap, (-letterFrequencyDictionary[key], key))
    
    sortedLetterByFrequencyList = []
    
    for index in range(len(maxHeap)):
        sortedLetterByFrequencyList.append(heapq.heappop(maxHeap)[1])
    
    return sortedLetterByFrequencyList

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
    RunAllSortingTests()