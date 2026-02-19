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
    
    auto charVecToStr = [](const std::vector<char>& vec) {
        std::string result = "[";
        for (size_t i = 0; i < vec.size(); i++) {
          if (i > 0) result += ", ";
          result += vec[i];
        }
        result += "]";
        return result;
      };

      std::vector<std::pair<std::vector<char>, std::vector<char>>> tests = {
          // Test cases
          {{'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}},
          {{}, {}},
          {{'a'}, {'a'}},
          {{'a', 'b'}, {'b', 'a'}},
          {{'a', 'b', 'c'}, {'c', 'b', 'a'}},
          {{'a', 'b', 'c', 'd'}, {'d', 'c', 'b', 'a'}},
      };

      for (const auto& [arr_orig, want] : tests) {
        auto arr = arr_orig;  // Make a copy since reverse modifies in place
        reverse(arr);

        if (arr != want) {
          throw std::runtime_error("\nreverse(" + charVecToStr(arr_orig) + "): got: " +
                                   charVecToStr(arr) + ", want: " + charVecToStr(want) + "\n");
        }
      }
    
    cout << "ALL ARRAY REVERSE TEST PROVIDED PASSED." << endl;
    
    return EXIT_SUCCESS;
}
