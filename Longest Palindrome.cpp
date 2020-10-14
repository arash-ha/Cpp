/*
Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/


class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        bool odd = false;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        for(auto i : mp){
            if(i.second % 2 == 0) count+= i.second;
            else{
                if(!odd){
                	count+= i.second;
                	odd = true;
                }
                else count += i.second - 1;
            }
        }
        return count;
    }
};
