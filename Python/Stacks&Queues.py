from collections import deque

def compress_array(arr: list[int]) -> list[int]:
    #Problem 32.1 - Compress Array
    
    if not arr:
        return []
    
    numberStack = []
    numberStack.append(arr[0])
    
    for number in arr[1:]:
        if number == numberStack[-1]:
            poppedNumber = numberStack.pop()
            while numberStack and numberStack[-1] == poppedNumber * 2:
                poppedNumber = numberStack.pop()
            numberStack.append(poppedNumber * 2)
            continue

        numberStack.append(number)
    
    return numberStack

def compress_array_k(arr: list[int], k: int) -> list[int]:
    #Problem 32.2 - Compress Array by K
    
    numberStack = []
    kCount = 1
    
    for number in arr:
        if numberStack and numberStack[-1] == number:
            kCount += 1
            if kCount == k:
                for index in range(k - 1):
                    numberStack.pop()
                kProduct = number * k
                lastIndex = len(numberStack) - 1
                kBacktrackCount = 1
                while lastIndex > -1 and kProduct == numberStack[lastIndex]:
                    kBacktrackCount += 1
                    if kBacktrackCount == k:
                        for index in range(k - 1):
                            numberStack.pop()
                        kProduct *= k
                        kBacktrackCount = 1
                    lastIndex -= 1
                numberStack.append(kProduct)
                kCount = 1
                continue 
            numberStack.append(number)
            continue
        
        numberStack.append(number)
        kCount = 1
    
    return numberStack

def current_url(actions: list[list]) -> str:
    #Problem 32.4 - Current URL
    
    url_stack = []
    for action in actions:
        if action[0] != "go":
            popCount = 0
            while popCount != action[1] and len(url_stack) != 1:
                url_stack.pop()
                popCount += 1
            continue
                
        url_stack.append(action[1])
    
    if len(url_stack) == 0:
        return ""
    
    return url_stack[-1]

def current_url_with_forward(actions: list[list]) -> str:
    #Problem 32.5 - Current URL with Forward
    
    url_stack = []
    backed_stack_url = deque()

    for action in actions:
        if action[0] == "go":
            backed_stack_url = deque()
            url_stack.append(action[1])
        elif action[0] == "back":
            pop_count = 0
            while pop_count != action[1] and len(url_stack) != 1:
                backed_stack_url.append(url_stack.pop())
                pop_count += 1
        else:
            pop_count = 0
            while backed_stack_url and pop_count != action[1]:
                url_stack.append(backed_stack_url.popleft())
                pop_count += 1
            
    if len(url_stack) == 0:
        return ""
    
    return url_stack[-1]

def max_balanced_partition(s: str) -> int:
    #Problem 32.6 - Balanced Partition
    
    parenthesis_count = 0
    balanced_partition_count = 0
    
    for parenthesis in s:
        if parenthesis == "(":
            parenthesis_count += 1
        else:
            parenthesis_count -= 1
        
            if parenthesis_count == 0:
                balanced_partition_count += 1
            
    return balanced_partition_count

def custom_brackets(s: str, brackets: list[str]) -> bool:
    #Problem # 32.7 - Custom Brackets
    
    open_close_brackets_dictionary = dict()
    close_brackets_set = set()
    
    for bracket in brackets:
        open_close_brackets_dictionary[bracket[0]] = bracket[1]
        close_brackets_set.add(bracket[1])
    
    bracket_stack = []
    
    for character in s:
        if character in open_close_brackets_dictionary:
            bracket_stack.append(open_close_brackets_dictionary[character])
        elif character in close_brackets_set:
            if not bracket_stack or character != bracket_stack[-1]:
                return False
                        
            bracket_stack.pop()
        
    return len(bracket_stack) == 0

def longest_balanced_subsequence(s: str) -> str:
    #Problem 32.8 - Longest Balanced Subsequence
    
    longest_balanced_indexes = []
    index = 0
    index_to_be_included = []
    
    for parenthesis in s:
        if parenthesis == "(":
            longest_balanced_indexes.append(index)     
        elif len(longest_balanced_indexes) > 0:
            index_to_be_included.append(longest_balanced_indexes.pop())
            index_to_be_included.append(index)
               
        index += 1
    
    index_to_be_included.sort()
    
    parenthesis_list = []
    
    for index in index_to_be_included:
        parenthesis_list.append(s[index])
    
    return  "".join(parenthesis_list)
     
#TESTS

def run_compress_array_tests():
    tests = [
        # Examples from problem description
		([8, 4, 2, 2, 2, 4], [16, 2, 4]),
		([4, 4, 4, 4], [16]),
		([1, 2, 3, 4], [1, 2, 3, 4]),
		
		# Edge cases
		([], []),
		([1], [1]),
		([0, 0], [0]),
		([0, 0, 0, 0], [0]),
		
		# Multiple compression chains
		([1, 1, 2, 2, 3, 3], [4, 2, 6]),
		([2, 2, 2, 2, 2, 2], [8, 4]),
		
		# Alternating numbers
		([1, 2, 1, 2, 1, 2], [1, 2, 1, 2, 1, 2]),
		
		# Numbers that sum to equal another number
		([2, 2, 4], [8]),
		([3, 3, 6, 6], [12, 6]),
		
		# Large numbers within constraints
		([999, 999], [1998]),
		([500, 500, 500, 500], [2000]),
		
		# Mix of different scenarios
		([5, 5, 5, 1, 1, 5], [10, 5, 2, 5]),
  	]
    
    for arr, want in tests:
        got = compress_array(arr)
        assert got == want, f"\ncompress_array({arr}): got: {got}, want: {want}\n"
    
    print("ALL COMPRESS ARRAY TESTS PROVIDED PASSED.")

def run_compress_array_by_k_tests():
    tests = [
        ([1, 9, 9, 3, 3, 3, 4], 3, [1, 27, 4]),
        ([8, 4, 2, 2], 2, [16]),
        ([4, 4, 4, 4], 5, [4, 4, 4, 4]),
        ([], 2, []),
        ([0, 0, 0, 0], 2, [0]),
    ]
    
    for arr, k, want in tests:
        got = compress_array_k(arr, k)
        assert got == want, f"\ncompress_array_k({arr}, {k}): got: {got}, want: {want}\n"

    print("ALL COMPRESS ARRAY BY K TESTS PROVIDED PASSED.")

def run_current_url_tests():
    tests = [
        ([["go", "google.com"], ["go", "wikipedia.com"], ["go", "amazon.com"], ["back", 4], [
        "go", "youtube.com"], ["go", "netflix.com"], ["back", 1]], "youtube.com"),
        ([["go", "example.com"], ["back", 1]], "example.com"),
        ([["go", "site1.com"], ["go", "site2.com"],
        ["back", 1], ["back", 1]], "site1.com"),
    ]
    
    for actions, want in tests:
        got = current_url(actions)
        assert got == want, f"\ncurrent_url({actions}): got: {got}, want: {want}\n"

    print("ALL CURRENT URL TESTS PROVIDED PASSED.")

def run_current_url_with_forward_tests():
    tests = [
        ([["go", "google.com"], ["go", "wikipedia.com"], ["back", 1], ["forward", 1], [
        "back", 3], ["go", "netflix.com"], ["forward", 3]], "netflix.com"),
        ([["go", "example.com"], ["forward", 1]], "example.com"),
        ([["go", "site1.com"], ["go", "site2.com"], [
        "back", 1], ["forward", 1], ["back", 1]], "site1.com"),
    ]
    
    for actions, want in tests:
        got = current_url_with_forward(actions)
        assert got == want, f"\ncurrent_url_with_forward({actions}): got: {got}, want: {want}\n"

    print("ALL CURRENT URL WITH FORWARD TESTS PROVIDED PASSED.")

def run_balanced_partition_tests():
    tests = [
        ("((()))(()())()(()(()))", 4),
        ("()()()", 3),
        ("(((())))", 1),
        ("", 0),
        ("()", 1),
    ]
    
    for s, want in tests:
        got = max_balanced_partition(s)
        assert got == want, f"\nmax_balanced_partition({s}): got: {got}, want: {want}\n"
    
    print("ALL BALANCED PARTITION TESTS PROVIDED PASSED.")

def run_custom_brackets_tests():
    tests = [
        # Example 1 from book
        ("((a+b)*[c-d]-{e/f})", ["()", "[]", "{}"], True),
        # Example 2 from book
        ("()[}", ["()", "[]", "{}"], False),
        # Example 3 from book
        ("([)]", ["()", "[]", "{}"], False),
        # Example 4 from book
        ("<div> hello :) </div>", ["<>", "()"], False),
        # Example 5 from book
        (")))(()((", [")("], True),
        # Empty string
        ("", ["()"], True),
        # Single character
        ("(", ["()"], False),
        # Multiple bracket types
        ("<<>>()[]{}", ["<>", "()", "[]", "{}"], True),
        # Nested brackets
        ("[{()}]", ["()", "[]", "{}"], True),
        # Unmatched opening bracket
        ("(()", ["()"], False),
        # Unmatched closing bracket
        ("())", ["()"], False),
        # Wrong order of closing
        ("({)}", ["()", "{}"], False),
        # Non-bracket characters mixed in
        ("a(b)c[d]e", ["()", "[]"], True),
        # Multiple identical bracket pairs
        ("<<>>", ["<>"], True),
    ]
    
    for s, brackets, want in tests:
        got = custom_brackets(s, brackets)
        assert got == want, f"\ncustom_brackets({s}, {brackets}): got: {got}, want: {want}\n"
    
    print("ALL CUSTOM BRACKETS TESTS PROVIDED PASSED.")

def run_longest_balanced_subsequence_tests():
    tests = [
        ("))(())(()", ["(())()"]),
        ("(()()", ["()()", "(())"]),
        ("(()(()(", ["()()", "(())"]),
        ("())(()", ["()()"]),
        ("(", [""]),
        ("", [""]),
    ]
    
    for s, want in tests:
        got = longest_balanced_subsequence(s)
        assert got in want, f"\nlongest_balanced_subsequence({s}): got: {got}, want: {want}\n"

    print("ALL LONGEST BALANCED SUBSEQUENCE TESTS PROVIDED PASSED.")
  
#ALL TESTS

def Run_All_Stacks_And_Queues_Tests():
    run_compress_array_tests()
    run_compress_array_by_k_tests()
    run_current_url_tests()
    run_current_url_with_forward_tests()
    run_balanced_partition_tests()
    run_custom_brackets_tests()
    run_longest_balanced_subsequence_tests()
    
    print()
    print("----------------------------------------------------------")
    print("ALL INCLUDED STACKS AND QUEUES TESTS IN THE FILE PASSED. |")
    print("----------------------------------------------------------")

if __name__ == "__main__":
    Run_All_Stacks_And_Queues_Tests()