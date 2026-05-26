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
    
    std::vector<std::tuple<std::vector<int>, int>> tests = {
          // Example 1 from book
          {{6, 5, 4, 7, 9}, 4},
          // Example 2 from book
          {{5, 6, 7}, 5},
          // Example 3 from book
          {{7, 6, 5}, 5},
          // Edge case - 2 elements
          {{2, 1}, 1},
          // Edge case - 3 elements
          {{3, 2, 4}, 2}};

      for (const auto& [arr, want] : tests) {
        int got = valleyBottom(arr);
        if (got != want) {
          std::string arr_str = "[";
          for (size_t i = 0; i < arr.size(); i++) {
            if (i > 0) arr_str += ", ";
            arr_str += std::to_string(arr[i]);
          }
          arr_str += "]";

          throw std::runtime_error("\nvalleyBottom(" + arr_str +
                                   "): got: " + std::to_string(got) +
                                   ", want: " + std::to_string(want) + "\n");
        }
      }
    
    cout << "ALL VALLEY BOTTOM TESTS PROVIDED PASSED." << endl;
    
    return EXIT_SUCCESS;
}

