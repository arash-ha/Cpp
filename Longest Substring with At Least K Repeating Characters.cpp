/*
Longest Substring with At Least K Repeating Characters


Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || n < k)
            return 0;
        if(k <= 1)
            return n;
        unordered_map<char, int> counts;
        for(char c : s) counts[c]++;
        int l = 0;
        while(l < n && counts[s[l]] >= k)
            l++;
        if(l >= n-1)
            return l;
        int ls1 = longestSubstring(s.substr(0, l), k);
        while(l < n && counts[s[l]] < k)
            l++;
        int ls2 = (l < n) ? longestSubstring(s.substr(l), k) : 0;
        return max(ls1, ls2);
    }
};
