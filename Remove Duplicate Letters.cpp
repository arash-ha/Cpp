/*
Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> visited;
        unordered_map<char, int> counter;
        string result = "";
        for (auto c : s) counter[c]++;
        for (auto c : s) {
            counter[c]--;
            if (visited[c]) continue;  
            while (!result.empty() && c < result.back() && counter[result.back()] > 0) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result;
    }
};
