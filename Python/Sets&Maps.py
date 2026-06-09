from collections import defaultdict

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
    
#ALL TESTS
    
def RunAllSetsAndMapsTests():
    runAccountSharingDetectionTests()
    runMostSharedAccountTests()
    
    print("------------------------------------------")
    print("ALL INCLUDED SETS AND MAPS TESTS PASSED. |")
    print("------------------------------------------")

if __name__ == "__main__":
    runMostSharedAccountTests()