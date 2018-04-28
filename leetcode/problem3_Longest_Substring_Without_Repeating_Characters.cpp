/*
 * Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> my_set;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (my_set.find(s[j]) == my_set.end()){
                my_set.insert(s[j++]);
                ans = max(ans, j - i);
            } else {
                my_set.erase(s[i++]);
            }
        }
        return ans;
    }
};

