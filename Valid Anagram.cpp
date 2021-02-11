/*
Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

// Solution 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> ump;
        for(auto ch : s) ump[ch]++;
        for(int i = 0; i < s.size(); i++){
            if(--ump[t[i]] < 0)
                return false;
        }
        return true;
    }
};

// Solution 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
