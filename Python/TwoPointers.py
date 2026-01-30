def palindrome(s: str) -> bool:
    #Problem 27.1 Palindrome Check
    
    leftPointer = 0
    rightPointer = len(s) - 1
    
    while leftPointer < rightPointer:
        if s[leftPointer] != s[rightPointer]:
            return False
        leftPointer += 1
        rightPointer -= 1
    
    return True

def smallerPrefixes(arr: list[int]) -> bool:
    #Problem 27.2 Smaller Prefixes
    
    for index in range(1, len(arr)):
        arr[index]  += arr[index - 1]
        if arr[index] < arr[index - 1] and index + 1 <= len(arr)//2:
            return False
        if index + 1 > len(arr)//2 and arr[index] < arr[len(arr)//2 - 1]:
            return False
    
    return True
if __name__ =="__main__":
    arr = [-2, 1, -4, 5, -3, 7]
    print(smallerPrefixes(arr))
    