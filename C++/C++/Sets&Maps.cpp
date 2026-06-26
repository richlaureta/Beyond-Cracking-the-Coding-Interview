//
//  Sets&Maps.cpp
//  C++
//
//  Created by Richmond Laureta on 6/8/26.
//

#include "Header.hpp"

string accountSharing(const vector<pair<string, string>> &connections)
{
    //Problem 30.1 - Account Sharing Detection
    
    unordered_set<string> names;
    
    for(pair<string, string> connection: connections)
    {
        if(names.find(connection.second) != names.end()) return connection.first;
        
        names.insert(connection.second);
    }
    
    return "";
}


string mostSharedAccount(const vector<pair<string, string>> &connections)
{
    //Problem 30.2 - Most Shared Account
    
    unordered_map<string, int> nameUsedCount;
    string mostSharedUser = "";
    int maxNameCountUsed = 0;
    
    for(pair<string, string> connection: connections)
    {
        nameUsedCount[connection.second]++;
        if(nameUsedCount[connection.second] > maxNameCountUsed)
        {
            mostSharedUser = connection.second;
            maxNameCountUsed = nameUsedCount[connection.second];
        }
    }
    
    return mostSharedUser;
}

string mostFrequentOctet(const vector<string> &ips)
{
    //Problem 30.3 - Most Frequent Octet
    
    unordered_map<string, int> octetFrequencyMap;
    int mostCommonCountOctet = 0;
    string mostCommonOctet = "";
    
    for(string ip: ips)
    {
        size_t dotIndex = ip.find('.');
        string octet = ip.substr(0, dotIndex);
        octetFrequencyMap[octet]++;
        if(octetFrequencyMap[octet] > mostCommonCountOctet)
        {
            mostCommonCountOctet = octetFrequencyMap[octet];
            mostCommonOctet = octet;
        }
    }
    
    return mostCommonOctet;
}

bool multiAccountCheating(const vector<pair<string, vector<string>>> &users)
{
    //Problem 30.4 - Multi-Account Cheating
    
    unordered_set<string> ipSet = {};
    
    for(pair<string, vector<string>> user: users)
    {
        for(string ip: user.second)
        {
            if(ipSet.find(ip) != ipSet.end()) return true;
        }
        
        for(string ip: user.second)
        {
            ipSet.insert(ip);
        }
    }
    
    return false;
}

void DomainResolver::registerDomain(string ip, string domain)
{
    //Problem 30.5 - Domain Resolver
    
    ipToDomainSetMap[ip].insert(domain);
}

void DomainResolver::registerSubdomain(string domain, string subdomain)
{
    //Problem 30.5 - Domain Resolver
    
    domainToSubdomainSetMap[domain].insert(subdomain);
}

bool DomainResolver::hasSubdomain(string ip, string domain, string subdomain)
{
    //Problem 30.5 - Domain Resolver
    
    if(ipToDomainSetMap[ip].find(domain) == ipToDomainSetMap[ip].end()) return false;
    
    if(domainToSubdomainSetMap[domain].find(subdomain) == domainToSubdomainSetMap[domain].end()) return false;
        
    return true;
}

vector<vector<int>> findSquared(const vector<int> &arr)
{
    //Problem 30.6 - Find All Squares
    
    unordered_map<double, int> numberIndexMap;
    vector<vector<int>> squaredIndex;
    
    for(int index = 0; index < (int) arr.size(); index++)
    {
        numberIndexMap[arr[index] + 0.0] = index;

        double number = (arr[index] * arr[index]) + 0.0;
        double squareRoot = sqrt(arr[index]);
        
        if(numberIndexMap.contains(number)) squaredIndex.push_back({index, numberIndexMap[number]});
        else if(numberIndexMap.contains(squareRoot)) squaredIndex.push_back({numberIndexMap[squareRoot], index});
        
    }
    
    return squaredIndex;
}

Checker::Checker(const string &word1)
{
    //Problem 30.7 - Word Expansion Class
    
    this->word = word1;
    
    for(char letter: word1)
    {
        wordMapFrequency[letter]++;
    }
}

bool Checker::expandsInto(const string &word2)
{
    //Problem 30.7 - Word Expansion Class
    
    if((int) word2.length() <= (int) this->word.length() or (int) word2.length() > ((int) word.length()) + 1) return false;
    
    unordered_map<char, int> wordFrequencyMap1;
    wordFrequencyMap1.reserve(this->wordMapFrequency.size());
    wordFrequencyMap1 = this->wordMapFrequency;
    
    int wordLength = (int) word.length();
    int exactlyOneCount = 0;
    
    for(char letter1: word2)
    {
        if(wordFrequencyMap1.find(letter1) == wordFrequencyMap1.end())
        {
            exactlyOneCount++;
            if(exactlyOneCount > 1) return false;
            continue;
        }
        
        wordFrequencyMap1[letter1]--;
        
        if(wordFrequencyMap1[letter1] == -1)
        {
            exactlyOneCount++;
            if(exactlyOneCount > 1) return false;
            continue;
        }
        
        wordLength--;
    }
    
    if(exactlyOneCount == 1 and wordLength == 0) return true;
    
    return false;
}

vector<vector<int>> suspectStudents(const vector<char> &answers, int m, const vector<Student> &students)
{
    //Problem 30.8 - Cheater Detection
    
    if((int) students.size() == 0 or m == 1 or (int) answers.size() == 0) return {};

    unordered_map<int, tuple<int, vector<char>>> deskToTupleMap;
    
    vector<vector<int>> suspectedPairsVector;
    
    for(Student student: students)
    {
        if(deskToTupleMap.find(student.desk - 1) != deskToTupleMap.end() and (student.desk - 1) % m != 0)
        {
            vector<int> wrongAnswerIndexVector = {};
            
            for(int index = 0; index < (int) answers.size(); index++)
            {
                if(answers[index] != student.answers[index]) wrongAnswerIndexVector.push_back(index);
            }
            
            for(int index1 = 0; index1 < (int) wrongAnswerIndexVector.size(); index1++)
            {
                if(student.answers[wrongAnswerIndexVector[index1]] ==
                   get<1>(deskToTupleMap[student.desk - 1])[wrongAnswerIndexVector[index1]])
                {
                    suspectedPairsVector.push_back({get<0>(deskToTupleMap[student.desk - 1]), student.ID});
                    break;
                }
            }
        }
        
        if(deskToTupleMap.find(student.desk + 1) != deskToTupleMap.end() and (student.desk + 1) % m != 1)
        {
            vector<int> wrongAnswerIndexVector = {};
            
            for(int index = 0; index < (int) answers.size(); index++)
            {
                if(answers[index] != student.answers[index]) wrongAnswerIndexVector.push_back(index);
            }
            
            for(int index1 = 0; index1 < (int) wrongAnswerIndexVector.size(); index1++)
            {
                if(student.answers[wrongAnswerIndexVector[index1]] ==
                   get<1>(deskToTupleMap[student.desk + 1])[wrongAnswerIndexVector[index1]])
                {
                    suspectedPairsVector.push_back({get<0>(deskToTupleMap[student.desk + 1]), student.ID});
                    break;
                }
            }
        }
        
        deskToTupleMap[student.desk] = {student.ID, student.answers};
    }
    
    return suspectedPairsVector;
}

bool alphabeticSumProduct(const vector<string> &words, int target)
{
    //Problem 30.9 - Product of Alphabetical Sums
    
    if((int) words.size() == 0) return false;
    
    unordered_set<double> targetMultiplesSet = {};
    
    for(string word: words)
    {
        int total = 0;
        for(char letter: word) total += static_cast<int>(letter) - 96 + 0.0;
        
        if(target % total == 0) targetMultiplesSet.insert(total);
    }
    
    for(int number0: targetMultiplesSet)
    {
        for(int number1: targetMultiplesSet)
        {
            if(targetMultiplesSet.find(target / (number0 * number1)) != targetMultiplesSet.end()) return true;
        }
    }
    
    return false;
}

Action::Action(string a, string act, int t) : agent(a), action(act), ticket(t)
{
    //Problem 30.10 - Action Log Anomalies
    
};

vector<int> findAnomalies(const vector<Action> &log)
{
    //Problem 30.10 - Action Log Anomalies
    
    unordered_set<int> anomalyTicketSet = {};
    unordered_set<int> stillOpentTicketSet = {};
    unordered_set<int> openedAndClosedTicketSet = {};
    unordered_set<string> agentsNeedToCloseSet = {};
    
    unordered_map<int, string> ticketToAgentMap;
    unordered_map<string, int> agentToTicketMap;
    
    vector<int> anomalyTicketVector = {};
    
    for(Action entry: log)
    {
        if(anomalyTicketSet.find(entry.ticket) != anomalyTicketSet.end())
        {
            if(agentsNeedToCloseSet.find(entry.agent) != agentsNeedToCloseSet.end() and
               entry.ticket != agentToTicketMap[entry.agent] and
               anomalyTicketSet.find(agentToTicketMap[entry.agent]) == anomalyTicketSet.end())
            {
                anomalyTicketSet.insert(agentToTicketMap[entry.agent]);
                anomalyTicketVector.push_back(agentToTicketMap[entry.agent]);
            }
            
            if(entry.action == "open")
            {
                agentsNeedToCloseSet.insert(entry.agent);
                stillOpentTicketSet.insert(entry.ticket);
                agentToTicketMap[entry.agent] = entry.ticket;
                ticketToAgentMap[entry.ticket] = entry.agent;
            }
            
            continue;
        }
        
        if(openedAndClosedTicketSet.find(entry.ticket) != openedAndClosedTicketSet.end() and
           anomalyTicketSet.find(entry.ticket) == anomalyTicketSet.end())
        {
            anomalyTicketSet.insert(entry.ticket);
            anomalyTicketVector.push_back(entry.ticket);
            continue;
        }
        
        if(ticketToAgentMap[entry.ticket] == "" and entry.action == "close")
        {
            if(agentsNeedToCloseSet.find(entry.agent) != agentsNeedToCloseSet.end())
            {
                anomalyTicketSet.insert(agentToTicketMap[entry.agent]);
                anomalyTicketVector.push_back(agentToTicketMap[entry.agent]);
                stillOpentTicketSet.erase(agentToTicketMap[entry.agent]);
            }
            
            anomalyTicketVector.push_back(entry.ticket);
            anomalyTicketSet.insert(entry.ticket);
            continue;
        }
        else if(ticketToAgentMap[entry.ticket] == "" and entry.action == "open")
        {
            if(agentsNeedToCloseSet.find(entry.agent) != agentsNeedToCloseSet.end())
            {
                anomalyTicketSet.insert(agentToTicketMap[entry.agent]);
                anomalyTicketVector.push_back(agentToTicketMap[entry.agent]);
                stillOpentTicketSet.erase(agentToTicketMap[entry.agent]);
            }
            
            ticketToAgentMap[entry.ticket] = entry.action;
            stillOpentTicketSet.insert(entry.ticket);
            agentToTicketMap[entry.agent] = entry.ticket;
            agentsNeedToCloseSet.insert(entry.agent);
            continue;
        }
        
        if(ticketToAgentMap[entry.ticket] != "" and entry.action == "close")
        {
            if(entry.agent != ticketToAgentMap[entry.ticket])
            {
                anomalyTicketSet.insert(entry.ticket);
                anomalyTicketVector.push_back(entry.ticket);
                agentsNeedToCloseSet.erase(ticketToAgentMap[entry.ticket]);
                stillOpentTicketSet.erase(entry.ticket);
                continue;
            }
            
            stillOpentTicketSet.erase(entry.ticket);
            openedAndClosedTicketSet.insert(entry.ticket);
            agentsNeedToCloseSet.erase(entry.agent);
        }
    }
    
    for(int ticket: stillOpentTicketSet)
    {
        if(anomalyTicketSet.find(ticket) == anomalyTicketSet.end()) anomalyTicketVector.push_back(ticket);
    }
    
    return anomalyTicketVector;
}

std::unordered_set<int> setIntersection(
    const std::unordered_set<int>& set1,
    const std::unordered_set<int>& set2) {
  std::unordered_set<int> result;
  // Iterate through the smaller set for efficiency
  if (set1.size() <= set2.size()) {
    for (int x : set1) {
      if (set2.find(x) != set2.end()) {
        result.insert(x);
      }
    }
  } else {
    for (int x : set2) {
      if (set1.find(x) != set1.end()) {
        result.insert(x);
      }
    }
  }
  return result;
}

int largestSetIntersectionPrefixSum(const std::vector<std::vector<int>>& sets) {
  int n = (int) sets.size();
  if (n == 1) {
    return 0;
  }

  std::vector<std::unordered_set<int>> hashSets(n);
  for (int i = 0; i < n; i++) {
    hashSets[i] = std::unordered_set<int>(sets[i].begin(), sets[i].end());
  }

  // Compute prefix intersections
  std::vector<std::unordered_set<int>> prefixIntersections(n);
  prefixIntersections[0] = hashSets[0];
  for (int i = 1; i < n; i++) {
    prefixIntersections[i] = setIntersection(prefixIntersections[i - 1], hashSets[i]);
  }

  // Compute suffix intersections
  std::vector<std::unordered_set<int>> suffixIntersections(n);
  suffixIntersections[n - 1] = hashSets[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffixIntersections[i] = setIntersection(suffixIntersections[i + 1], hashSets[i]);
  }

  // Find the best index to exclude
  int bestIndex = 0;
  int maxSize = 0;

  for (int i = 0; i < n; i++) {
    // Compute intersection excluding sets[i]
    std::unordered_set<int> intersection;
    if (i == 0) {
      intersection = suffixIntersections[1];
    } else if (i == n - 1) {
      intersection = prefixIntersections[n - 2];
    } else {
      intersection = setIntersection(prefixIntersections[i - 1], suffixIntersections[i + 1]);
    }

    if (intersection.size() > maxSize) {
      maxSize = (int) intersection.size();
      bestIndex = i;
    }
  }

  return bestIndex;
}

int largestSetIntersectionFrequencyMap(const vector<vector<int>> &sets)
{
    //Problem 30.11 - Largest Set Intersection
    
    if((int) sets.size() == 1) return 0;
    
    unordered_map<int, int> numberToFrequencyMap;
    
    for(vector<int> set: sets)
    {
        for(int number: set)
        {
            numberToFrequencyMap[number]++;
        }
    }
    
    int index = 0;
    int minimumIntersectionIndex = 0;
    int minimumIntersectionCount = INT_MAX;
    
    for(vector<int> set: sets)
    {
        int totalIntersection = 0;
        for(int number: set)
        {
            totalIntersection += numberToFrequencyMap[number] - 1;
        }
        
        if(totalIntersection == minimumIntersectionCount and ((int) sets[index].size()) < ((int) sets[minimumIntersectionIndex].size())) minimumIntersectionIndex = index;
        else if(totalIntersection < minimumIntersectionCount)
        {
            minimumIntersectionIndex = index;
            minimumIntersectionCount = totalIntersection;
        }
        
        index++;
    }
    
    return minimumIntersectionIndex;
}
