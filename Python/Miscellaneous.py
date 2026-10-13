from collections import defaultdict

def romanToInt(s: str) -> int:
    #LeetCode Problem 13 - Roman to Integer
    
    roman_value_dictionary = defaultdict(int)
    
    roman_value_dictionary["I"] = 1
    roman_value_dictionary["V"] = 5
    roman_value_dictionary["X"] = 10
    roman_value_dictionary["L"] = 50
    roman_value_dictionary["C"] = 100
    roman_value_dictionary["D"] = 500
    roman_value_dictionary["M"] = 1000
    
    count_integer = 0
    
    if len(s) == 1:
        count_integer = roman_value_dictionary[s[0]]
        return count_integer
    
    pointer = len(s) - 1
    
    while pointer > 0:
        if roman_value_dictionary[s[pointer - 1]] < roman_value_dictionary[s[pointer]]:
            count_integer += roman_value_dictionary[s[pointer]] - roman_value_dictionary[s[pointer - 1]]
            pointer -= 2 
            continue
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