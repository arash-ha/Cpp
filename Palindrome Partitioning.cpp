/*
Palindrome Partitioning


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
    vector<vector<string>> res;
    vector<string> temp;
    void backtrack(const string s){
        for(int i = 1; i <= s.length(); i++){
            int l = 0, r = i - 1;
            while(l <= r){
                if(s[l] != s[r])
                    break;
                l++;
                r--;
            }
            if(l > r){
                temp.emplace_back(s.substr(0, i));
                if(i == s.length())
                    res.emplace_back(temp);
                backtrack(s.substr(i));
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s);
        return res;
    }
};
