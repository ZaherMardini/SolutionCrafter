#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

    // My wrong approach: count every occurence and stop on the first duplicate, reset, repeat

    // The Optimal Approach: Sliding Window
    // You need a two-pointer sliding window. The key insight is:
    // When a duplicate is found at index i, the left boundary should jump to (last seen position of that character) + 1

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeenIndex;
        int longest = 0;
        int windowSize = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (lastSeenIndex.count(c) && lastSeenIndex[c] >= left) { // the last seen must not be behind the left window boundry, see the testcase "tmmzuxt"
                left = lastSeenIndex[c] + 1;
            }
            lastSeenIndex[c] = i;
            windowSize = i - left + 1;
            longest = max(longest, windowSize);
        }
        return longest;
    }

int main(){
    // int result = lengthOfLongestSubstring("pwwkewepoljing");
    // int result = lengthOfLongestSubstring("12233||1234||12345"); // 6
    int result = lengthOfLongestSubstring("tmmzuxt"); // 5 condition insight
    // int result = lengthOfLongestSubstring(" "); // 1
    // int result = lengthOfLongestSubstring("dvdf"); // 3 killer
    // int result = lengthOfLongestSubstring("bcdef||gh||hijklmnbcdeo8prtyu123456");
    return result;
}