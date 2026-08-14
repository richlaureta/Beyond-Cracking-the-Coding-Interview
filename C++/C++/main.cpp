//
//  main.cpp
//  C++
//
//  Created by Richmond Laureta on 1/16/26.
//

#include "Header.hpp"

int main(int argc, const char *argv[]) {
    // String Manipulation - Is it lower case?
    //    cout << isLowerCase('B') << endl;
    // String Manipulation - Is it uppercase?
    //    cout << isUpperCase('8') << endl;
    // String Manipulation - Is it uppercase?
    //    cout << isDigit('/') << endl;
    // String Manipulation - Is it alpha numeric?
    //    cout << isAlphaNumeric('(') << endl;
    // Problem 25.1 Implement Dynamic Array
    //    DynamicArray testingDynamicArray;
    //
    //    testingDynamicArray.append(1);
    //    testingDynamicArray.append(2);
    //    testingDynamicArray.append(3);
    //    testingDynamicArray.append(4);
    //    testingDynamicArray.append(5);
    //    testingDynamicArray.append(6);
    //    testingDynamicArray.append(7);
    //    testingDynamicArray.append(8);
    //    testingDynamicArray.append(9);
    //    testingDynamicArray.append(10);
    //    testingDynamicArray.append(11);
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }
    //
    //    cout << "The capacity is: " << testingDynamicArray.size() << endl;
    //    cout << "The size is: " << testingDynamicArray.capacity() << endl;
    //
    //    cout << "This is the popped number: " << testingDynamicArray.pop(10)
    //    << endl;
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }
    //
    //    cout << "The capacity is: " << testingDynamicArray.size() << endl;
    //    cout << "The size is: " << testingDynamicArray.capacity() << endl;
    //
    //    if(testingDynamicArray.contains(3)) cout << "The number is in the
    //    dynamic array." << endl; else cout << "The number is not in the
    //    dynamic array." << endl;
    //
    //    testingDynamicArray.insert(5, 67);
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }
    //
    //    cout << "_________________" << endl;
    //
    //    testingDynamicArray.insert(0, 69);
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }
    //
    //    cout << "_________________" << endl;
    //
    //    testingDynamicArray.insert(10, 68);
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }
    //
    //    cout << "___________________" << endl;
    //
    //    cout << "The removed number is at index: " <<
    //    testingDynamicArray.remove(69) << endl;
    //
    //    for(int index = 0; index < testingDynamicArray.size(); index++)
    //    {
    //        cout << testingDynamicArray.get(index) << endl;
    //    }

    // Problem 26.1 String Split
    //
    //    vector<string> splitStrings = split("/home/./..//Documents/", '/');
    //
    //    for(int index = 0; index < splitStrings.size(); index++)
    //    {
    //        cout << splitStrings[index] << endl;
    //    }

    // Problem 26.2 - String Join
    //    vector<string> arr = {"", "home", ".", "..", "", "Documents", ""};
    //    string s = "/";
    //
    //    cout << join(arr, s) << endl;

    // Problem #28 Find the Index of the First Occurrence in a String - Easy
    //    string haystack = "butsad";
    //    string needle = "sad";
    //
    //    cout << strStr(haystack, needle) << endl;

    // Problem 27.1 - Palindrome Check

    //    cout << palindrome("ba") << endl;

    // Problem 27.3 Array Intersection

    //    vector<int> arr1 = {1, 2, 2, 3};
    //    vector<int> arr2 = {2, 2, 3};
    //
    //    vector<int> intersections = commonElements(arr1, arr2);
    //
    //    for(int element: intersections) cout << element << endl;

    // Problem 27.4 Palindromic Sentence
    //
    //    string s = "Bob wondered, 'Now, Bob?'";
    //
    //    cout << palindromicSentence(s) << endl;

    // Problem 27.5 Reverse Case Match
    //    std::vector<std::pair<std::string, bool>> tests = {
    //        // Example 1 from the book
    //        {"haDrRAHd", true},
    //        // Example 2 from the book
    //        {"haHrARDd", false},
    //        // Additional test cases
    //        {"", true},
    //        {"aA", true},
    //        {"Aa", true},
    //        {"BbbB", true},
    //        {"abAB", false},
    //        {"abBA", true},
    //        {"helloworldHELLOWORLD", false},
    //    };
    //
    //    for (const auto& [s, want] : tests) {
    //      bool got = reverseCaseMatch(s);
    //      if (got != want) {
    //        throw std::runtime_error("\nreverseCaseMatch(\"" + s +
    //                                 "\"): got: " + (got ? "true" : "false") +
    //                                 ", want: " + (want ? "true" : "false") +
    //                                 "\n");
    //      }
    //    }
    //
    //    cout << "All Reverse Case Match tests passed." << endl;

    // Problem 27.6 Merge Two Sorted Arrays
    //
    //    auto vecToStr = [](const std::vector<int>& vec) {
    //        std::string result = "[";
    //        for (size_t i = 0; i < vec.size(); i++) {
    //          if (i > 0) result += ", ";
    //          result += std::to_string(vec[i]);
    //        }
    //        result += "]";
    //        return result;
    //      };
    //
    //      std::vector<std::tuple<std::vector<int>, std::vector<int>,
    //      std::vector<int>>>
    //          tests = {
    //              // Example 1 from the book
    //              {{1, 3, 4, 5}, {2, 4, 4}, {1, 2, 3, 4, 4, 4, 5}},
    //              // Example 2 from the book
    //              {{-1}, {}, {-1}},
    //              // Additional test cases
    //              {{}, {}, {}},
    //              {{1}, {}, {1}},
    //              {{}, {1}, {1}},
    //              {{1, 3, 5}, {2, 4, 6}, {1, 2, 3, 4, 5, 6}},
    //              {{1, 1, 1}, {1, 1, 1}, {1, 1, 1, 1, 1, 1}},
    //          };
    //
    //      for (const auto& [arr1, arr2, want] : tests) {
    //        auto got = merge(arr1, arr2);
    //        if (got != want) {
    //          throw std::runtime_error("\nmerge(" + vecToStr(arr1) + ", " +
    //          vecToStr(arr2) +
    //                                   "): got: " + vecToStr(got) + ", want: "
    //                                   + vecToStr(want) +
    //                                   "\n");
    //        }
    //      }
    //
    //    cout << "ALL MERGE TEST PROVIDED PASSED." << endl;

    // Problem 27.7 2-Sum
    //    auto vecToStr = [](const std::vector<int>& vec) {
    //      std::string result = "[";
    //      for (size_t i = 0; i < vec.size(); i++) {
    //        if (i > 0) result += ", ";
    //        result += std::to_string(vec[i]);
    //      }
    //      result += "]";
    //      return result;
    //    };
    //
    //    std::vector<std::pair<std::vector<int>, bool>> tests = {
    //        // Example 1 from the book
    //        {{-5, -2, -1, 1, 1, 10}, true},
    //        // Example 2 from the book
    //        {{-3, 0, 0, 1, 2}, true},
    //        // Example 3 from the book
    //        {{-5, -3, -1, 0, 2, 4, 6}, false},
    //        // Additional test cases
    //        {{}, false},
    //        {{0}, false},
    //        {{-1, 1}, true},
    //        {{-2, -1, 0, 1}, true},
    //        {{1, 2, 3, 4}, false},
    //    };
    //
    //    for (const auto& [arr, want] : tests) {
    //      bool got = twoSum(arr);
    //
    //      if (got != want) {
    //        throw std::runtime_error("\ntwoSum(" + vecToStr(arr) +
    //                                 "): got: " + (got ? "true" : "false") +
    //                                 ", want: " + (want ? "true" : "false") +
    //                                 "\n");
    //      }
    //    }
    //    cout << "ALL TWO SUM TEST PROVIDED PASSED." << endl;

    // Problem 27.8 Three-Way Merge Without Duplicates
    //    const vector<int> arr1 = {1};
    //    const vector<int> arr2 = {};
    //    const vector<int> arr3 = {};
    //
    //    vector<int> mergedThreeWay = threeWayMerge(arr1, arr2, arr3);
    //
    //    for(int index = 0; index < mergedThreeWay.size(); index++) cout <<
    //    mergedThreeWay[index] << endl; auto vecToStr = [](const
    //    std::vector<int>& vec) {
    //        std::string result = "[";
    //        for (size_t i = 0; i < vec.size(); i++) {
    //          if (i > 0) result += ", ";
    //          result += std::to_string(vec[i]);
    //        }
    //        result += "]";
    //        return result;
    //      };
    //
    //      std::vector<std::tuple<std::vector<int>, std::vector<int>,
    //      std::vector<int>,
    //                             std::vector<int>>>
    //          tests = {
    //              // Example from the book
    //              {{2, 3, 3, 4, 5, 7}, {3, 3, 9}, {3, 3, 9}, {2, 3, 4, 5, 7,
    //              9}},
    //              // Additional test cases
    //              {{}, {}, {}, {}},
    //              {{1}, {}, {}, {1}},
    //              {{1}, {1}, {1}, {1}},
    //              {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {1, 2, 3, 4, 5}},
    //              {{1, 1, 1}, {1, 1}, {1}, {1}},
    //              {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3, 4, 5, 6, 7, 8,
    //              9}},
    //          };
    //
    //      for (const auto& [arr1, arr2, arr3, want] : tests) {
    //        auto got = threeWayMerge(arr1, arr2, arr3);
    //
    //        if (got != want) {
    //          throw std::runtime_error("\nthreeWayMerge(" + vecToStr(arr1) +
    //          ", " + vecToStr(arr2) +
    //                                   ", " + vecToStr(arr3) + "): got: " +
    //                                   vecToStr(got) +
    //                                   ", want: " + vecToStr(want) + "\n");
    //        }
    //      }
    //
    //    cout << "ALL THREE-WAY MERGE TEST PROVIDED PASSED." << endl;

    // Problem 27.9 Sort Valley-Shaped Array
//    auto vecToStr = [](const std::vector<int> &vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//            if (i > 0)
//                result += ", ";
//            result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//    };
//
//    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
//        // Example 1 from the book
//        {{8, 4, 2, 6}, {2, 4, 6, 8}},
//        // Example 2 from the book
//        {{1, 2}, {1, 2}},
//        // Example 3 from the book
//        {{2, 2, 1, 1}, {1, 1, 2, 2}},
//        // Additional test cases
//        {{}, {}},
//        {{1}, {1}},
//        {{3, 2, 1, 4}, {1, 2, 3, 4}},
//        {{5, 4, 3, 2, 1, 2, 3}, {1, 2, 2, 3, 3, 4, 5}},
//        {{1, 1, 1, 1}, {1, 1, 1, 1}},
//    };
//
//    for (const auto &[arr, want] : tests) {
//        auto got = sortValleyArray(arr);
//
//        if (got != want) {
//            throw std::runtime_error("\nsortValleyArray(" + vecToStr(arr) +
//                                     "): got: " + vecToStr(got) +
//                                     ", want: " + vecToStr(want) + "\n");
//        }
//    }
//    
//    cout << "ALL SORT VALLEY-SHAPED ARRAY TEST PROVIDED PASSED." << endl;
    
    //Problem 27.10 Missing Numbers in Range
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::tuple<std::vector<int>, int, int, std::vector<int>>> tests =
//          {
//              // Example 1 from the book
//              {{6, 9, 12, 15, 18}, 9, 13, {10, 11, 13}},
//              // Example 2 from the book
//              {{}, 9, 9, {9}},
//              // Example 3 from the book
//              {{6, 7, 8, 9}, 7, 8, {}},
//              // Additional test cases
//              {{}, 1, 5, {1, 2, 3, 4, 5}},
//              {{1, 2, 3, 4, 5}, 1, 5, {}},
//              {{1, 3, 5}, 1, 5, {2, 4}},
//              {{1}, 1, 1, {}},
//              {{2}, 1, 3, {1, 3}},
//          };
//
//      for (const auto& [arr, low, high, want] : tests) {
//        auto got = missingNumbers(arr, low, high);
//
//        if (got != want) {
//          throw std::runtime_error("\nmissingNumbers(" + vecToStr(arr) + ", " +
//                                   std::to_string(low) + ", " +
//                                   std::to_string(high) + "): got: " + vecToStr(got) +
//                                   ", want: " + vecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL MISSING NUMBERS IN RANGE TEST PROVIDED PASSED." << endl;
    
    //Problem 27.11 Interval Intersection
//    
//    auto intVecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const std::vector<std::vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<
//          std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<int>>,
//                     std::vector<std::vector<int>>>>
//          tests = {
//              // Example 1 from the book
//              {{{0, 1}, {4, 6}, {7, 8}},
//               {{2, 3}, {5, 9}, {10, 11}},
//               {{5, 6}, {7, 8}}},
//              // Example 2 from the book
//              {{{2, 4}, {5, 8}}, {{3, 3}, {4, 7}}, {{3, 3}, {4, 4}, {5, 7}}},
//              // Additional test cases
//              {{}, {}, {}},
//              {{{1, 2}}, {}, {}},
//              {{{1, 3}}, {{2, 4}}, {{2, 3}}},
//              {{{1, 5}}, {{2, 3}}, {{2, 3}}},
//              {{{1, 2}, {3, 4}}, {{2, 3}}, {{2, 2}, {3, 3}}},
//          };
//
//      for (const auto& [arr1, arr2, want] : tests) {
//        auto got = intervalIntersection(arr1, arr2);
//
//        if (got != want) {
//          throw std::runtime_error("\nintervalIntersection(" + intVecVecToStr(arr1) + ", " +
//                                   intVecVecToStr(arr2) + "): got: " + intVecVecToStr(got) +
//                                   ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL INTERVAL INTERSECTION TEST PROVIDED PASSED." << endl;
    
    //Problem 27.12 Array Reversal
    
//    auto charVecToStr = [](const std::vector<char>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += vec[i];
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<char>, std::vector<char>>> tests = {
//          // Test cases
//          {{'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}},
//          {{}, {}},
//          {{'a'}, {'a'}},
//          {{'a', 'b'}, {'b', 'a'}},
//          {{'a', 'b', 'c'}, {'c', 'b', 'a'}},
//          {{'a', 'b', 'c', 'd'}, {'d', 'c', 'b', 'a'}},
//      };
//
//      for (const auto& [arr_orig, want] : tests) {
//        auto arr = arr_orig;  // Make a copy since reverse modifies in place
//        reverse(arr);
//
//        if (arr != want) {
//          throw std::runtime_error("\nreverse(" + charVecToStr(arr_orig) + "): got: " +
//                                   charVecToStr(arr) + ", want: " + charVecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL ARRAY REVERSE TEST PROVIDED PASSED." << endl;
    
    //Problem 27.13 Parity Sorting
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
//          // Example 1 from the book
//          {{1, 2, 3, 4, 5}, {2, 4, 1, 3, 5}},
//          // Example 2 from the book
//          {{5, 1, 3, 1, 5}, {5, 1, 3, 1, 5}},
//          // Additional test cases
//          {{}, {}},
//          {{1}, {1}},
//          {{2}, {2}},
//          {{1, 2}, {2, 1}},
//          {{2, 1}, {2, 1}},
//          {{1, 3, 2, 4}, {2, 4, 1, 3}},
//      };
//
//      for (const auto& [arr_orig, example_solution] : tests) {
//        auto arr = arr_orig;  // Make a copy since sortEven modifies in place
//        sortEven(arr);
//
//        if (!isValidSolutionSortEven(arr, arr_orig)) {
//          throw std::runtime_error("\nsortEven(" + vecToStr(arr_orig) +
//                                   "): got: " + vecToStr(arr) +
//                                   ", example solution: " + vecToStr(example_solution) + "\n");
//        }
//      }
//    
//    cout << "ALL PARITY SORTING TEST PROVIDED PASSED." << endl;
    
    //Problem 27.14 In-Place Duplicate Removal
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> tests = {
//          // Example from the book
//          std::make_tuple(std::vector<int>{1, 2, 2, 3, 3, 3, 5}, 4,
//                          std::vector<int>{1, 2, 3, 5}),
//          // Additional test cases
//          std::make_tuple(std::vector<int>{}, 0, std::vector<int>{}),
//          std::make_tuple(std::vector<int>{1}, 1, std::vector<int>{1}),
//          std::make_tuple(std::vector<int>{1, 1}, 1, std::vector<int>{1}),
//          std::make_tuple(std::vector<int>{1, 2}, 2, std::vector<int>{1, 2}),
//          std::make_tuple(std::vector<int>{1, 1, 1}, 1, std::vector<int>{1}),
//          std::make_tuple(std::vector<int>{1, 2, 2, 2, 3}, 3,
//                          std::vector<int>{1, 2, 3}),
//      };
//
//      for (const auto& [arr_orig, want_len, want_prefix] : tests) {
//        auto arr =
//            arr_orig;  // Make a copy since removeDuplicates modifies in place
//        int got_len = removeDuplicates(arr);
//
//        if (got_len != want_len) {
//          throw std::runtime_error("\nremoveDuplicates(" + vecToStr(arr_orig) +
//                                   "): got length: " + std::to_string(got_len) +
//                                   ", want length: " + std::to_string(want_len) +
//                                   "\n");
//        }
//
//        std::vector<int> got_prefix(arr.begin(), arr.begin() + got_len);
//        if (got_prefix != want_prefix) {
//          throw std::runtime_error("\nremoveDuplicates(" + vecToStr(arr_orig) +
//                                   "): got prefix: " + vecToStr(got_prefix) +
//                                   ", want prefix: " + vecToStr(want_prefix) + "\n");
//        }
//      }
//    
//    cout << "ALL IN-PLACE DUPLICATE REMOVAL TEST PROVIDED PASSED." << endl;
    
    //Problem 27.15 Quicksort Partition
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<int>, int>> tests = {
//          // Example 1 from the book
//          {{1, 7, 2, 3, 3, 5, 3}, 4},
//          // Example 2 from the book
//          {{1, 7, 2, 3, 3, 5, 3}, 3},
//          // Additional test cases
//          {{}, 1},
//          {{1}, 1},
//          {{1, 2}, 1},
//          {{2, 1}, 1},
//          {{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}, 4},
//      };
//
//      for (const auto& [arr_orig, pivot] : tests) {
//        auto arr = arr_orig;  // Make a copy since partition modifies in place
//        partition(arr, pivot);
//
//        if (!isValidPartition(arr, pivot)) {
//          throw std::runtime_error("\npartition(" + vecToStr(arr_orig) + ", " +
//                                   std::to_string(pivot) + "): got: " + vecToStr(arr) +
//                                   "\n");
//        }
//      }
//    
//    cout << "ALL QUICKSORT PARTITION TEST PROVIDED PASSED." << endl;
    
    //Problem 27.16 Dutch Flag Problem
//    auto charVecToStr = [](const std::vector<char>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += vec[i];
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<char>, std::vector<char>>> tests = {
//          // Example from the book
//          {{'R', 'W', 'B', 'B', 'W', 'R', 'W'},
//           {'R', 'R', 'W', 'W', 'W', 'B', 'B'}},
//          // Additional test cases
//          {{}, {}},
//          {{'R'}, {'R'}},
//          {{'W'}, {'W'}},
//          {{'B'}, {'B'}},
//          {{'R', 'W'}, {'R', 'W'}},
//          {{'W', 'R'}, {'R', 'W'}},
//          {{'R', 'W', 'B'}, {'R', 'W', 'B'}},
//          {{'R', 'R', 'R', 'W', 'W', 'B', 'B', 'B'},
//           {'R', 'R', 'R', 'W', 'W', 'B', 'B', 'B'}},
//          {{'B', 'B', 'B', 'W', 'W', 'R', 'R', 'R'},
//           {'R', 'R', 'R', 'W', 'W', 'B', 'B', 'B'}},
//      };
//
//      for (const auto& [arr_orig, want] : tests) {
//        auto arr = arr_orig;  // Make a copy since sortColors modifies in place
//        sortColors(arr);
//
//        if (arr != want) {
//          throw std::runtime_error("\nsortColors(" + charVecToStr(arr_orig) +
//                                   "): got: " + charVecToStr(arr) + ", want: " + charVecToStr(want) +
//                                   "\n");
//        }
//      }
//    
//    cout << "ALL DUTCH FLAG PROBLEM TEST PROVIDED PASSED." << endl;
    
    //Problem 27.17 Prefix-Suffix Swap
//    auto charVecToStr = [](const std::vector<char>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += vec[i];
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<char>, std::vector<char>>> tests = {
//          // Example from the book
//          {{'b', 'a', 'd', 'r', 'e', 'v', 'i', 'e', 'w'},
//           {'r', 'e', 'v', 'i', 'e', 'w', 'b', 'a', 'd'}},
//          // Additional test cases
//          {{}, {}},
//          {{'a', 'b', 'c'}, {'b', 'c', 'a'}},
//          {{'a', 'b', 'c', 'd', 'e', 'f'}, {'c', 'd', 'e', 'f', 'a', 'b'}},
//          {{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
//           {'4', '5', '6', '7', '8', '9', '1', '2', '3'}},
//          {{'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'},
//           {'b', 'b', 'b', 'c', 'c', 'c', 'a', 'a', 'a'}},
//      };
//
//      for (const auto& [arr_orig, want] : tests) {
//        auto arr =
//            arr_orig;  // Make a copy since swapPrefixSuffix modifies in place
//        swapPrefixSuffix(arr);
//
//        if (arr != want) {
//          throw std::runtime_error("\nswapPrefixSuffix(" + charVecToStr(arr_orig) +
//                                   "): got: " + charVecToStr(arr) + ", want: " + charVecToStr(want) +
//                                   "\n");
//        }
//      }
//    
//    cout << "ALL PREFIX-SUFFIX SWAP TEST PROVIDED PASSED." << endl;
    
    //Problem 27.18 Shift Word to Back
    
//    auto charVecToStr = [](const std::vector<char>& vec) {
//      std::string result = "[";
//      for (size_t i = 0; i < vec.size(); i++) {
//        if (i > 0) result += ", ";
//        result += vec[i];
//      }
//      result += "]";
//      return result;
//    };
//
//    std::vector<std::tuple<std::vector<char>, std::string, std::vector<char>>>
//        tests = {
//            // Example 1 from the book
//            {std::vector<char>({'s', 'e', 'e', 'k', 'e', 'r', 'a', 'n', 'd', 'w',
//                                'r', 'i', 't', 'e', 'r'}),
//             std::string("edit"),
//             std::vector<char>({'s', 'e', 'k', 'e', 'r', 'a', 'n', 'w', 'r', 'e',
//                                'r', 'e', 'd', 'i', 't'})},
//            // Example 2 from the book
//            {std::vector<char>({'b', 'a', 'c', 'b'}), std::string("ab"),
//             std::vector<char>({'b', 'c', 'a', 'b'})},
//            // Example 3 from the book
//            {std::vector<char>({'b', 'a', 'b', 'c'}), std::string("b"),
//             std::vector<char>({'a', 'b', 'c', 'b'})},
//            // Additional test cases
//            {std::vector<char>(), std::string(""), std::vector<char>()},
//            {std::vector<char>({'a'}), std::string("a"),
//             std::vector<char>({'a'})},
//            {std::vector<char>({'a', 'b', 'c'}), std::string(""),
//             std::vector<char>({'a', 'b', 'c'})},
//            {std::vector<char>({'h', 'e', 'l', 'l', 'o'}), std::string("ho"),
//             std::vector<char>({'e', 'l', 'l', 'h', 'o'})},
//            {std::vector<char>({'a', 'b', 'c', 'a', 'b', 'c'}),
//             std::string("abc"),
//             std::vector<char>({'a', 'b', 'c', 'a', 'b', 'c'})},
//        };
//
//    for (const auto& [arr, word, want] : tests) {
//      auto got = arr;  // Make a copy since moveWord modifies in place
//      moveWord(got, word);
//      if (got != want) {
//        throw std::runtime_error("\nmoveWord(" + charVecToStr(arr) + ", \"" + word +
//                                 "\"): got: " + charVecToStr(got) + ", want: " + charVecToStr(want) +
//                                 "\n");
//      }
//    }
//    
//    cout << "ALL SHIFT WORD TO BACK TEST PROVIDED PASSED." << endl;
//
    //Problem 28.1 Chess Moves
//      auto intVecToStr = [](const vector<int>& vec) {
//        string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const vector<vector<int>>& vec) {
//        string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      struct Test {
//        vector<vector<int>> board;
//        string piece;
//        int r;
//        int c;
//        vector<vector<int>> want;
//      };
//
//      vector<Test> tests = {
//          // Example 1 from the book - king moves
//          {{{0, 0, 0, 1, 0, 0},
//            {0, 1, 1, 1, 0, 0},
//            {0, 1, 0, 1, 1, 0},
//            {1, 1, 1, 1, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 1, 0, 0, 0, 0}},
//           "king",
//           3,
//           5,
//           {{2, 5}, {3, 4}, {4, 4}, {4, 5}}},
//          // Example 2 from the book - knight moves
//          {{{0, 0, 0, 1, 0, 0},
//            {0, 1, 1, 1, 0, 0},
//            {0, 1, 0, 1, 1, 0},
//            {1, 1, 1, 1, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 1, 0, 0, 0, 0}},
//           "knight",
//           4,
//           3,
//           {{2, 2}, {3, 5}, {5, 5}}},
//          // Example 3 from the book - queen moves
//          {{{0, 0, 0, 1, 0, 0},
//            {0, 1, 1, 1, 0, 0},
//            {0, 1, 0, 1, 1, 0},
//            {1, 1, 1, 1, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 1, 0, 0, 0, 0}},
//           "queen",
//           4,
//           4,
//           {{3, 4},
//            {3, 5},
//            {4, 0},
//            {4, 1},
//            {4, 2},
//            {4, 3},
//            {4, 5},
//            {5, 3},
//            {5, 4},
//            {5, 5}}},
//          // Edge case - 1x1 board
//          {{{0}}, "queen", 0, 0, {}},
//          // Edge case - all occupied except current position
//          {{{1, 1}, {1, 0}}, "knight", 1, 1, {}},
//      };
//
//      for (const auto& test : tests) {
//        auto got = chessMoves(test.board, test.piece, test.r, test.c);
//        // Sort both vectors for consistent comparison
//        std::sort(got.begin(), got.end());
//        auto want = test.want;
//        std::sort(want.begin(), want.end());
//
//        if (got != want) {
//          throw std::runtime_error("\nchessMoves(" + intVecVecToStr(test.board) + ", " + test.piece +
//                                   ", " + std::to_string(test.r) + ", " +
//                                   std::to_string(test.c) + "): got: " + intVecVecToStr(got) +
//                                   ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//
//    cout << "ALL CHESS MOVES TEST PROVIDED PASSED." << endl;
    
    //Problem 28.2 Queen's Reach
//    auto intVecToStr = [](const vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const vector<vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      vector<std::pair<vector<vector<int>>, vector<vector<int>>>> tests = {
//          {{{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}},
//           {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}}},
//          // Edge case - 1x1 board with queen
//          {{{1}}, {{1}}},
//          // Edge case - 1x1 board without queen
//          {{{0}}, {{0}}},
//          // Edge case - no queens
//          {{{0, 0}, {0, 0}}, {{0, 0}, {0, 0}}},
//      };
//
//      for (const auto& [board, want] : tests) {
//        auto got = safeCells(board);
//        if (got != want) {
//          throw std::runtime_error("\nsafeCells(" + intVecVecToStr(board) + "): got: " +
//                                   intVecVecToStr(got) + ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL QUEEN'S REACH TEST PROVIDED PASSED." << endl;
    
    //Problem 28.3 - Spiral Order
    
//      auto intVecToStr = [](const vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const vector<vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      vector<std::pair<int, vector<vector<int>>>> tests = {
//          // Example from book
//          {5,
//           {{16, 17, 18, 19, 20},
//            {15, 4, 5, 6, 21},
//            {14, 3, 0, 7, 22},
//            {13, 2, 1, 8, 23},
//            {12, 11, 10, 9, 24}}},
//          // Edge case - 1x1
//          {1, {{0}}},
//          // Edge case - 3x3
//          {3, {{4, 5, 6}, {3, 0, 7}, {2, 1, 8}}},
//      };
//
//      for (const auto& [n, want] : tests) {
//        auto got = spiral(n);
//        if (got != want) {
//          throw std::runtime_error("\nspiral(" + std::to_string(n) + "): got: " +
//                                   intVecVecToStr(got) + ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//
//
//    cout << "ALL SPIRAL ORDER TEST PROVIDED PASSED." << endl;
    
    //Problem 28.4 - Snowprints
    
//    vector<std::pair<vector<vector<int>>, int>> tests = {
//          // Example from book
//          {{{0, 0, 0, 0, 0, 0},
//            {0, 0, 1, 0, 0, 0},
//            {1, 1, 0, 1, 0, 0},
//            {0, 0, 0, 0, 1, 1}},
//           1},
//          // Edge case - top of grid
//          {{{0, 0, 0, 1, 0, 0},
//            {0, 0, 1, 0, 1, 0},
//            {1, 1, 0, 0, 0, 1},
//            {0, 0, 0, 0, 0, 0}},
//           0},
//          // Edge case - bottom of grid
//          {{{0, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {1, 1, 1, 1, 1, 1}},
//           3},
//          // Edge case - single column
//          {{{0}, {1}}, 1},
//          // Edge case - single row
//          {{{1, 1, 1}}, 0},
//          // Edge case - zigzag path
//          {{{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 1},
//      };
//
//      for (const auto& [field, want] : tests) {
//        int got = distanceToRiver(field);
//        if (got != want) {
//          std::string field_str = "[";
//          for (size_t i = 0; i < field.size(); i++) {
//            field_str += "[";
//            for (size_t j = 0; j < field[i].size(); j++) {
//              field_str += std::to_string(field[i][j]);
//              if (j < field[i].size() - 1) field_str += ", ";
//            }
//            field_str += "]";
//            if (i < field.size() - 1) field_str += ", ";
//          }
//          field_str += "]";
//
//          throw std::runtime_error("\ndistanceToRiver(" + field_str +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL SNOWPRINTS TEST PROVIDED PASSED." << endl;
    
    //Problem 28.5 - Valid Sudoku
    
//    vector<std::pair<vector<vector<int>>, bool>> tests = {
//          // Example 1 from book - valid sudoku
//          {{{5, 0, 0, 0, 0, 0, 0, 0, 6},
//            {0, 0, 9, 0, 5, 0, 3, 0, 0},
//            {0, 3, 0, 0, 0, 2, 0, 0, 0},
//            {8, 0, 0, 7, 0, 0, 0, 0, 9},
//            {0, 0, 2, 0, 0, 0, 8, 0, 0},
//            {4, 0, 0, 0, 0, 6, 0, 0, 3},
//            {0, 0, 0, 3, 0, 0, 0, 4, 0},
//            {0, 0, 3, 0, 8, 0, 2, 0, 0},
//            {9, 0, 0, 0, 0, 0, 0, 0, 7}},
//           true},
//          // Example 2 from book - invalid sudoku (duplicate 7 in bottom right subgrid)
//          {{{5, 0, 0, 0, 0, 0, 0, 0, 6},
//            {0, 0, 9, 0, 5, 0, 3, 0, 0},
//            {0, 3, 0, 0, 0, 2, 0, 0, 0},
//            {8, 0, 0, 7, 0, 0, 0, 0, 9},
//            {0, 0, 2, 0, 0, 0, 8, 0, 0},
//            {4, 0, 0, 0, 0, 6, 0, 0, 3},
//            {0, 0, 0, 3, 0, 0, 0, 4, 0},
//            {0, 0, 3, 0, 8, 0, 7, 0, 0},
//            {9, 0, 0, 0, 0, 0, 0, 0, 7}},
//           false},
//          // Edge case - empty board
//          {vector<vector<int>>(9, vector<int>(9, 0)), true},
//          // Edge case - full valid board
//          {{{1, 2, 3, 4, 5, 6, 7, 8, 9},
//            {4, 5, 6, 7, 8, 9, 1, 2, 3},
//            {7, 8, 9, 1, 2, 3, 4, 5, 6},
//            {2, 3, 1, 5, 6, 4, 8, 9, 7},
//            {5, 6, 4, 8, 9, 7, 2, 3, 1},
//            {8, 9, 7, 2, 3, 1, 5, 6, 4},
//            {3, 1, 2, 6, 4, 5, 9, 7, 8},
//            {6, 4, 5, 9, 7, 8, 3, 1, 2},
//            {9, 7, 8, 3, 1, 2, 6, 4, 5}},
//           true},
//      };
//
//      
//      for (const auto& [board, want] : tests) {
//          bool got = validSudoku(board);
//        if (got != want) {
//          std::string board_str = "[";
//          for (size_t i = 0; i < board.size(); i++) {
//            board_str += "[";
//            for (size_t j = 0; j < board[i].size(); j++) {
//              board_str += std::to_string(board[i][j]);
//              if (j < board[i].size() - 1) board_str += ", ";
//            }
//            board_str += "]";
//            if (i < board.size() - 1) board_str += ", ";
//          }
//          board_str += "]";
//
//          throw std::runtime_error("\nsolve(" + board_str +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL VALID SUDOKU TEST PROVIDED PASSED." << endl;

//    auto intVecToStr = [](const vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const vector<vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      vector<std::pair<vector<vector<int>>, vector<vector<int>>>> tests;
//
//      // Example from book
//      tests.push_back(
//          std::make_pair(vector<vector<int>>{{1, 5, 3}, {4, -1, 0}, {2, 0, 2}},
//                         vector<vector<int>>{{5, 5, 3}, {4, 2, 2}, {2, 2, 2}}));
//
//      // Edge case - 1x1 grid
//      tests.push_back(
//          std::make_pair(vector<vector<int>>{{5}}, vector<vector<int>>{{5}}));
//
//      // Edge case - single row
//      tests.push_back(std::make_pair(vector<vector<int>>{{1, 2, 3}},
//                                     vector<vector<int>>{{3, 3, 3}}));
//
//      // Edge case - single column
//      tests.push_back(std::make_pair(vector<vector<int>>{{1}, {2}, {3}},
//                                     vector<vector<int>>{{3}, {3}, {3}}));
//
//      // Edge case - negative numbers
//      tests.push_back(std::make_pair(vector<vector<int>>{{-1, -2}, {-3, -4}},
//                                     vector<vector<int>>{{-1, -2}, {-3, -4}}));
//
//      for (const auto& [grid, want] : tests) {
//        auto got = subgridMaximums(grid);
//        if (got != want) {
//          throw std::runtime_error("\nsubgridMaximums(" + intVecVecToStr(grid) + "): got: " +
//                                   intVecVecToStr(got) + ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL SUBGRID MAXIMUMS TEST PROVIDED PASSED." << endl;
    
    //Problem 28.7 Subgrid Sums
    
//    auto intVecToStr = [](const vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const vector<vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      vector<std::pair<vector<vector<int>>, vector<vector<int>>>> tests = {
//          // Example from book
//          {{{-1, 2, 3}, {4, 0, 0}, {-2, 0, 9}},
//           {{15, 14, 12}, {11, 9, 9}, {7, 9, 9}}},
//          // Edge case - 1x1 grid
//          {{{5}}, {{5}}},
//          // Edge case - single row
//          {{{1, 2, 3}}, {{6, 5, 3}}},
//          // Edge case - single column
//          {{{1}, {2}, {3}}, {{6}, {5}, {3}}},
//          // Edge case - all zeros
//          {{{0, 0}, {0, 0}}, {{0, 0}, {0, 0}}},
//      };
//
//      for (const auto& [grid, want] : tests) {
//        auto got = subgridSums(grid);
//        if (got != want) {
//          throw std::runtime_error("\nsubgridSums(" + intVecVecToStr(grid) + "): got: " +
//                                   intVecVecToStr(got) + ", want: " + intVecVecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL SUBGRID SUMS TESTS PROVIDED PASSED." << endl;
    
    //Problem 28.8 Matrix Operations
//    auto doubleVecToStr = [](const vector<double>& vec) {
//        string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto doubleVecVecToStr = [&](const vector<vector<double>>& vec) {
//        string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += doubleVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      struct Test {
//        vector<vector<double>> grid;
//        string operation;
//        vector<vector<double>> want;
//      };
//
//      vector<Test> tests = {
//          // Test transpose
//          {{{1.0, 2.0}, {3.0, 4.0}}, "transpose", {{1.0, 3.0}, {2.0, 4.0}}},
//          // Test horizontal reflection
//          {{{1.0, 2.0}, {3.0, 4.0}}, "reflectHorizontally", {{2.0, 1.0}, {4.0, 3.0}}},
//          // Test vertical reflection
//          {{{1.0, 2.0}, {3.0, 4.0}}, "reflectVertically", {{3.0, 4.0}, {1.0, 2.0}}},
//          // Test clockwise rotation
//          {{{1.0, 2.0}, {3.0, 4.0}}, "rotateClockwise", {{3.0, 1.0}, {4.0, 2.0}}},
//          // Test counterclockwise rotation
//          {{{1.0, 2.0}, {3.0, 4.0}}, "rotateCounterclockwise", {{2.0, 4.0}, {1.0, 3.0}}},
//          // Edge case - 1x1 matrix
//          {{{5.0}}, "transpose", {{5.0}}},
//          // Edge case - 3x3 matrix
//          {{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}},
//           "rotateClockwise",
//           {{7.0, 4.0, 1.0}, {8.0, 5.0, 2.0}, {9.0, 6.0, 3.0}}},
//      };
//
//      for (const auto& test : tests) {
//        MatrixOperations matrix(test.grid);
//        if (test.operation == "transpose") {
//          matrix.transpose();
//        } else if (test.operation == "reflectHorizontally") {
//          matrix.reflectHorizontally();
//        } else if (test.operation == "reflectVertically") {
//          matrix.reflectVertically();
//        } else if (test.operation == "rotateClockwise") {
//          matrix.rotateClockwise();
//        } else if (test.operation == "rotateCounterclockwise") {
//          matrix.rotateCounterclockwise();
//        }
//
//        auto got = matrix.getMatrix();
//        if (got != test.want) {
//          throw std::runtime_error("\nMatrix(" + doubleVecVecToStr(test.grid) + ")." + test.operation +
//                                   "(): got: " + doubleVecVecToStr(got) + ", want: " + doubleVecVecToStr(test.want) +
//                                   "\n");
//        }
//      }
//    
//    cout << "ALL MATRIX OPERATIONS TEST PROVIDED PASSED." << endl;
    
    //Problem 29.1 Search in Sorted Array
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string str = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) str += ", ";
//          str += std::to_string(vec[i]);
//        }
//        str += "]";
//        return str;
//      };
//
//      std::vector<std::tuple<std::vector<int>, int, int>> tests = {
//          // Example 1 from book
//          {{-2, 0, 3, 4, 7, 9, 11}, 3, 2},
//          // Example 2 from book
//          {{-2, 0, 3, 4, 7, 9, 11}, 2, -1},
//          // Edge case - empty array
//          {{}, 5, -1},
//          // Edge case - target at start
//          {{1, 2, 3}, 1, 0},
//          // Edge case - target at end
//          {{1, 2, 3}, 3, 2},
//          // Edge case - single element
//          {{5}, 5, 0},
//          // Edge case - not found
//          {{1, 3, 5}, 2, -1}};
//
//      for (const auto& [arr, target, want] : tests) {
//        int got = searchInSortedArray(arr, target);
//        if (got != want) {
//          throw std::runtime_error("\nsearchInSortedArray(" + vecToStr(arr) + ", " +
//                                   std::to_string(target) +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//    }
//      
//    cout << "ALL SEARCH IN SORTED ARRAY TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.3 Valley Bottom
    
//    std::vector<std::tuple<std::vector<int>, int>> tests = {
//          // Example 1 from book
//          {{6, 5, 4, 7, 9}, 4},
//          // Example 2 from book
//          {{5, 6, 7}, 5},
//          // Example 3 from book
//          {{7, 6, 5}, 5},
//          // Edge case - 2 elements
//          {{2, 1}, 1},
//          // Edge case - 3 elements
//          {{3, 2, 4}, 2}};
//
//      for (const auto& [arr, want] : tests) {
//        int got = valleyBottom(arr);
//        if (got != want) {
//          std::string arr_str = "[";
//          for (size_t i = 0; i < arr.size(); i++) {
//            if (i > 0) arr_str += ", ";
//            arr_str += std::to_string(arr[i]);
//          }
//          arr_str += "]";
//
//          throw std::runtime_error("\nvalleyBottom(" + arr_str +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL VALLEY BOTTOM TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.4 2-Array 2-Sum
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//      std::string str = "[";
//      for (size_t i = 0; i < vec.size(); i++) {
//        if (i > 0) str += ", ";
//        str += std::to_string(vec[i]);
//      }
//      str += "]";
//      return str;
//    };
//
//    std::vector<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>>
//        tests = {
//                  {{-5, -4, -1, 4, 6, 6, 7}, {-3, 7, 18, 4, 6}, {1, 3}},
//                  {{1, 2, 3}, {1, 2, 3}, {-1, -1}},
//                  {{1}, {-1}, {0, 0}},
//                  {{1, 2}, {-2, -1}, {1, 0}},
//                  {{0, 1, 2, 3}, {3, 2, 1, 0}, {0, 3}}};
//
//    for (const auto& [sortedArr, unsortedArr, want] : tests) {
//      auto got = twoArrayTwoSum(sortedArr, unsortedArr);
//      if (got != want) {
//        throw std::runtime_error("\ntwoArrayTwoSum(" + vecToStr(sortedArr) + ", " +
//                                 vecToStr(unsortedArr) + "): got: " +
//                                 vecToStr(got) + ", want: " + vecToStr(want) + "\n");
//      }
//    }
//    
//    cout << "ALL 2-ARRAY 2-SUM TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.5 Target Count Divisible by K
    
//    std::vector<std::tuple<std::vector<int>, int, int, bool>> tests = {
//          // Example 1
//          {{1, 2, 2, 2, 2, 2, 2, 3}, 2, 3, true},
//          // Example 2
//          {{1, 2, 2, 2, 2, 2, 2, 3}, 2, 4, false},
//          // Example 3: 0 occurrences, 0 is multiple of any number
//          {{1, 2, 2, 2, 2, 2, 2, 3}, 4, 3, true},
//          // Example 4
//          {{1, 1, 2, 2, 2}, 1, 3, false},
//          // single occurrence, at the start
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 1, 1, true},
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 1, 2, false},
//          // single occurrence, at the end
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 19, 1, true},
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 19, 2, false},
//          // single occurrence, in the middle
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 9, 1, true},
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 9, 2, false},
//          // smaller than any elements
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 0, 1, true},
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 0, 2, true},
//          // larger than any elements
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 20, 1, true},
//          {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 20, 2, true},
//          // Edge case - every occurrence is target
//          {{5, 5, 5, 5, 5}, 5, 5, true},
//          {{5, 5, 5, 5, 5}, 5, 3, false},
//      };
//
//
//      for (const auto& [arr, target, k, want] : tests)
//      {
//          bool got = targetCountDivisibleByK(arr, target, k);
//        std::string arr_str = "[";
//        for (size_t i = 0; i < arr.size(); i++) {
//          if (i > 0) arr_str += ", ";
//          arr_str += std::to_string(arr[i]);
//        }
//        arr_str += "]";
//
//        if (got != want) {
//          throw std::runtime_error(
//              "\nsolve(" + arr_str + ", " + std::to_string(target) + ", " +
//              std::to_string(k) + "): got: " + std::to_string(got) +
//              ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL TARGET COUNT DIVISIBLE BY K TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.6 Race Overtaking
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//      std::string str = "[";
//      for (size_t i = 0; i < vec.size(); i++) {
//        if (i > 0) str += ", ";
//        str += std::to_string(vec[i]);
//      }
//      str += "]";
//      return str;
//    };
//
//    std::vector<std::tuple<std::vector<int>, std::vector<int>, int>> tests = {
//        // Example 1 from book
//        {{2, 4, 6, 8, 10}, {1, 3, 5, 9, 11}, 3},
//        // Example
//        {{2, 3, 4, 5, 6}, {1, 2, 3, 6, 7}, 3},
//        // Example
//        {{3, 4, 5}, {2, 5, 6}, 1},
//        // Edge case - overtake at start
//        {{2, 3}, {1, 4}, 1}};
//
//    for (const auto& [p1, p2, want] : tests) {
//      int got = raceOvertaking(p1, p2);
//      if (got != want) {
//        throw std::runtime_error("\nraceOvertaking(" + vecToStr(p1) + ", " +
//                               vecToStr(p2) + "): got: " + std::to_string(got) +
//                               ", want: " + std::to_string(want) + "\n");
//      }
//    }
//    
//    cout << "ALL RACE OVERTAKING TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.7 Search in Sorted Grid
    
//    auto gridToStr = [](const std::vector<std::vector<int>>& grid) {
//        std::string str = "[";
//        for (size_t i = 0; i < grid.size(); i++) {
//          if (i > 0) str += ", ";
//          str += "[";
//          for (size_t j = 0; j < grid[i].size(); j++) {
//            if (j > 0) str += ", ";
//            str += std::to_string(grid[i][j]);
//          }
//          str += "]";
//        }
//        str += "]";
//        return str;
//      };
//
//      std::vector<std::tuple<std::vector<std::vector<int>>, int, std::vector<int>>>
//          tests = {// Example 1
//                   {{{1, 3, 5}, {7, 9, 11}, {13, 15, 17}}, 9, {1, 1}},
//                   // Example 2
//                   {{{1, 3, 5}, {7, 9, 11}}, 4, {-1, -1}},
//                   // 2x2 grid, all grid after
//                   {{{2, 3}, {4, 5}}, 1, {-1, -1}},
//                   // 2x2 grid, all grid before
//                   {{{1, 2}, {3, 4}}, 5, {-1, -1}},
//                   // 3x2 grid, first element
//                   {{{1, 2}, {3, 4}, {5, 6}}, 1, {0, 0}},
//                   // 2x3 grid, last element
//                   {{{1, 2, 3}, {4, 5, 6}}, 6, {1, 2}},
//                   // Single element edge case
//                   {{{7}}, 7, {0, 0}},
//                   // Single element edge case (not found)
//                   {{{7}}, 6, {-1, -1}}};
//
//      for (const auto& [grid, target, want] : tests) {
//        auto got = searchInSortedGrid(grid, target);
//        if (got != want) {
//          std::string got_str =
//              "[" + std::to_string(got[0]) + ", " + std::to_string(got[1]) + "]";
//          std::string want_str =
//              "[" + std::to_string(want[0]) + ", " + std::to_string(want[1]) + "]";
//
//          throw std::runtime_error("\nsearchInSortedGrid(" + gridToStr(grid) + ", " +
//                                   std::to_string(target) + "): got: " + got_str +
//                                   ", want: " + want_str + "\n");
//        }
//      }
//    
//    cout << "ALL SEARCH IN SORTED GRID TESTS PROVIDED PASSED." << endl;
    
    //Problem 29.12 - Tide Aerial View
    
//    std::vector<std::tuple<std::vector<std::vector<std::vector<int>>>, int>>
//          tests = {// Example from the book
//                   {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
//                     {{1, 0, 0}, {0, 0, 0}, {1, 0, 0}},
//                     {{1, 1, 0}, {0, 0, 0}, {1, 0, 0}},
//                     {{1, 1, 0}, {1, 1, 1}, {1, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {1, 1, 0}}},
//                    2},
//                   // 3 pictures with increasing water
//                   {{{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}},
//                     {{1, 1, 0}, {1, 1, 0}, {1, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}},
//                    1},
//                   // 2 pictures
//                   {{{{1, 0}, {0, 0}}, {{1, 1}, {1, 0}}}, 0},
//                   // Incremental progression
//                   {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
//                     {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}},
//                     {{1, 0, 0}, {1, 0, 0}, {0, 0, 0}},
//                     {{1, 1, 0}, {1, 0, 0}, {0, 0, 0}},
//                     {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 0}, {0, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {0, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {1, 1, 0}},
//                     {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}},
//                    4},
//                   // Edge case - single picture
//                   {{{{1, 1}, {0, 0}}}, 0},
//                   // Edge case - all water
//                   {{{{1, 1}, {1, 1}}}, 0},
//                   // Edge case - all land
//                   {{{{0, 0}, {0, 0}}}, 0}};
//
//      for (const auto& [pictures, want] : tests) {
//        int got = tideAerialView(pictures);
//        if (got != want) {
//          std::string pictures_str = "[";
//          for (size_t i = 0; i < pictures.size(); i++) {
//            if (i > 0) pictures_str += ", ";
//            pictures_str += "[";
//            for (size_t j = 0; j < pictures[i].size(); j++) {
//              if (j > 0) pictures_str += ", ";
//              pictures_str += "[";
//              for (size_t k = 0; k < pictures[i][j].size(); k++) {
//                if (k > 0) pictures_str += ", ";
//                pictures_str += std::to_string(pictures[i][j][k]);
//              }
//              pictures_str += "]";
//            }
//            pictures_str += "]";
//          }
//          pictures_str += "]";
//
//          throw std::runtime_error("\ntideAerialView(" + pictures_str +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL TIDE AERIAL VIEW TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.1 - Account Sharing Detection
    
//    std::vector<
//          std::pair<std::vector<std::pair<std::string, std::string>>, std::string>>
//          tests = {// Example 1
//                   {{{"203.0.113.10", "mike"},
//                     {"298.51.100.25", "bob"},
//                     {"292.0.2.5", "mike"},
//                     {"203.0.113.15", "bob2"}},
//                    "292.0.2.5"},
//                   // Example 2
//                   {{{"111.0.0.0", "mike"},
//                     {"111.0.0.1", "mike"},
//                     {"111.0.0.2", "bob"},
//                     {"111.0.0.3", "bob"}},
//                    "111.0.0.1"},
//                   // Example 3
//                   {{{"111.0.0.0", "mike"},
//                     {"111.0.0.1", "mike2"},
//                     {"111.0.0.2", "mike3"},
//                     {"111.0.0.3", "mike4"}},
//                    ""},
//                   // Edge case - empty list
//                   {{}, ""},
//                   // Edge case - single connection
//                   {{{"1.1.1.1", "alice"}}, ""}};
//
//      for (const auto& [connections, want] : tests) {
//        auto got = accountSharing(connections);
//        if (got != want) {
//          std::string connections_str = "[";
//          for (size_t i = 0; i < connections.size(); i++) {
//            if (i > 0) connections_str += ", ";
//            connections_str += "(\"" + connections[i].first + "\", \"" +
//                               connections[i].second + "\")";
//          }
//          connections_str += "]";
//
//          throw std::runtime_error("\naccountSharing(" + connections_str +
//                                   "): got: \"" + got + "\", want: \"" + want +
//                                   "\"\n");
//        }
//      }
//    
//    cout << "ALL ACCOUNT SHARING DETECTION TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.2 - Most Shared Account
    
//    auto connectionVecToStr = [](const std::vector<std::pair<std::string, std::string>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += "(\"" + vec[i].first + "\", \"" + vec[i].second + "\")";
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<
//          std::pair<std::vector<std::pair<std::string, std::string>>, std::string>>
//          tests = {// Example
//                   {{{"203.0.113.10", "mike"},
//                     {"208.51.100.25", "bob"},
//                     {"202.0.2.5", "mike"},
//                     {"203.0.113.15", "bob2"}},
//                    "mike"},
//                   // Additional test cases
//                   {{}, ""},
//                   {{{"1.1.1.1", "alice"}}, "alice"},
//                   {{{"1.1.1.1", "alice"},
//                     {"1.1.1.2", "bob"},
//                     {"1.1.1.3", "alice"},
//                     {"1.1.1.4", "bob"}},
//                    "alice"}};
//
//      for (const auto& [connections, want] : tests) {
//        auto got = mostSharedAccount(connections);
//
//        // Check if got matches want directly
//        if (got == want) {
//          continue;
//        }
//
//        // If want is empty, got must also be empty
//        if (want.empty()) {
//          if (!got.empty()) {
//            throw std::runtime_error("\nmostSharedAccount(" + connectionVecToStr(connections) +
//                                     "): got: \"" + got + "\", want: \"" + want +
//                                     "\"\n");
//          }
//          continue;
//        }
//
//        // Count occurrences of got and want in connections
//        int gotCount = 0, wantCount = 0;
//        for (const auto& [_, user] : connections) {
//          if (user == got) gotCount++;
//          if (user == want) wantCount++;
//        }
//
//        if (gotCount != wantCount) {
//          throw std::runtime_error("\nmostSharedAccount(" + connectionVecToStr(connections) +
//                                   "): got: \"" + got + "\", want: \"" + want +
//                                   "\"\n");
//        }
//      }
//    
//    cout << "ALL MOST SHARED ACCOUNT TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.3 - Most Frequent Octet
    
//    std::vector<std::pair<std::vector<std::string>, std::string>> tests = {
//          // Example
//          {{"203.0.113.10", "208.51.100.5", "202.0.2.5", "203.0.113.5"}, "203"},
//          // Additional test cases
//          {{}, ""},
//          {{"192.168.1.1"}, "192"},
//          {{"10.0.0.1", "10.0.0.2", "192.168.1.1"}, "10"},
//          {{"172.16.0.1", "172.16.0.2", "172.17.0.1", "172.16.0.3"}, "172"}};
//
//      for (const auto& [ips, want] : tests) {
//        auto got = mostFrequentOctet(ips);
//        if (got != want) {
//          std::string ips_str = "[";
//          for (size_t i = 0; i < ips.size(); i++) {
//            if (i > 0) ips_str += ", ";
//            ips_str += "\"" + ips[i] + "\"";
//          }
//          ips_str += "]";
//
//          throw std::runtime_error("\nmostFrequentOctet(" + ips_str + "): got: \"" +
//                                   got + "\", want: \"" + want + "\"\n");
//        }
//      }
//    
//    cout << "ALL MOST FREQUENT OCTET TESTS PASSED." << endl;
    
    //Problem 30.4 - Multi-Account Cheating
    
//    std::vector<std::pair<
//          std::vector<std::pair<std::string, std::vector<std::string>>>, bool>>
//          tests = {
//              // Example
//              {{{"mike", {"203.0.3.10", "208.51.0.5", "52.0.2.5"}},
//                {"bob", {"111.0.0.10", "222.0.0.5", "222.0.0.8"}},
//                {"bob2", {"222.0.0.5", "222.0.0.8", "111.0.0.10"}}},
//               true},
//              // Additional test cases
//              {{}, false},
//              {{{"alice", {"1.1.1.1"}}}, false},
//              {{{"alice", {"1.1.1.1", "2.2.2.2"}}, {"bob", {"2.2.2.2", "1.1.1.1"}}},
//               true},
//              {{{"alice", {"1.1.1.1"}}, {"bob", {"2.2.2.2"}}}, false}};
//
//      for (const auto& [users, want] : tests) {
//        auto got = multiAccountCheating(users);
//        if (got != want) {
//          std::string users_str = "[";
//          for (size_t i = 0; i < users.size(); i++) {
//            if (i > 0) users_str += ", ";
//            users_str += "(\"" + users[i].first + "\", [";
//            for (size_t j = 0; j < users[i].second.size(); j++) {
//              if (j > 0) users_str += ", ";
//              users_str += "\"" + users[i].second[j] + "\"";
//            }
//            users_str += "])";
//          }
//          users_str += "]";
//
//          throw std::runtime_error("\nmultiAccountCheating(" + users_str +
//                                   "): got: " + (got ? "true" : "false") +
//                                   ", want: " + (want ? "true" : "false") + "\n");
//        }
//      }
//    
//    cout << "ALL MULTI-ACCOUNT CHEATING TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.5 - Domain Resolver
    
//    struct Operation {
//        std::string op;
//        std::string arg1;
//        std::string arg2;
//        std::string arg3;
//        bool is_has_subdomain;
//      };
//
//      struct TestCase {
//        std::vector<Operation> operations;
//        std::vector<bool> wants;  // expected bool result for each operation
//      };
//
//      std::vector<TestCase> tests = {
//          // Example
//          {{{"register_domain", "192.168.1.1", "example.com", "", false},
//            {"register_domain", "192.168.1.1", "example.org", "", false},
//            {"register_domain", "192.168.1.2", "domain.com", "", false},
//            {"register_subdomain", "example.com", "a", "", false},
//            {"register_subdomain", "example.com", "b", "", false},
//            {"has_subdomain", "192.168.1.1", "example.com", "a", true},
//            {"has_subdomain", "192.168.1.1", "example.com", "c", true},
//            {"has_subdomain", "127.0.0.1", "example.com", "a", true},
//            {"has_subdomain", "192.168.1.1", "example.org", "a", true},
//            {"has_subdomain", "192.168.1.2", "example.com", "a", false}},
//           {true, true, true, true, true, true, false, false, false, false}},
//          // Additional test cases
//          {{{"register_domain", "1.1.1.1", "test.com", "", false},
//            {"register_subdomain", "test.com", "www", "", false},
//            {"has_subdomain", "1.1.1.1", "test.com", "www", true}},
//           {true, true, true}},
//          {{{"register_domain", "1.1.1.1", "site1.com", "", false},
//            {"register_domain", "2.2.2.2", "site2.com", "", false},
//            {"register_subdomain", "site1.com", "www", "", false},
//            {"register_subdomain", "site2.com", "www", "", false},
//            {"has_subdomain", "1.1.1.1", "site1.com", "www", true},  // Should be true
//            {"has_subdomain", "2.2.2.2", "site2.com", "www", true},  // Should be true
//            {"has_subdomain", "1.1.1.1", "site2.com", "www", true},  // Should be false (wrong IP)
//            {"has_subdomain", "2.2.2.2", "site1.com", "www", true}}, // Should be false (wrong IP)
//           {true, true, true, true, true, true, false, false}}};
//
//      for (const auto& test : tests) {
//        DomainResolver resolver;
//        for (size_t i = 0; i < test.operations.size(); i++) {
//          const auto& op = test.operations[i];
//          bool want = test.wants[i];
//
//          if (!op.is_has_subdomain) {
//            if (op.op == "register_domain") {
//              resolver.registerDomain(op.arg1, op.arg2);
//            } else {  // register_subdomain
//              resolver.registerSubdomain(op.arg1, op.arg2);
//            }
//          } else {
//            bool got = resolver.hasSubdomain(op.arg1, op.arg2, op.arg3);
//            if (got != want) {
//              throw std::runtime_error(
//                  "\n" + op.op + "(\"" + op.arg1 + "\", \"" + op.arg2 + "\", \"" +
//                  op.arg3 + "\"): got: " + (got ? "true" : "false") +
//                  ", want: " + (want ? "true" : "false") + "\n");
//            }
//          }
//        }
//      }
//    
//    cout << "ALL DOMAIN RESOLVER TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.6 Find All Squares
    
//    auto intVecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const std::vector<std::vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<int>, std::vector<std::vector<int>>>>
//          tests = {// Example
//                   {{4, 10, 3, 100, 5, 2, 10000}, {{5, 0}, {1, 3}, {3, 6}}},
//                   // Additional test cases
//                   {{}, {}},
//                   {{1}, {{0, 0}}},
//                   {{2, 4}, {{0, 1}}}};
//
//      for (const auto& [arr, want] : tests) {
//        auto got = findSquared(arr);
//        // Sort both vectors to compare them regardless of order
//        std::sort(got.begin(), got.end());
//        auto want_sorted = want;
//        std::sort(want_sorted.begin(), want_sorted.end());
//
//        if (got != want_sorted) {
//          throw std::runtime_error("\nfindSquared(" + intVecToStr(arr) + "): got: " +
//                                   intVecVecToStr(got) + ", want: " + intVecVecToStr(want_sorted) + "\n");
//        }
//      }
//    
//    cout << "ALL FIND ALL SQUARES TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.7 - Word Expansion Class
    
//    std::vector<std::pair<std::string, std::vector<std::pair<std::string, bool>>>>
//          tests = {
//              // Example 1
//              {"tea", {{"tea", false}, {"team", true}, {"seam", false}}},
//              // Example 2
//              {"on", {{"nooo", false}, {"not", true}, {"now", true}}},
//              // Additional test cases
//              {"", {{"a", true}, {"", false}, {"ab", false}}},
//              {"xyz",
//               {{"wxyz", true}, {"xyzw", true}, {"xyza", true}, {"xyz", false}}}};
//
//      for (const auto& [s, checks] : tests) {
//        Checker checker(s);
//        for (const auto& [s2, want] : checks) {
//          bool got = checker.expandsInto(s2);
//          if (got != want) {
//            throw std::runtime_error("\nChecker(\"" + s + "\").expandsInto(\"" +
//                                     s2 + "\"): got: " + (got ? "true" : "false") +
//                                     ", want: " + (want ? "true" : "false") + "\n");
//          }
//        }
//      }
//    
//    cout << "ALL WORD EXPANSION CLASS TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.8 - Cheater Detection
    
//    std::vector<std::tuple<std::vector<char>, int, std::vector<Student>,
//                             std::vector<std::vector<int>>>>
//          tests = {
//              // Example
//              {{'a', 'b', 'c', 'c'},
//               5,
//               {Student{4, 10, {'a', 'b', 'c', 'd'}},
//                Student{1, 6, {'a', 'b', 'c', 'd'}},
//                Student{3, 8, {'a', 'b', 'd', 'd'}},
//                Student{5, 11, {'a', 'b', 'c', 'd'}},
//                Student{9, 7, {'a', 'b', 'c', 'd'}},
//                Student{6, 16, {'a', 'b', 'd', 'd'}}},
//                  {{1, 9}, {3, 9}}},
//              // Additional test cases
//              {{'a', 'b'},
//               2,
//               {Student{1, 1, {'a', 'b'}}, Student{2, 2, {'a', 'b'}}},
//               {}},  // Perfect scores are not suspicious
//              {{'a', 'b'},
//               2,
//               {Student{1, 1, {'b', 'b'}}, Student{2, 2, {'b', 'b'}}},
//               {{1, 2}}},
//              {{'a', 'b'},
//               2,
//               {Student{1, 1, {'b', 'b'}}, Student{2, 3, {'b', 'b'}}},
//               {}}  // Different rows
//          };
//
//      for (const auto& [answers, m, students, want] : tests) {
//        auto got = suspectStudents(answers, m, students);
//        if (got != want) {
//          std::string students_str = "[";
//          for (size_t i = 0; i < students.size(); i++) {
//            if (i > 0) students_str += ", ";
//            students_str += "[" + std::to_string(students[i].ID) + ", " +
//                            std::to_string(students[i].desk) + ", [";
//            const auto& student_answers = students[i].answers;
//            for (size_t j = 0; j < student_answers.size(); j++) {
//              if (j > 0) students_str += ", ";
//              students_str += "'" + std::string(1, student_answers[j]) + "'";
//            }
//            students_str += "]]";
//          }
//          students_str += "]";
//
//          throw std::runtime_error("\nsuspect_students(" + students_str + ", " +
//                                   std::to_string(m) +
//                                   "): got: " + std::to_string(got.size()) +
//                                   ", want: " + std::to_string(want.size()) + "\n");
//        }
//      }
//    
//    cout << "ALL CHEATER DETECTION TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.9 - Product of Alphabetical Sums
    
//    std::vector<std::tuple<std::vector<std::string>, int, bool>> tests = {
//          // Example 1
//          {{"abc", "fg", "hij", "klm", "nop", "qrs", "vwx"}, 1620, true},
//          // Example 2
//          {{"a", "b"}, 2, true},
//          // Additional test cases
//          {{}, 1, false},
//          {{"a"}, 1, true},
//          {{"a", "b", "c"}, 6, true},
//          {{"a", "b", "c"}, 7, false}};
//
//      for (const auto& [words, target, want] : tests) {
//        auto got = alphabeticSumProduct(words, target);
//        if (got != want) {
//          std::string words_str = "[";
//          for (size_t i = 0; i < words.size(); i++) {
//            if (i > 0) words_str += ", ";
//            words_str += "\"" + words[i] + "\"";
//          }
//          words_str += "]";
//
//          throw std::runtime_error("\nalphabeticSumProduct(" + words_str + ", " +
//                                   std::to_string(target) +
//                                   "): got: " + (got ? "true" : "false") +
//                                   ", want: " + (want ? "true" : "false") + "\n");
//        }
//      }
//    
//    cout << "ALL PRODUCT OF ALPHABETICAL SUMS TESTS PROVIDED PASSED." << endl;
//
    
    //Problem 30.10 - Action Log Anomalies
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//      std::string str = "[";
//      for (size_t i = 0; i < vec.size(); i++) {
//        if (i > 0) str += ", ";
//        str += std::to_string(vec[i]);
//      }
//      str += "]";
//      return str;
//    };
//
//    std::vector<std::pair<std::vector<Action>, std::vector<int>>> tests = {
//        // Example
//        {{Action("Dwight", "close", 2), Action("Dwight", "open", 2),
//          Action("Drew", "open", 32), Action("Drew", "close", 32),
//          Action("Drew", "open", 32), Action("Drew", "close", 32),
//          Action("Susa", "open", 7), Action("Jo", "close", 7),
//          Action("Susa", "open", 33), Action("Jo", "open", 8),
//          Action("Jo", "open", 36), Action("Jo", "close", 8),
//          Action("Susa", "close", 33)},
//         {2, 32, 7, 8, 36}},
//        // Additional test cases
//        {{}, {}},  // no tickets
//        {{Action("Alice", "open", 1), Action("Alice", "close", 1)},
//         {}},  // Nothing anomalous
//        {{Action("Alice", "open", 1), Action("Alice", "open", 1)},
//         {1}},  // Opened multiple times
//        {{Action("Alice", "open", 1), Action("Alice", "close", 1),
//          Action("Alice", "open", 1)},
//         {1}},                                // Opened after close
//        {{Action("Alice", "open", 1)}, {1}},  // Not closed
//        {{Action("Alice", "open", 1), Action("Susa", "open", 1)},
//         {1}},                                 // Different agent
//        {{Action("Alice", "close", 1)}, {1}},  // Closed before opened
//        {{Action("Drew", "open", 32), Action("Drew", "close", 2),
//          Action("Drew", "close", 32)},
//         {2, 32}},
//        {{Action("Dwight", "close", 2), Action("Dwight", "open", 2),
//          Action("Drew", "open", 32), Action("Drew", "open", 2),
//          Action("Drew", "close", 32)},
//         {2, 32}},  // Multiple agents working on same ticket
//    };
//
//    for (const auto& [log, want] : tests) {
//      auto got = findAnomalies(log);
//      // Sort both vectors to compare them regardless of order
//      std::sort(got.begin(), got.end());
//      auto want_sorted = want;
//      std::sort(want_sorted.begin(), want_sorted.end());
//
//      if (got != want_sorted) {
//        std::string log_str = "[";
//        for (size_t i = 0; i < log.size(); i++) {
//          if (i > 0) log_str += ", ";
//          log_str += "[" + log[i].agent + ", " + log[i].action + ", " +
//                     std::to_string(log[i].ticket) + "]";
//        }
//        log_str += "]";
//
//        throw std::runtime_error("\nfindAnomalies(" + log_str +
//                                 "): got: " + vecToStr(got) +
//                                 ", want: " + vecToStr(want) + "\n");
//      }
//    }
//    
//    cout << "ALL ACTION LOG ANOMALIES TESTS PROVIDED PASSED." << endl;
    
    //Problem 30.11 - Largest Set Intersection
    
//    auto intVecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//      
//      auto intVecVecToStr = [&](const std::vector<std::vector<int>>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += intVecToStr(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
//          // Example 1
//          {{{1, 2, 3}, {3, 2, 1}, {1, 4, 5}, {1, 2}}, 2},
//          // Example 2
//          {{{1, 2}, {3, 4}, {5, 6}}, 0},
//          // Example 3
//          {{{1, 2, 3}, {4, 5}}, 1},
//          // Example 4
//          {{{1, 2, 3}}, 0},
//          // Additional test cases
//          {{{1}, {1}}, 0},
//          {{{1, 2}, {2, 3}, {1, 3}}, 0}};
//
//      for (const auto& [sets, want] : tests) {
//        int gotFreq = largestSetIntersectionFrequencyMap(sets);
//        int gotPrefix = largestSetIntersectionPrefixSum(sets);
//        if (gotFreq != want || gotPrefix != want) {
//          if (gotFreq != want) {
//            throw std::runtime_error("\nlargestSetIntersectionFrequencyMap(" +
//                                     intVecVecToStr(sets) +
//                                     "): got: " + std::to_string(gotFreq) +
//                                     ", want: " + std::to_string(want) + "\n");
//          }
//          if (gotPrefix != want) {
//            throw std::runtime_error("\nlargestSetIntersectionPrefixSum(" +
//                                     intVecVecToStr(sets) +
//                                     "): got: " + std::to_string(gotPrefix) +
//                                     ", want: " + std::to_string(want) + "\n");
//          }
//        }
//      }
//    
//    cout << "ALL LARGEST SET INTERSECTION TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.1 - Sorting by Frequency
    
//    std::vector<std::pair<std::string, std::vector<char>>> tests = {
//          // Example from the book
//          {"supercalifragilisticexpialidocious",
//           {'i', 'a', 'c', 'l', 's', 'e', 'o', 'p', 'r', 'u', 'd', 'f', 'g', 't',
//            'x'}},
//          // Edge case - empty string
//          {"", {}},
//          // Edge case - single character
//          {"a", {'a'}},
//          // Edge case - all same frequency
//          {"abc", {'a', 'b', 'c'}},
//          // Multiple frequencies with ties
//          {"aabbbcccc", {'c', 'b', 'a'}},
//          // All same character
//          {"zzzzz", {'z'}},
//          // Alternating characters
//          {"ababab", {'a', 'b'}},
//          // Reverse alphabetical order but same frequency
//          {"zyxwv", {'v', 'w', 'x', 'y', 'z'}},
//          // Long string with many frequencies
//          {"aaaaabbbbbbbcccccccccdddddddddddeeeeeeeeeeee",
//           {'e', 'd', 'c', 'b', 'a'}},
//      };
//
//      for (const auto& [word, want] : tests) {
//        auto vecToString = [](const std::vector<char>& v) {
//          std::string out = "[";
//          for (size_t i = 0; i < v.size(); i++) {
//            if (i > 0) out += ", ";
//            out += v[i];
//          }
//          out += "]";
//          return out;
//        };
//
//        const auto got1 = letterOccurrences(word);
//        if (got1 != want) {
//          std::string error = "\nletterOccurrences(" + word + "): got: " +
//                              vecToString(got1) + ", want: " +
//                              vecToString(want) + "\n";
//          throw std::runtime_error(error);
//        }
//
//        const auto got2 = letterOccurrencesLambda(word);
//        if (got2 != want) {
//          std::string error = "\nletterOccurrencesLambda(" + word + "): got: " +
//                              vecToString(got2) + ", want: " +
//                              vecToString(want) + "\n";
//          throw std::runtime_error(error);
//        }
//
//      }
//    
//    cout << "ALL SORTING BY FREQUENCY TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.2 - Nested Circles
    
//    std::vector<std::pair<std::vector<Circle>, bool>> tests = {
//          // Example 1 from the book
//          {{{{{4, 4}, 5}, {{8, 4}, 2}}}, false},
//          // Example 2 from the book
//          {{{{{5, 3}, 3}, {{5, 3}, 2}, {{4, 4}, 5}}}, true},
//          // Example 3 from the book
//          {{{{{5, 3}, 3}}}, true},
//          // Edge case - two identical circles
//          {{{{{1, 1}, 2}, {{1, 1}, 2}}}, false},
//          // Edge case - touching circles
//          {{{{{0, 0}, 4}, {{0, 0}, 2}}}, true},
//          // Edge case - empty list
//          {{}, true},
//          // Edge case - negative coordinates
//          {{{{{-5, -3}, 4}, {{-5, -3}, 2}}}, true},
//          // Edge case - negative radius
//          {{{{{0, 0}, -2}}}, true},
//          // Edge case - max coordinate values
//          {{{{{10000, 10000}, 10000}, {{0, 0}, 100}}}, false},
//          // Edge case - min coordinate values
//          {{{{{-10000, -10000}, 10000}, {{0, 0}, 100}}}, false},
//          // Edge case - multiple circles with same center
//          {{{{{1, 1}, 5}, {{1, 1}, 4}, {{1, 1}, 3}, {{1, 1}, 2}}}, true},
//          // Edge case - circles not sorted by radius
//          {{{{{0, 0}, 2}, {{0, 0}, 4}, {{0, 0}, 3}}}, true},
//      };
//
//      for (const auto& [circles, want] : tests) {
//        auto circlesCopy =
//            circles;  // Create a copy since areCirclesNested modifies input
//        bool got = areCirclesNested(circlesCopy);
//        if (got != want) {
//          std::string error = "\nareCirclesNested([";
//          for (size_t i = 0; i < circles.size(); i++) {
//            if (i > 0) error += ", ";
//            error += "((" + std::to_string(circles[i].first.first) + ", " +
//                     std::to_string(circles[i].first.second) + "), " +
//                     std::to_string(circles[i].second) + ")";
//          }
//          error += "]): got: " + std::to_string(got) +
//                   ", want: " + std::to_string(want) + "\n";
//          throw std::runtime_error(error);
//        }
//      }
//    
//    cout << "ALL NESTED CIRCLES TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.3 Delete Operations
    
//    std::vector<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>>
//        tests = {// Example 1 from the book
//                 {{50, 30, 70, 20, 80}, {2, -1, 4, -1}, {50}},
//                 // Example 2 from the book
//                 {{1, 2, 3}, {}, {1, 2, 3}},
//                 // Example 3 from the book
//                 {{1, 2, 3}, {-1, -1, -1}, {}},
//                 // Edge case - delete all indices
//                 {{1, 2, 3}, {0, 1, 2}, {}},
//                 // Edge case - single element
//                 {{1}, {-1}, {}},
//                 // Edge case - duplicates
//                 {{5, 5, 5}, {-1, -1}, {5}},
//                 // Edge case - negative numbers
//                 {{-3, -2, -1}, {-1, -1}, {-1}},
//                 // Mixed operations with duplicates
//                 {{10, 10, 20, 20}, {1, -1, -1}, {20}},
//                 // Operations targeting same index
//                 {{1, 2, 3}, {0, 0, 0}, {2, 3}},
//                 // Alternating index and min operations
//                 {{5, 4, 3, 2, 1}, {2, -1, 0, -1}, {4}},
//                 // Large numbers within constraints
//                 {{1000000000, -1000000000, 0}, {-1, -1}, {1000000000}}};
//
//    for (const auto& [nums, operations, want] : tests) {
//      auto got = processOperations(nums, operations);
//      if (got != want) {
//        std::string error = "\nprocessOperations([";
//        for (size_t i = 0; i < nums.size(); i++) {
//          if (i > 0) error += ", ";
//          error += std::to_string(nums[i]);
//        }
//        error += "], [";
//        for (size_t i = 0; i < operations.size(); i++) {
//          if (i > 0) error += ", ";
//          error += std::to_string(operations[i]);
//        }
//        error += "]): got: [";
//        for (size_t i = 0; i < got.size(); i++) {
//          if (i > 0) error += ", ";
//          error += std::to_string(got[i]);
//        }
//        error += "], want: [";
//        for (size_t i = 0; i < want.size(); i++) {
//          if (i > 0) error += ", ";
//          error += std::to_string(want[i]);
//        }
//        error += "]\n";
//        throw std::runtime_error(error);
//      }
//    }
//    
//    cout << "ALL DELETE OPERATIONS TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.4 - Spreadsheet
//    
//    {
//      Spreadsheet s(0, 0);
//      s.newSheet(3, 3);
//      s.set(0, 0, 5);
//      s.set(0, 1, 3);
//      s.set(0, 2, 8);
//      s.set(1, 0, 6);
//      s.set(2, 1, 1);
//      s.sortColumnsByRow(0);
//      s.sortRowsByColumn(1);
//      std::vector<std::vector<int>> want = {
//          {1, 0, 0},
//          {3, 5, 8},
//          {0, 6, 0},
//      };
//      for (int r = 0; r < want.size(); r++) {
//        for (int c = 0; c < want[0].size(); c++) {
//          int got = s.get(r, c);
//          int expect = want[r][c];
//          if (got != expect) {
//            throw std::runtime_error("\nget(" + std::to_string(r) + ", " +
//                                     std::to_string(c) + "): got: " +
//                                     std::to_string(got) + ", want: " +
//                                     std::to_string(expect) + "\n");
//          }
//        }
//      }
//    }
//
//    // Edge case - 1x1 spreadsheet
//    {
//      Spreadsheet s(0, 0);
//      s.newSheet(1, 1);
//      s.set(0, 0, 42);
//      std::vector<std::vector<int>> want = {
//          {42},
//      };
//      for (int r = 0; r < want.size(); r++) {
//        for (int c = 0; c < want[0].size(); c++) {
//          int got = s.get(r, c);
//          int expect = want[r][c];
//          if (got != expect) {
//            throw std::runtime_error("\nget(" + std::to_string(r) + ", " +
//                                     std::to_string(c) + "): got: " +
//                                     std::to_string(got) + ", want: " +
//                                     std::to_string(expect) + "\n");
//          }
//        }
//      }
//    }
//
//    // Edge case - sort empty rows
//    {
//      Spreadsheet s(0, 0);
//      s.newSheet(3, 2);
//      s.sortRowsByColumn(0);
//      std::vector<std::vector<int>> want = {
//          {0, 0},
//          {0, 0},
//          {0, 0},
//      };
//      for (int r = 0; r < want.size(); r++) {
//        for (int c = 0; c < want[0].size(); c++) {
//          int got = s.get(r, c);
//          int expect = want[r][c];
//          if (got != expect) {
//            throw std::runtime_error("\nget(" + std::to_string(r) + ", " +
//                                     std::to_string(c) + "): got: " +
//                                     std::to_string(got) + ", want: " +
//                                     std::to_string(expect) + "\n");
//          }
//        }
//      }
//    }
//    
//    cout << "ALL SPREADSHEET TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.5 - Sort by Publication Year
    
//    std::vector<std::pair<std::vector<Book>, std::vector<int>>> tests = {
//        // Example from the book
//        {
//          {
//            Book("Shadow of Tomorrow", "Elliot Greyson", 350, "Science Fiction", 2020),
//            Book("Whispers in the Wind", "Lila Hart", 280, "Romance", 2018),
//            Book("Echoes of Eternity", "Mara Vance", 420, "Fantasy", 2018),
//            Book("Fragments of Dawn", "Cora Blake", 310, "Mystery", 2019),
//            Book("Beneath the Starlit Sky", "Aria Monroe", 270, "Drama", 2020)
//          },
//          {2018, 2018, 2019, 2020, 2020}
//        },
//        // Edge case - empty list
//        {{}, {}},
//        // Edge case - single book
//        {{Book("Solo", "Author", 100, "Genre", 2000)}, {2000}},
//        // Multiple books with the same year
//        {
//          {
//            Book("A", "Author1", 100, "Genre", 2000),
//            Book("B", "Author2", 200, "Genre", 2000)
//          },
//          {2000, 2000}
//        },
//        // Reverse sorted years
//        {
//          {
//            Book("A", "Author1", 100, "Genre", 2020),
//            Book("B", "Author2", 200, "Genre", 2019),
//            Book("C", "Author3", 300, "Genre", 2018)
//          },
//          {2018, 2019, 2020}
//        },
//        // Large gap between years
//        {
//          {
//            Book("A", "Author1", 100, "Genre", 1000),
//            Book("B", "Author2", 200, "Genre", 2025)
//          },
//          {1000, 2025}
//        },
//        // Many books same year
//        {
//          std::vector<Book>{10, Book("Book0", "Author0", 100, "Genre", 2000)},
//          std::vector<int>(10, 2000)
//        }
//      };
//
//      for ( auto& [books, wantYears] : tests) {
//        auto got = bucketSort(books);
//        std::vector<int> gotYears;
//        for (const auto& book : got) {
//          gotYears.push_back(book.yearPublished);
//        }
//        if (gotYears != wantYears) {
//          std::string error = "\nbucketSort([";
//          for (size_t i = 0; i < books.size(); i++) {
//            if (i > 0) error += ", ";
//            error += books[i].title;
//          }
//          error += "]): got years: [";
//          for (size_t i = 0; i < gotYears.size(); i++) {
//            if (i > 0) error += ", ";
//            error += std::to_string(gotYears[i]);
//          }
//          error += "], want years: [";
//          for (size_t i = 0; i < wantYears.size(); i++) {
//            if (i > 0) error += ", ";
//            error += std::to_string(wantYears[i]);
//          }
//          error += "]\n";
//          throw std::runtime_error(error);
//        }
//
//        // Verify that all books are preserved
//        if (got.size() != books.size()) {
//          throw std::runtime_error("\nbucketSort: got length " +
//                                 std::to_string(got.size()) +
//                                 ", want length " +
//                                 std::to_string(books.size()) + "\n");
//        }
//
//        std::unordered_set<std::string> gotTitles, wantTitles;
//        for (const auto& book : got) gotTitles.insert(book.title);
//        for (const auto& book : books) wantTitles.insert(book.title);
//        if (gotTitles != wantTitles) {
//          throw std::runtime_error("\nbucketSort: some books were lost or duplicated\n");
//        }
//      }
//    
//    cout << "ALL SORT BY PUBLICATION YEAR TESTS PROVIDED PASSED." << endl;
    
    //Problem 31.6 - First K
    
//    std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> tests = {
//          // Example from the book
//          std::make_tuple(
//              std::vector<int>{15, 4, 13, 8, 10, 5, 2, 20, 3, 9, 11, 27}, 5,
//              std::vector<int>{2, 3, 4, 5, 8}),
//          // Edge case - k = 1
//          std::make_tuple(std::vector<int>{5, 2, 1, 3, 4}, 1, std::vector<int>{1}),
//          // Edge case - k = length of array
//          std::make_tuple(std::vector<int>{3, 1, 2}, 3, std::vector<int>{1, 2, 3}),
//          // Edge case - array of length 1
//          std::make_tuple(std::vector<int>{42}, 1, std::vector<int>{42}),
//          // Reverse sorted array
//          std::make_tuple(std::vector<int>{5, 4, 3, 2, 1}, 4,
//                          std::vector<int>{1, 2, 3, 4}),
//          // Already sorted array
//          std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 3,
//                          std::vector<int>{1, 2, 3}),
//          // Edge case - empty array
//          std::make_tuple(std::vector<int>{}, 0, std::vector<int>{}),
//          // Array with negative numbers
//          std::make_tuple(std::vector<int>{-3, -1, -4, -2}, 3,
//                          std::vector<int>{-4, -3, -2}),
//          // Mix of positive and negative
//          std::make_tuple(std::vector<int>{-5, 3, -2, 8, -1}, 4,
//                          std::vector<int>{-5, -2, -1, 3}),
//          // Large numbers
//          std::make_tuple(std::vector<int>{1000000000, -1000000000, 0}, 2,
//                          std::vector<int>{-1000000000, 0})};
//
//      std::vector<std::pair<std::string,
//                            std::function<std::vector<int>(std::vector<int>, int)>>>
//          solutions = {{"firstKSorting", firstKSorting},
//                       {"firstKMaxHeap", firstKMaxHeap},
//                       {"firstKMinHeap", firstKMinHeap},
//                       {"firstKQuickselect", firstKQuickselect}};
//
//      auto vecToStr = [](const std::vector<int>& vec) {
//        std::string str = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) str += ", ";
//          str += std::to_string(vec[i]);
//        }
//        str += "]";
//        return str;
//      };
//
//      for (const auto& [name, solution] : solutions) {
//        for (const auto& [arr, k, want] : tests) {
//          auto got = solution(arr, k);
//          std::sort(got.begin(), got.end());
//          std::vector<int> wantSorted = want;
//          std::sort(wantSorted.begin(), wantSorted.end());
//
//          if (got != wantSorted) {
//            std::string arr_str = vecToStr(arr);
//            std::string got_str = vecToStr(got);
//            std::string want_str = vecToStr(want);
//            throw std::runtime_error("\n" + name + "(" + arr_str + ", " +
//                                     std::to_string(k) + "): got: " + got_str +
//                                     ", want: " + want_str + " (in any order)\n");
//          }
//        }
//      }
//    
//    cout << "ALL FIRST K TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.1 - Compress Array
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
//          {{8, 4, 2, 2, 2, 4}, {16, 2, 4}},
//          {{4, 4, 4, 4}, {16}},
//          {{1, 2, 3, 4}, {1, 2, 3, 4}},
//          {{}, {}},
//          {{0, 0, 0, 0}, {0}}};
//
//      for (const auto& [arr, want] : tests) {
//        std::vector<int> got = compressArray(arr);
//        if (got != want) {
//          throw std::runtime_error("\ncompressArray(" + vecToStr(arr) + "): got: " +
//                                   vecToStr(got) + ", want: " + vecToStr(want) + "\n");
//        }
//      }
//    
//    cout << "ALL COMPRESS ARRAY TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.2 - Compress Array by K
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> tests = {
//          std::make_tuple(std::vector<int>{1, 9, 9, 3, 3, 3, 4}, 3,
//                          std::vector<int>{1, 27, 4}),
//          std::make_tuple(std::vector<int>{8, 4, 2, 2}, 2, std::vector<int>{16}),
//          std::make_tuple(std::vector<int>{4, 4, 4, 4}, 5,
//                          std::vector<int>{4, 4, 4, 4}),
//          std::make_tuple(std::vector<int>{}, 2, std::vector<int>{}),
//          std::make_tuple(std::vector<int>{0, 0, 0, 0}, 2, std::vector<int>{0})};
//
//      CompressArrayK solution;
//      for (const auto& [arr, k, want] : tests) {
//        std::vector<int> got = solution.solve(arr, k);
//        if (got != want) {
//          throw std::runtime_error("\nsolve(" + vecToStr(arr) + ", " + std::to_string(k) +
//                                   "): got: " + vecToStr(got) + ", want: " + vecToStr(want) +
//                                   "\n");
//        }
//      }
//    
//    cout << "ALL COMPRESS ARRAY BY K TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.4 - Current URL
    
//    std::vector<
//          std::pair<std::vector<std::pair<std::string, std::string>>, std::string>>
//          tests = {{{{"go", "google.com"},
//                     {"go", "wikipedia.com"},
//                     {"go", "amazon.com"},
//                     {"back", "4"},
//                     {"go", "youtube.com"},
//                     {"go", "netflix.com"},
//                     {"back", "1"}},
//                    "youtube.com"},
//                   {{{"go", "example.com"}, {"back", "1"}}, "example.com"},
//                   {{{"go", "site1.com"},
//                     {"go", "site2.com"},
//                     {"back", "1"},
//                     {"back", "1"}},
//                    "site1.com"}};
//
//      for (const auto& [actions, want] : tests) {
//        std::string got = currentUrl(actions);
//        if (got != want) {
//          std::string actions_str = "[";
//          for (size_t i = 0; i < actions.size(); i++) {
//            if (i > 0) actions_str += ", ";
//            actions_str +=
//                "[\"" + actions[i].first + "\", \"" + actions[i].second + "\"]";
//          }
//          actions_str += "]";
//
//          throw std::runtime_error("\ncurrentUrl(" + actions_str +
//                                   "): got: " + got + ", want: " + want + "\n");
//        }
//      }
//    
//    cout << "ALL CURRENT URL TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.5 - Current URL with Forward
    
//    auto actionsToString =
//        [](const std::vector<std::pair<std::string, std::string>>& actions) {
//          std::string actions_str = "[";
//          for (size_t i = 0; i < actions.size(); i++) {
//            if (i > 0) actions_str += ", ";
//            actions_str +=
//                "[\"" + actions[i].first + "\", \"" + actions[i].second + "\"]";
//          }
//          actions_str += "]";
//          return actions_str;
//        };
//
//    std::vector<
//        std::pair<std::vector<std::pair<std::string, std::string>>, std::string>>
//        tests = {{{{"go", "google.com"},
//                   {"go", "wikipedia.com"},
//                   {"back", "1"},
//                   {"forward", "1"},
//                   {"back", "3"},
//                   {"go", "netflix.com"},
//                   {"forward", "3"}},
//                  "netflix.com"},
//                 {{{"go", "example.com"}, {"forward", "1"}}, "example.com"},
//                 {{{"go", "site1.com"},
//                   {"go", "site2.com"},
//                   {"back", "1"},
//                   {"forward", "1"},
//                   {"back", "1"}},
//                  "site1.com"}};
//
//    for (const auto& [actions, want] : tests) {
//      std::string got = currentUrlWithForward(actions);
//      if (got != want) {
//        throw std::runtime_error("\ncurrentUrlWithForward(" +
//                                 actionsToString(actions) + "): got: " + got +
//                                 ", want: " + want + "\n");
//      }
//    }
//    
//    cout << "ALL CURRENT URL WITH FORWARD TESTS PROVIDED PASSED." << endl;
    
    //Problem  32.6 - Balanced Partition
//    
//    std::vector<std::pair<std::string, int>> tests = {
//        {"((()))(()())()(()(()))", 4},
//        {"()()()", 3},
//        {"(((())))", 1},
//        {"", 0},
//        {"()", 1}};
//
//    for (const auto& [s, want] : tests) {
//      int got = maxBalancedPartition(s);
//      if (got != want) {
//        throw std::runtime_error("\nmaxBalancedPartition(" + s +
//                                 "): got: " + std::to_string(got) +
//                                 ", want: " + std::to_string(want) + "\n");
//      }
//    }
//    
//    cout << "ALL BALANCED PARTITION TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.7 - Custom Brackets
    
//    std::vector<std::tuple<std::string, std::vector<std::string>, bool>> tests = {
//        // Example 1 from book
//        {"((a+b)*[c-d]-{e/f})", {"()", "[]", "{}"}, true},
//        // Example 2 from book
//        {"(){[}", {"()", "[]", "{}"}, false},
//        // Example 3 from book
//        {"([)]", {"()", "[]", "{}"}, false},
//        // Example 4 from book
//        {"<div> hello :) </div>", {"<>", "()"}, false},
//        // Example 5 from book
//        {")))(()((", {")("}, true},
//        // Empty string
//        {"", {"()"}, true},
//        // Single character
//        {"(", {"()"}, false},
//        // Multiple bracket types
//        {"<<>>()[]{}", {"<>", "()", "[]", "{}"}, true},
//        // Nested brackets
//        {"[{()}]", {"()", "[]", "{}"}, true},
//        // Unmatched opening bracket
//        {"(()", {"()"}, false},
//        // Unmatched closing bracket
//        {"())", {"()"}, false},
//        // Wrong order of closing
//        {"({)}", {"()", "{}"}, false},
//        // Non-bracket characters mixed in
//        {"a(b)c[d]e", {"()", "[]"}, true},
//        // Multiple identical bracket pairs
//        {"<<>>", {"<>"}, true}};
//
//    for (const auto& [s, brackets, want] : tests) {
//      bool got = customBrackets(s, brackets);
//      if (got != want) {
//        std::string brackets_str = "[";
//        for (size_t i = 0; i < brackets.size(); i++) {
//          if (i > 0) brackets_str += ", ";
//          brackets_str += "\"" + brackets[i] + "\"";
//        }
//        brackets_str += "]";
//
//        throw std::runtime_error("\ncustomBrackets(\"" + s + "\", " +
//                                 brackets_str +
//                                 "): got: " + (got ? "true" : "false") +
//                                 ", want: " + (want ? "true" : "false") + "\n");
//      }
//    }
//    
//    cout << "ALL CUSTOM BRACKETS TESTS PROVIDED PASSED." << endl;
    
    //Problem 32.8 - Longest Balanced Subsequence
    
//    std::vector<std::pair<std::string, std::vector<std::string>>> tests = {
//          {"))(())(()", {"(())()"}},
//          {"(()()", {"()()", "(())"}},
//          {"(()(()(", {"()()", "(())"}},
//          {"())(()", {"()()"}},
//          {"(", {""}},
//          {"", {""}}};
//
//      for (const auto& [s, want] : tests) {
//        std::string got = longestBalancedSubsequence(s);
//        bool found = false;
//        for (const auto& w : want) {
//          if (got == w) {
//            found = true;
//            break;
//          }
//        }
//        if (!found) {
//          std::string want_str;
//          for (size_t i = 0; i < want.size(); i++) {
//            if (i > 0) want_str += " or ";
//            want_str += want[i];
//          }
//          throw std::runtime_error("\nlongestBalancedSubsequence(" + s +
//                                   "): got: " + got + ", want: " + want_str + "\n");
//        }
//      }
//    
//    cout << "ALL LONGEST BALANCED SUBSEQUENCE TESTS PROVIDED PASSED." << endl;
    
    //Problem 33.1 - Robot Instructions
    
//    std::vector<std::pair<std::string, std::string>> tests = {
//        // Example 1 from book
//        {"LL", "LL"},
//        // Example 2 from book
//        {"2LR", "LRR"},
//        // Example 3 from book
//        {"2L", "L"},
//        // Example 4 from book
//        {"22LR", "LRRLR"},
//        // Example 5 from book
//        {"LL2R2L", "LLRLL"},
//        // Edge case - empty string
//        {"", ""},
//        // Edge case - single character
//        {"L", "L"},
//        // Multiple 2s in a row
//        {"2222LR", "LRRLRLRRLRRLR"},
//      };
//
//      for (const auto& [seq, want] : tests) {
//        std::string got = moves(seq);
//        if (got != want) {
//          throw std::runtime_error("\nmoves(" + seq +
//                                 "): got: " + got +
//                                 ", want: " + want + "\n");
//        }
//      }
//    
//    cout << "ALL ROBOT INSTRUCTIONS TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 33.2 - Nested Sum Array
    
//    auto vecToStr = [](const std::vector<int>& vec) {
//        std::string str = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) str += ", ";
//          str += std::to_string(vec[i]);
//        }
//        str += "]";
//        return str;
//      };
//
//      std::vector<std::pair<std::vector<int>, int>> tests = {
//          // Example 1 from book
//          {{3, -9, 2, 4, -1, 5, 5, -4}, 6},
//          // Example 2 from book
//          {{1}, 1},
//          // Example 3 from book
//          {{-1, -2}, -1},
//          // Additional test case
//          {{1, 2, 3, 4}, 10},
//          // Additional test case with all negatives
//          {{-2, -1, -4, -3}, -1},
//          // Large test case
//          {{1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}, 15},
//      };
//
//      for (const auto& [arr, want] : tests) {
//        int got = maxLaminalSum(arr);
//        if (got != want) {
//          throw std::runtime_error("\nsolve(" + vecToStr(arr) +
//                                   "): got: " + std::to_string(got) +
//                                   ", want: " + std::to_string(want) + "\n");
//        }
//      }
//    
//    cout << "ALL NESTED SUM ARRAY TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.1 - Singly Linked List Design
    
//    SinglyLinkedList list;
//
//      // Test empty list
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//
//      if (list.popFront()) {
//        throw std::runtime_error("\npop_front(): got value, want: nullopt\n");
//      }
//
//      if (list.popBack()) {
//        throw std::runtime_error("\npop_back(): got value, want: nullopt\n");
//      }
//
//      // Test push_front
//      list.pushFront(10);
//      if (list.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 1\n");
//      }
//      if (!list.contains(10)) {
//        throw std::runtime_error("\ncontains(10): got: false, want: true\n");
//      }
//
//      // Test push_back
//      list.pushBack(20);
//      if (list.size() != 2) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 2\n");
//      }
//      if (!list.contains(20)) {
//        throw std::runtime_error("\ncontains(20): got: false, want: true\n");
//      }
//
//      // Test pop_front
//      auto val = list.popFront();
//      if (!val || *val != 10) {
//        throw std::runtime_error(
//            "\npop_front(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 10\n");
//      }
//      if (list.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 1\n");
//      }
//      if (list.contains(10)) {
//        throw std::runtime_error("\ncontains(10): got: true, want: false\n");
//      }
//
//      // Test pop_back
//      val = list.popBack();
//      if (!val || *val != 20) {
//        throw std::runtime_error(
//            "\npop_back(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 20\n");
//      }
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//      if (list.contains(20)) {
//        throw std::runtime_error("\ncontains(20): got: true, want: false\n");
//      }
//
//      // Test multiple operations
//      list.pushBack(30);
//      list.pushFront(40);
//      if (list.size() != 2) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 2\n");
//      }
//
//      val = list.popFront();
//      if (!val || *val != 40) {
//        throw std::runtime_error(
//            "\npop_front(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 40\n");
//      }
//
//      val = list.popBack();
//      if (!val || *val != 30) {
//        throw std::runtime_error(
//            "\npop_back(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 30\n");
//      }
//
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//    
//    cout << "ALL SINGLY LINKED LIST DESIGN TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.2 - Doubly Linked List Design
    
//    DoublyLinkedList list;
//
//      // Test empty list
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//
//      if (list.popFront()) {
//        throw std::runtime_error("\npop_front(): got value, want: nullopt\n");
//      }
//
//      if (list.popBack()) {
//        throw std::runtime_error("\npop_back(): got value, want: nullopt\n");
//      }
//
//      // Test push_front
//      list.pushFront(10);
//      if (list.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 1\n");
//      }
//      if (!list.contains(10)) {
//        throw std::runtime_error("\ncontains(10): got: false, want: true\n");
//      }
//
//      // Test push_back
//      list.pushBack(20);
//      if (list.size() != 2) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 2\n");
//      }
//      if (!list.contains(20)) {
//        throw std::runtime_error("\ncontains(20): got: false, want: true\n");
//      }
//
//      // Test pop_front
//      auto val = list.popFront();
//      if (!val || *val != 10) {
//        throw std::runtime_error(
//            "\npop_front(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 10\n");
//      }
//      if (list.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 1\n");
//      }
//      if (list.contains(10)) {
//        throw std::runtime_error("\ncontains(10): got: true, want: false\n");
//      }
//
//      // Test pop_back
//      val = list.popBack();
//      if (!val || *val != 20) {
//        throw std::runtime_error(
//            "\npop_back(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 20\n");
//      }
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//      if (list.contains(20)) {
//        throw std::runtime_error("\ncontains(20): got: true, want: false\n");
//      }
//
//      // Test multiple operations
//      list.pushBack(30);
//      list.pushFront(40);
//      if (list.size() != 2) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 2\n");
//      }
//
//      val = list.popFront();
//      if (!val || *val != 40) {
//        throw std::runtime_error(
//            "\npop_front(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 40\n");
//      }
//
//      val = list.popBack();
//      if (!val || *val != 30) {
//        throw std::runtime_error(
//            "\npop_back(): got: " + (val ? std::to_string(*val) : "nullopt") +
//            ", want: 30\n");
//      }
//
//      if (list.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(list.size()) +
//                                 ", want: 0\n");
//      }
//    
//    cout << "ALL DOUBLY LINKED LIST DESIGN TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.3 - Linked-List-Based Stack
//    
//    LinkedListStack stack;
//
//      // Test size on empty stack
//      if (stack.size() != 0) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(stack.size()) +
//                                 ", want: 0\n");
//      }
//
//      // Test pop on empty stack
//      if (stack.pop() != std::nullopt) {
//        throw std::runtime_error("\npop() on empty stack should return null\n");
//      }
//
//      // Test peek on empty stack
//      if (stack.peek() != std::nullopt) {
//        throw std::runtime_error("\npeek() on empty stack should return null\n");
//      }
//
//      // Test push and size
//      stack.push(10);
//      if (stack.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(stack.size()) +
//                                 ", want: 1\n");
//      }
//
//      // Test peek
//      if (stack.peek() != 10) {
//        throw std::runtime_error("\npeek() should return 10\n");
//      }
//
//      // Test push and pop
//      stack.push(20);
//      if (stack.pop() != 20) {
//        throw std::runtime_error("\npop() should return 20\n");
//      }
//      if (stack.size() != 1) {
//        throw std::runtime_error("\nsize(): got: " + std::to_string(stack.size()) +
//                                 ", want: 1\n");
//      }
//
//      // Test empty
//      if (stack.empty()) {
//        throw std::runtime_error("\nempty() should return false\n");
//      }
//      stack.pop();
//      if (!stack.empty()) {
//        throw std::runtime_error("\nempty() should return true\n");
//      }
//
//    cout << "ALL LINKED-LIST-BASED STACK TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.4 - Linked-List-Based Queue
    
//    LinkedListQueue queue;
//
//     // Test size on empty queue
//     if (queue.size() != 0) {
//       throw std::runtime_error("\nsize(): got: " + std::to_string(queue.size()) +
//                                ", want: 0\n");
//     }
//
//     // Test pop on empty queue
//     if (queue.pop() != std::nullopt) {
//       throw std::runtime_error("\npop() on empty queue should return null\n");
//     }
//
//     // Test push and size
//     queue.push(10);
//     if (queue.size() != 1) {
//       throw std::runtime_error("\nsize(): got: " + std::to_string(queue.size()) +
//                                ", want: 1\n");
//     }
//
//     // Test push and pop
//     queue.push(20);
//     if (queue.pop() != 10) {
//       throw std::runtime_error("\npop() should return 10\n");
//     }
//     if (queue.size() != 1) {
//       throw std::runtime_error("\nsize(): got: " + std::to_string(queue.size()) +
//                                ", want: 1\n");
//     }
//
//     // Test empty
//     if (queue.empty()) {
//       throw std::runtime_error("\nempty() should return false\n");
//     }
//     queue.pop();
//     if (!queue.empty()) {
//       throw std::runtime_error("\nempty() should return true\n");
//     }
//    
//    cout << "ALL LINKED-LIST-BASED QUEUE TESTS PROVIDED PASSED." << endl;
    
    //Problem 34.5 - Linked-List Copy
    
//    auto vecToLinkedList = [](const std::vector<int>& arr) -> Node* {
//        if (arr.empty()) return nullptr;
//        Node* head = new Node(arr[0]);
//        Node* cur = head;
//        for (size_t i = 1; i < arr.size(); i++) {
//          cur->next = new Node(arr[i]);
//          cur = cur->next;
//        }
//        return head;
//      };
//
//      auto linkedListToVec = [](Node* head) -> std::vector<int> {
//        std::vector<int> result;
//        Node* cur = head;
//        while (cur) {
//          result.push_back(cur->val);
//          cur = cur->next;
//        }
//        return result;
//      };
//
//      auto cleanupList = [](Node* head) -> void {
//        while (head) {
//          Node* temp = head;
//          head = head->next;
//          delete temp;
//        }
//      };
//
//      auto vecToStr = [](const std::vector<int>& vec) -> std::string {
//        std::string result = "[";
//        for (size_t i = 0; i < vec.size(); i++) {
//          if (i > 0) result += ", ";
//          result += std::to_string(vec[i]);
//        }
//        result += "]";
//        return result;
//      };
//
//      std::vector<std::vector<int>> tests = {
//          // Test empty list
//          {},
//          // Test single element list
//          {1},
//          // Test multiple elements list
//          {1, 2, 3},
//          // Test list with repeated values
//          {1, 1, 1},
//          // Test list with negative values
//          {-1, -2, -3},
//          // Test list with zero
//          {0},
//          // Test longer list
//          {1, 2, 3, 4, 5},
//          // Test list with mixed values
//          {-1, 0, 1},
//      };
//
//      for (size_t i = 0; i < tests.size(); i++) {
//        const auto& arr = tests[i];
//        Node* head = vecToLinkedList(arr);
//
//        // Test first copyList function
//        Node* copiedHead1 = copyList(head);
//        std::vector<int> got1 = linkedListToVec(copiedHead1);
//
//        if (got1 != arr) {
//          std::string error_msg = "\nTest " + std::to_string(i + 1) +
//                                  " (copyList 1): got: " + vecToStr(got1) +
//                                  ", want: " + vecToStr(arr) + "\n";
//          cleanupList(head);
//          cleanupList(copiedHead1);
//          throw std::runtime_error(error_msg);
//        }
//
//        // Test second copyList function
////        Node* copiedHead2 = copyListWithDummy(head);
////        std::vector<int> got2 = linkedListToVec(copiedHead2);
////
////        if (got2 != arr) {
////          std::string error_msg = "\nTest " + std::to_string(i + 1) +
////                                  " (copyList 2): got: " + vecToStr(got2) +
////                                  ", want: " + vecToStr(arr) + "\n";
////          cleanupList(head);
////          cleanupList(copiedHead1);
////          cleanupList(copiedHead2);
////          throw std::runtime_error(error_msg);
////        }
////
////        // Clean up memory
////        cleanupList(head);
////        cleanupList(copiedHead1);
////        cleanupList(copiedHead2);
//      }
//    
//    cout << "ALL LINKED-LIST COPY TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.6 - Linked-List Reversal
    
//    auto vecToLinkedList = [](const std::vector<int>& arr) -> Node* {
//      if (arr.empty()) return nullptr;
//      Node* head = new Node(arr[0]);
//      Node* cur = head;
//      for (size_t i = 1; i < arr.size(); i++) {
//        cur->next = new Node(arr[i]);
//        cur = cur->next;
//      }
//      return head;
//    };
//
//    auto linkedListToVec = [](Node* head) -> std::vector<int> {
//      std::vector<int> result;
//      Node* cur = head;
//      while (cur) {
//        result.push_back(cur->val);
//        cur = cur->next;
//      }
//      return result;
//    };
//
//    auto vecToStr = [](const std::vector<int>& vec) -> std::string {
//      std::string result = "[";
//      for (size_t i = 0; i < vec.size(); i++) {
//        if (i > 0) result += ", ";
//        result += std::to_string(vec[i]);
//      }
//      result += "]";
//      return result;
//    };
//
//    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
//        // Test empty list
//        {{}, {}},
//        // Test single element list
//        {{1}, {1}},
//        // Test multiple elements list
//        {{1, 2, 3}, {3, 2, 1}},
//        // Test list with repeated values
//        {{1, 1, 1}, {1, 1, 1}},
//        // Test list with negative values
//        {{-1, -2, -3}, {-3, -2, -1}},
//        // Test list with zero
//        {{0}, {0}},
//        // Test longer list
//        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
//        // Test list with mixed values
//        {{-1, 0, 1}, {1, 0, -1}},
//    };
//
//    for (size_t i = 0; i < tests.size(); i++) {
//      auto [input, want] = tests[i];
//      Node* head = vecToLinkedList(input);
//      Node* reversedHead = reverseList(head);
//      std::vector<int> got = linkedListToVec(reversedHead);
//
//      if (got != want) {
//        std::string error_msg = "\nTest " + std::to_string(i + 1) +
//                                ": got: " + vecToStr(got) +
//                                ", want: " + vecToStr(want) + "\n";
//
//        while (reversedHead) {
//          Node* temp = reversedHead;
//          reversedHead = reversedHead->next;
//          delete temp;
//        }
//        throw std::runtime_error(error_msg);
//      }
//
//      while (reversedHead) {
//        Node* temp = reversedHead;
//        reversedHead = reversedHead->next;
//        delete temp;
//      }
//    }
//    
//    cout << "ALL LINKED-LIST REVERSAL TESTS PROVIDED HAVE PASSED." << endl;
    
    //Problem 34.7 - Sublist Reversal
    
    auto vecToLinkedList = [](const std::vector<int>& arr) -> Node* {
        if (arr.empty()) return nullptr;
        Node* head = new Node(arr[0]);
        Node* cur = head;
        for (size_t i = 1; i < arr.size(); i++) {
          cur->next = new Node(arr[i]);
          cur = cur->next;
        }
        return head;
      };

      auto linkedListToVec = [](Node* head) -> std::vector<int> {
        std::vector<int> result;
        Node* cur = head;
        while (cur) {
          result.push_back(cur->val);
          cur = cur->next;
        }
        return result;
      };

      auto vecToStr = [](const std::vector<int>& vec) -> std::string {
        std::string result = "[";
        for (size_t i = 0; i < vec.size(); i++) {
          if (i > 0) result += ", ";
          result += std::to_string(vec[i]);
        }
        result += "]";
        return result;
      };

      std::vector<std::tuple<std::vector<int>, int, int, std::vector<int>>> tests =
          {
              // From book
              {{1, 2, 3, 4, 5}, 1, 3, {1, 4, 3, 2, 5}},
              {{1, 2, 3, 4, 5}, 2, 7, {1, 2, 5, 4, 3}},
              {{1, 2}, 5, 6, {1, 2}},

              // Test empty list
              {{}, 0, 1, {}},
              // Test single element list
              {{1}, 0, 1, {1}},
              // Test reversing entire list
              {{1, 2, 3}, 0, 3, {3, 2, 1}},
              // Test reversing sublist with repeated values
              {{1, 1, 1, 2, 2}, 1, 3, {1, 2, 1, 1, 2}},
              // Test reversing sublist with negative values
              {{-1, -2, -3, -4}, 1, 3, {-1, -4, -3, -2}},
              // Test reversing sublist with zero
              {{0, 1, 2}, 0, 1, {1, 0, 2}},
              // Test reversing sublist at the end
              {{1, 2, 3, 4, 5}, 2, 4, {1, 2, 5, 4, 3}},
              // Test left beyond list length - should not modify
              {{1, 2, 3}, 4, 5, {1, 2, 3}},
              // Test right beyond list length - reverse to end
              {{1, 2, 3}, 1, 5, {1, 3, 2}},
          };

      for (size_t i = 0; i < tests.size(); i++) {
        auto [input, left, right, want] = tests[i];
        Node* head = vecToLinkedList(input);
        Node* reversedHead = reverseSection(head, left, right);
        std::vector<int> got = linkedListToVec(reversedHead);

        if (got != want) {
          std::string error_msg = "\nTest " + std::to_string(i + 1) +
                                  ": got: " + vecToStr(got) +
                                  ", want: " + vecToStr(want) + "\n";

          // Clean up memory before throwing
          while (reversedHead) {
            Node* temp = reversedHead;
            reversedHead = reversedHead->next;
            delete temp;
          }

          throw std::runtime_error(error_msg);
        }

        // Clean up memory
        while (reversedHead) {
          Node* temp = reversedHead;
          reversedHead = reversedHead->next;
          delete temp;
        }
      }
    
    cout << "ALL SUBLIST REVERSAL TESTS PROVIDED HAVE PASSED." << endl;
    
    return EXIT_SUCCESS;
}

