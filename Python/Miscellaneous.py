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
        
    pointer = 0
    
    while pointer < len(s) - 1:
        if roman_value_dictionary[s[pointer + 1]] > roman_value_dictionary[s[pointer]]:
            count_integer += roman_value_dictionary[s[pointer + 1]] - roman_value_dictionary[s[pointer]]
            pointer += 2 
        else:
            count_integer += roman_value_dictionary[s[pointer]]
            pointer += 1
    
    if pointer == len(s) - 1:
        count_integer += roman_value_dictionary[s[len(s) - 1]]
        
    return count_integer
    
if __name__ == "__main__":
    s = "MCMXCIV"
    print(romanToInt(s))