/*
Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:

Input: s = "a"
Output: 0

Example 3:

Input: s = "ab"
Output: 1
 
Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> res(n+1, 0);
        iota(res.begin(), res.end(), -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j] ; j++)
                res[i + j + 1] = min(res[i + j + 1], 1 + res[i - j]);

            for(int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++)
                res[i + j + 1] = min(res[i + j + 1], 1 + res[i - j + 1]);
        }
        return res[n];
    }
};
