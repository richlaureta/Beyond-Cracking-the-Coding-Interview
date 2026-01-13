#Character Manipulation Problem Set - Page 289

#Question 1: Implement a function is_alphanumeric(c) that returns whether a character c is a lowercase or
#uppercase English letter or a digit between '0' and '9'. Page 289.

def is_lowercase(c: str) -> bool:
	return ord(c) > 96 and ord(c) < 123

def is_uppercase(c: str) -> bool:
    return ord(c) > 64 and ord(c) < 91

def is_numeric(c: str) -> bool:
    return ord(c) > 47 and ord(c) < 58

def is_alphanumeric(c: str) -> bool:
    return is_lowercase(c) or is_uppercase(c) or is_numeric(c)

#Question 2: Implement a function to_uppercase(c) that converts a lowercase character c to uppercase. If c is not a
#lowercase character, the function does nothing. Page 289.

def to_uppercase(c: str) -> str:
    #Question 2: Implement a function to_uppercase(c) that converts a lowercase character c to uppercase. If c is not a
	#lowercase character, the function does nothing. Page 289.
    if is_lowercase(c):
        return chr(ord(c) - 32)
    
    return c

def split(s: str, c: str) -> list[str]:
    #Problem 26.1 String Split: Without using a built-in string split method, implements a split(s, c) 
    #method, which recieves an array of strings, arr, and a string, s, and returns a single string 
    #consisting of the strings in arr with s in between them.
    
    if len(s) == 0:
        return []
    
    splitArray = []
    tempString = ""
    
    for index, character in enumerate(s):
        if character == c:
            if index > 0 and s[index - 1] == c:
                splitArray.append("")
                continue
            splitArray.append(tempString)
            tempString = ""
            continue
        
        tempString += character
    
    splitArray.append(tempString)
    
    return splitArray
    
if __name__ == "__main__":
    s = ""
    c = '?'
    print(s.split('?'))
    print(split(s, c))