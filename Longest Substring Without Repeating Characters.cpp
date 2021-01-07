/*
Longest Substring Without Repeating Characters


Given a string s, find the length of the longest substring without repeating characters.


Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int start = -1, maxL = 0;
        for(int i = 0; i < s.length(); i++){
            if(umap.count(s[i]) != 0)
                start = max(start, umap[s[i]]);
            umap[s[i]] = i;
            maxL = max(maxL, i - start);
        }
        return maxL;
    }
};
