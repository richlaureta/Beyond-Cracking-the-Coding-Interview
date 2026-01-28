from collections import defaultdict
import random
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
    tempArray = []
    
    for index, character in enumerate(s):
        if character == c:
            if s[index - 1] == c:
                splitArray.append("")
                continue
            splitArray.append(''.join(tempArray))
            tempArray = []
            continue
        
        tempArray.append(character)
    
    splitArray.append(''.join(tempArray))
    
    return splitArray

def arrayToString(stringArray: list[str]) -> str:
    return "".join(stringArray)

def join(arr: list[str], s: str) -> str:
    #Problem 26.2 Without using a built-in string join method, implement a join(arr, s) method, which receives an array
    #of strings, arr, and a string, s, and returns a single string consisting of the strings in arr with s 
    #in between them.    
    stringArray = []
    for index in range(len(arr)):
        if arr[index] == s:
            stringArray.append(s)
            continue
        
        if index == len(arr) - 1 and arr[index] == "":
            continue
        
        if arr[index] == "":
            stringArray.append(s)
            continue
            
        stringArray.append(arr[index])
        
        if index < len(arr) - 1:
            stringArray.append(s)
    
    return arrayToString(stringArray)

def indexOf(s: str, t: str) -> int:
    #Problem 26.3 String Matching

    if  s.find(t) == -1:
        return -1
    return s.index(t)

def strStr(haystack: str, needle: str) -> int:
    #Problem #28 Find the Index of the First Occurrence in a String - Easy - Rolling Hash Algorithm Approach
    if len(needle) > len(haystack):
        return -1
    
    needleSum = 0
    for character in needle:
        needleSum += ord(character)
    
    hayStackSum = 0
    for index in range(0, len(needle)):
        hayStackSum += ord(haystack[index])
    
    initialIndex = 0
    if needleSum == hayStackSum:
        for character in needle:
            if character != haystack[initialIndex]:
                break
            initialIndex += 1
            if initialIndex == len(needle):
                return 0
    
    subtractIndex = 0
    for index1 in range(len(needle), len(haystack)):
        hayStackSum -= ord(haystack[subtractIndex])
        hayStackSum += ord(haystack[index1])
        temporaryIndex = subtractIndex + 1
        if needleSum == hayStackSum:
            for character in needle:
                if character != haystack[temporaryIndex]:
                    break
                temporaryIndex += 1
                
                if temporaryIndex == index1 + 1 :
                    return subtractIndex + 1
        subtractIndex += 1
    
    return -1

def strStr1(haystack: str, needle: str) -> int:
    #Problem #28 Find the Index of the First Occurrence in a String - Easy - KMP Algorithm Approach - AI generated - Understanding the Solution
    #TESTING
    preprocessNeedle = [0] * len(needle)
    suffixIndex = 0
    currentIndex = 1
    
    while currentIndex < len(needle):
        if needle[currentIndex] == needle[suffixIndex]:
            suffixIndex += 1
            preprocessNeedle[currentIndex] = suffixIndex
            currentIndex += 1
        else:
            if suffixIndex != 0:
                suffixIndex = preprocessNeedle[suffixIndex - 1]
            else:
                preprocessNeedle[currentIndex] = 0
                currentIndex += 1
    
    needleIndex = 0
    mainIndex = 0
    
    while mainIndex < len(haystack):
        if needle[needleIndex] == haystack[mainIndex]:
            mainIndex += 1
            needleIndex += 1
        
        if needleIndex == len(needle):
            return mainIndex - needleIndex
        
        elif mainIndex < len(haystack) and needle[needleIndex] != haystack[mainIndex]:
            if needleIndex != 0:
                needleIndex = preprocessNeedle[needleIndex -1]
            else:
                mainIndex += 1
    
    return -1

def randomPasswordGenerator(passwordLength: int = 16) -> str:
    #Generate a Password of a Given Length
    
    if passwordLength < 16:
        raise ValueError("The minimum password length is 16. Choose a number length greater than or equal to 16.")
        
    
    
    arrayCharacter = ['0'] * passwordLength
    randomIndex = set()
    
    uppercaseIndex = random.randint(0, passwordLength - 1)
    randomIndex.add(uppercaseIndex)
    
    randomUppercase = chr(random.randint(65, 90))
    arrayCharacter[uppercaseIndex] = randomUppercase
    
    lowercaseIndex = random.randint(0, passwordLength - 1)
    while lowercaseIndex in randomIndex:
        lowercaseIndex = random.randint(0, passwordLength - 1)
    randomIndex.add(lowercaseIndex)
    
    randomLowercase = chr(random.randint(97, 122))
    arrayCharacter[lowercaseIndex] = randomLowercase
    
    numberIndex = random.randint(0, passwordLength - 1)
    while numberIndex in randomIndex:
        numberIndex = random.randint(0, passwordLength - 1)
    randomIndex.add(numberIndex)
    
    randomNumber = chr(random.randint(48, 57))
    arrayCharacter[numberIndex] = randomNumber
    
    symbolIndex = random.randint(0, passwordLength - 1)
    while symbolIndex in randomIndex:
        symbolIndex = random.randint(0, passwordLength - 1)
    randomIndex.add(symbolIndex)
    
    randomSwitch = random.randint(1, 4)
    randomSymbol = 0
    randomSymbol1 = '*'
    if randomSwitch == 1:
        randomSymbol = random.randint(33, 47)
        randomSymbol1 = chr(randomSymbol)
    elif randomSwitch == 2:
        randomSymbol = random.randint(58, 64)
        randomSymbol1 = chr(randomSymbol)
    elif randomSwitch == 3:
            randomSymbol = random.randint(91, 96)
            randomSymbol1 = chr(randomSymbol)
    else:
        randomSymbol = random.randint(123, 126)
        randomSymbol1 = chr(randomSymbol)
            
    arrayCharacter[symbolIndex] = randomSymbol1
    
    for index in range(passwordLength):
        if index in randomIndex:
            continue
        
        arrayCharacter[index] = chr(random.randint(33, 126))
    
    passwordString = "".join(arrayCharacter)
    return passwordString

if __name__ == "__main__":
    password = randomPasswordGenerator(20)
    print(password)
    print(len(password))
    
