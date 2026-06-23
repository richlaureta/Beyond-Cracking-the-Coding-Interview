from collections import defaultdict
import math
import copy
from collections import Counter

def accountSharing(connections) -> str:
    #Problem 30.1 - Account Sharing Detection
    
    usernameSet = set()
    
    for connection in connections:
        if connection[1] in usernameSet:
            return connection[0]
        
        usernameSet.add(connection[1])
    
    return ""

def mostSharedAccount(connections: list[tuple[str]]) -> str:
    #Problem 30.2 - Most Shared Account
    
    nameUsedCount = defaultdict(int)
    mostSharedUser = None
    maxNameCountUsed = 0
    
    for connection in connections:
        nameUsedCount[connection[1]] += 1
        if nameUsedCount[connection[1]] > maxNameCountUsed:
            mostSharedUser = connection[1]
            maxNameCountUsed = nameUsedCount[connection[1]]
    return mostSharedUser

def mostFrequentOctet(ips: list[str]) -> str:
    #Problem 30.3 - Most Frequent Octet
    
    octetFrequencyDictionary = defaultdict(int)
    mostCommonCountOctet = 0
    mostCommonOctet = None
    
    for ip in ips:
        octet = ip.partition('.')[0]
        octetFrequencyDictionary[octet] += 1
        if octetFrequencyDictionary[octet] > mostCommonCountOctet:
            mostCommonCountOctet = octetFrequencyDictionary[octet]
            mostCommonOctet = octet
        
    return mostCommonOctet

def multiAccountCheating(users: list[tuple]) -> bool:
    #Problem 30.4 - Multi-Account Cheating
    
    ipSet = set()
    
    for user in users:
        for ip in user[1]:
            if ip in ipSet:
                return True
        for ip in user[1]:
            ipSet.add(ip)
    
    return False

class DomainResolver:
    #Problem 30.5 - Domain Resolver
    
    def __init__(self):
        self.ipToDomainSetDictionary = defaultdict(set)
        self.domainToSubDomainDictionary = defaultdict(set)
    
    def registerDomain(self, ip: str, domain: str):
        self.ipToDomainSetDictionary[ip].add(domain)
    def registerSubdomain(self, domain: str, subdomain: str):
        self.domainToSubDomainDictionary[domain].add(subdomain)
    def hasSubdomain(self, ip: str, domain: str, subdomain: str) -> bool:
        if domain not in self.ipToDomainSetDictionary[ip]:
            return False
        if subdomain not in self.domainToSubDomainDictionary[domain]:
            return False
        
        return True

def findSquared(arr: list[int]) -> list[list[int]]:
    #Problem 30.6 - Find All Squares
    
    numberIndexDictionary = defaultdict(int)
    squaredIndex = []
    
    for index in range(len(arr)):
        numberIndexDictionary[arr[index] + 0.0] = index
        number = (arr[index] * arr[index]) + 0.0
        squareRoot = math.sqrt(arr[index])
        
        if number in numberIndexDictionary:
            squaredIndex.append([index, numberIndexDictionary[number]])
        elif squareRoot in numberIndexDictionary:
            squaredIndex.append([numberIndexDictionary[squareRoot], index])
    
    return squaredIndex

class Checker:
    #Problem 30.7 - Word Expansion Class
    
    def __init__(self, word1:str):
        self.word = word1        
        self.wordDictionaryFrequency = Counter(self.word)
        
    def expandsInto(self, word2: str) -> bool:
        if len(word2) <= len(self.word) or len(word2) > len(self.word) + 1:
            return False
        
        wordDictionaryFrequency1 = self.wordDictionaryFrequency.copy()
        
        wordLength = len(self.word)
        exactlyOneCount = 0
        
        for letter1 in word2:
            if letter1 not in wordDictionaryFrequency1:
                exactlyOneCount += 1
                if exactlyOneCount > 1:
                    return False
                continue
            
            wordDictionaryFrequency1[letter1] -= 1
    
            if wordDictionaryFrequency1[letter1] == -1:
                exactlyOneCount += 1
                if exactlyOneCount > 1:
                    return False
                continue
            
            wordLength -= 1
        
        if exactlyOneCount == 1 and wordLength == 0:
            return True
        
        return False

def suspectStudents(answers: list[str], m: int, students: list[tuple]) -> list[list[int]]:
    #Problem 30.8 - Cheater Detection
    
    if len(students) == 0 or m == 1 or len(answers) == 0:
        return []
    
    deskToTupleDictionary = defaultdict(tuple)
    deskToTupleDictionary[students[0][1]] = (students[0][0], students[0][2])
    
    suspectedStudentList = []
    
    for student in students[1:]:
        if student[1] - 1 in deskToTupleDictionary and (student[1] - 1) % m != 0:
            wrongAnswerIndexList = []
            for index in range(len(answers)):
                if answers[index] != student[2][index]:
                    wrongAnswerIndexList.append(index)
            
            for index1 in range(len(wrongAnswerIndexList)):
                if (student[2][wrongAnswerIndexList[index1]] == 
                    deskToTupleDictionary[student[1] - 1][1][wrongAnswerIndexList[index1]]):
                    suspectedStudentList.append([deskToTupleDictionary[student[1] - 1][0],student[0]])
                    break
                        
        if student[1] + 1 in deskToTupleDictionary and (student[1]  + 1) % m != 1:
            wrongAnswerIndexList = []
            for index in range(len(answers)):
                if answers[index] != student[2][index]:
                    wrongAnswerIndexList.append(index)
            
            for index1 in range(len(wrongAnswerIndexList)):
                if (student[2][wrongAnswerIndexList[index1]] == 
                    deskToTupleDictionary[student[1] + 1][1][wrongAnswerIndexList[index1]]):
                    suspectedStudentList.append([deskToTupleDictionary[student[1] + 1][0], student[0]])
                    break
            
        deskToTupleDictionary[student[1]] = (student[0], student[2])
    
    return suspectedStudentList

def alphabeticSumProduct(words: list[str], target: int) -> bool:
    #Problem 30.9 - Product of Alphabetical Sums
    
    if len(words) == 0:
        return False
    
    targetMultiplesSet = set()
    
    for word in words:
        total = 0
        for letter in word:
            total += ord(letter) - 96
            
        if target % total == 0:
            targetMultiplesSet.add(total)
    
    for number0 in targetMultiplesSet:
        for number1 in targetMultiplesSet:
            if target / (number0 * number1) in targetMultiplesSet:
                return True
    
    return False

#TESTS

def runAccountSharingDetectionTests():
    tests = [
        # Example 1 
      	([("203.0.113.10", "mike"), ("298.51.100.25", "bob"),
        ("292.0.2.5", "mike"), ("203.0.113.15", "bob2")], "203.0.113.10"),
      	# Example 2 
      	([("111.0.0.0", "mike"), ("111.0.0.1", "mike"),
        ("111.0.0.2", "bob"), ("111.0.0.3", "bob")], "111.0.0.0"),
      	# Example 3 
      	([("111.0.0.0", "mike"), ("111.0.0.1", "mike2"),
        ("111.0.0.2", "mike3"), ("111.0.0.3", "mike4")], ""),
      	# Edge case - empty list
      	([], ""),
      	# Edge case - single connection
      	([("1.1.1.1", "alice")], ""),
  	]
    
    for connections, want in tests:
        got = accountSharing(connections)
        
        # Check if got matches want directly
        if got == want:
         continue
     
     	# If want is empty, got must also be empty
        if want == "":
            assert got == "", f"\naccount_sharing({connections}): got: {got}, want: {want}\n"
            continue
	
    print("ALL ACCOUNT SHARING DETECTION TESTS PROVIDED PASSED.")

def runMostSharedAccountTests():
    tests = [
        # Example 
        ([("203.0.113.10", "mike"), ("208.51.100.25", "bob"),
        ("202.0.2.5", "mike"), ("203.0.113.15", "bob2")], "mike"),
        # Additional test cases
        ([], None),
        ([("1.1.1.1", "alice")], "alice"),
        ([("1.1.1.1", "alice"), ("1.1.1.2", "bob"),
        ("1.1.1.3", "alice"), ("1.1.1.4", "bob")], "alice"),
    ]
    
    for connections, want in tests:
        got = mostSharedAccount(connections)
        assert got == want or (want and got and
                           len([(ip, u) for ip, u in connections if u == got]) ==
                           len([(ip, u) for ip, u in connections if u == want])), \
            f"\nmost_shared_account({connections}): got: {got}, want: {want}\n"
    
    print("ALL MOST SHARED ACCOUNT TESTS PROVIDED PASSED.")

def runMostFrequentOctetTests():
    tests = [
        # Example 
        (["203.0.113.10", "208.51.100.5", "202.0.2.5", "203.0.113.5"], "203"),
        # Additional test cases
        ([], None),
        (["192.168.1.1"], "192"),
        (["10.0.0.1", "10.0.0.2", "192.168.1.1"], "10"),
        (["172.16.0.1", "172.16.0.2", "172.17.0.1", "172.16.0.3"], "172"),
    ]
    
    for ips, want in tests:
        got = mostFrequentOctet(ips)
        assert got == want, f"\nmost_frequent_octet({ips}): got: {got}, want: {want}\n"
        
    print("ALL MOST FREQUENT OCTET TESTS PROVIDED PASSED.")

def runMultiAccountCheatingTests():
    tests = [
        # Example 
        ([("mike", ["203.0.3.10", "208.51.0.5", "52.0.2.5"]),
        ("bob", ["111.0.0.10", "222.0.0.5", "222.0.0.8"]),
          ("bob2", ["222.0.0.5", "222.0.0.8", "111.0.0.10"])], True),
        # Additional test cases
        ([], False),
        ([("alice", ["1.1.1.1"])], False),
        ([("alice", ["1.1.1.1", "2.2.2.2"]),
        ("bob", ["2.2.2.2", "1.1.1.1"])], True),
        ([("alice", ["1.1.1.1"]), ("bob", ["2.2.2.2"])], False),
    ]
    
    for users, want in tests:
        got = multiAccountCheating(users)
        assert got == want, f"\nmulti_account_cheating({users}): got: {got}, want: {want}\n"
    
    print("ALL MULTI-ACCOUNT CHEATING TESTS PROVIDED PASSED.")

def runDomainResolverTests():
    tests = [
        # Example 
        (
            [
                ("register_domain", "192.168.1.1", "example.com"),
                ("register_domain", "192.168.1.1", "example.org"),
                ("register_domain", "192.168.1.2", "domain.com"),
                ("register_subdomain", "example.com", "a"),
                ("register_subdomain", "example.com", "b"),
                ("has_subdomain", "192.168.1.1", "example.com", "a"),
                ("has_subdomain", "192.168.1.1", "example.com", "c"),
                ("has_subdomain", "127.0.0.1", "example.com", "a"),
                ("has_subdomain", "192.168.1.1", "example.org", "a"),
                ("has_subdomain", "192.168.1.2", "example.com", "a"),
            ],
            [None, None, None, None, None, True, False, False, False, False]
        ),
        # Additional test cases
        (
            [
                ("register_domain", "1.1.1.1", "test.com"),
                ("register_subdomain", "test.com", "www"),
                ("has_subdomain", "1.1.1.1", "test.com", "www"),
            ],
            [None, None, True]
        ),
        (
            [
                ("register_domain", "1.1.1.1", "site1.com"),
                ("register_domain", "2.2.2.2", "site2.com"),
                ("register_subdomain", "site1.com", "www"),
                ("register_subdomain", "site2.com", "www"),
                ("has_subdomain", "1.1.1.1", "site1.com", "www"),  # Should be True
                ("has_subdomain", "2.2.2.2", "site2.com", "www"),  # Should be True
                ("has_subdomain", "1.1.1.1", "site2.com", "www"),  # Should be False (wrong IP)
                ("has_subdomain", "2.2.2.2", "site1.com", "www"),  # Should be False (wrong IP)
            ],
            [None, None, None, None, True, True, False, False]
        ),
    ]
    
    for operations, wants in tests:
        resolver = DomainResolver()
        for i, op in enumerate(operations):
            if op[0] == "register_domain":
                got = resolver.registerDomain(op[1], op[2])
            elif op[0] == "register_subdomain":
                got = resolver.registerSubdomain(op[1], op[2])
            else:  # has_subdomain
                got = resolver.hasSubdomain(op[1], op[2], op[3])
            want = wants[i]
            assert got == want, \
                f"\n{op[0]}({', '.join(repr(x) for x in op[1:])}): got: {got}, want: {want}\n"
    
    print("ALL DOMAIN RESOLVER TESTS PROVIDED PASSED.")

def runFindAllSquaresTests():
    tests = [
        # Example 
        ([4, 10, 3, 100, 5, 2, 10000], [[5, 0], [1, 3], [3, 6]]),
        # Additional test cases
        ([], []),
        ([1], [[0, 0]]),
        ([2, 4], [[0, 1]]),
    ]
    
    for arr, want in tests:
        got = findSquared(arr)
        # Sort both lists to compare them regardless of order
        got.sort()
        want.sort()
        assert got == want, f"\nfind_squared({arr}): got: {got}, want: {want}\n"

    print("ALL FIND ALL SQUARES TESTS PROVIDED PASSED.")

def runWordExpansionClassTests():
    tests = [
        # Example 1 
        (
            ("tea", [
                ("tea", False),
                ("team", True),
                ("seam", False),
                ]
             )
        ),        
        # Example 2 
        (
            ("on", [
                ("nooo", False),
                ("not", True),
                ("now", True),
                ]
            )
        ),
        # Additional test cases
        (
            ("", [
                ("a", True),
                ("", False),
                ("ab", False),
                ]
            )
        ),
        
        (
            ("xyz", [
                ("wxyz", True),
                ("xyzw", True),
                ("xyza", True),
                ("xyz", False),
                ]
             )
        ),
    ]
    
    for s, checks in tests:
        checker = Checker(s)
        for s2, want in checks:
            got = checker.expandsInto(s2)
            assert got == want, \
                f"\nChecker({repr(s)}).expandsInto({repr(s2)}): got: {got}, want: {want}\n"
    
    print("ALL WORD EXPANSION CLASS TESTS PROVIDED PASSED.")
    
def runCheaterDetectionTests():
    tests = [
        # Example 
        (
            ['a', 'b', 'c', 'c'],
            5,
            [
                (4, 10, ['a', 'b', 'c', 'd']),
                (1, 6, ['a', 'b', 'c', 'd']),
                (3, 8, ['a', 'b', 'd', 'd']),
                (5, 11, ['a', 'b', 'c', 'd']),
                (9, 7, ['a', 'b', 'c', 'd']),
                (6, 16, ['a', 'b', 'd', 'd']),
            ],
            [[1, 9], [3, 9]]
        ),
        # Additional test cases
        (
            ['a', 'b'],
            2,
            [
                (1, 1, ['a', 'b']),
                (2, 2, ['a', 'b']),
            ],
            []  # Perfect scores are not suspicious
        ),
        (
            ['a', 'b'],
            2,
            [
                (1, 1, ['b', 'b']),
                (2, 2, ['b', 'b']),
            ],
            [[1, 2]]
        ),
        (
            ['a', 'b'],
            2,
            [
                (1, 1, ['b', 'b']),
                (2, 3, ['b', 'b']),
            ],
            []  # Different rows
        ),
    ]

    for answers, m, students, want in tests:
        got = suspectStudents(answers, m, students)
        # Sort both lists to compare them regardless of order
        assert got == want, \
            f"\nsuspect_students({answers}, {m}, {students}): got: {got}, want: {want}\n"
            
    print("ALL CHEATER DETECTION TESTS PROVIDED PASSED.")

def runProductOfAlphabeticalSumsTests():
    tests = [
        # Example 1 
        (["abc", "fg", "hij", "klm", "nop", "qrs", "vwx"], 1620, True),
        # Example 2 
        (["a", "b"], 2, True),
        # Additional test cases
        ([], 1, False),
        (["a"], 1, True),
        (["a", "b", "c"], 6, True),
        (["a", "b", "c"], 7, False),
    ]
    
    for words, target, want in tests:
        got = alphabeticSumProduct(words, target)
        assert got == want, \
            f"\nalphabetic_sum_product({words}, {target}): got: {got}, want: {want}\n"
    
    print("ALL PRODUCT OF ALPHABETICAL SUMS TESTS PROVIDED PASSED.")
   
#ALL TESTS
    
def RunAllSetsAndMapsTests():
    runAccountSharingDetectionTests()
    runMostSharedAccountTests()
    runMostFrequentOctetTests()
    runMultiAccountCheatingTests()
    runFindAllSquaresTests()
    runWordExpansionClassTests()
    runCheaterDetectionTests()
    runProductOfAlphabeticalSumsTests()
    
    print()
    print("------------------------------------------------------")
    print("ALL INCLUDED SETS AND MAPS TESTS IN THE FILE PASSED. |")
    print("------------------------------------------------------")

if __name__ == "__main__":
    RunAllSetsAndMapsTests()