/*
Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 
Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec1(26, 0), vec2(26, 0), res;
        for(char c : p)
            vec1[c - 'a']++;
        for(int i = 0; i < s.length(); i++){
            vec2[s[i] - 'a']++;
            if(i >= p.length())
                vec2[s[i - p.length()] - 'a']--;
            if(vec1 == vec2)
                res.emplace_back(i - p.length() + 1);
        }
        return res;
    }
};
