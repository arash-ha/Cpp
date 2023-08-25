/*
Strange Printer

There is a strange printer with the following two special properties:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 
Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.
*/
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int i, int j, string& s){       
        if (dp[i][j] != -1) return dp[i][j];
        if (i == j) return dp[i][j] = 1;
        int res;
        if (s[i] == s[j] || s[j - 1] == s[j]) res = f(i, j - 1, s);
        else if (s[i] == s[i + 1]) res = f(i + 1, j, s);
        else {
            res = f(i, j - 1, s) + 1;
            for (int k = i + 1; k < j; k++) {
                if (s[k] == s[j])
                    res = min(res, f(i, k - 1, s) + f(k, j - 1, s));
            }
        }
        return dp[i][j] = res;
    }
    int strangePrinter(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return f(0, n - 1, s);
    }
};
