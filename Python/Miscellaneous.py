from collections import defaultdict

def romanToInt(s: str) -> int:
    #LeetCode Problem 13 - Roman to Integer
    
    roman_value_dictionary = {
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000
    }
    
    count_integer = 0
        
    pointer = len(s) - 1
    
    while pointer > 0:
        if roman_value_dictionary[s[pointer - 1]] < roman_value_dictionary[s[pointer]]:
            count_integer += roman_value_dictionary[s[pointer]] - roman_value_dictionary[s[pointer - 1]]
            pointer -= 2 
        else:
            count_integer += roman_value_dictionary[s[pointer]]
            pointer -= 1
    
    if pointer == 0:
        count_integer += roman_value_dictionary[s[0]]
        
    return count_integer
    
if __name__ == "__main__":
    #1476
    s = "MCMXCIV"
    print(romanToInt(s))