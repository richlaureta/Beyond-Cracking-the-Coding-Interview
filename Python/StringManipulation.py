#Character Manipulation Problem Set

#Question 1: Implement a function is_alphanumeric(c) that returns whether a character c is a lowercase or
#uppercase English letter or a digit between '0' and '9'.

def is_lowercase(c: str) -> bool:
	return ord(c) > 96 and ord(c) < 123

def is_uppercase(c: str) -> bool:
    return ord(c) > 64 and ord(c) < 91

def is_numeric(c: str) -> bool:
    return ord(c) > 47 and ord(c) < 58

def is_alphanumeric(c: str) -> bool:
    return is_lowercase(c) or is_uppercase(c) or is_numeric(c)

if __name__ == "__main__":
    print(is_alphanumeric('&'))