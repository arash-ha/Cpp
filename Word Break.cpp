/*
Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_map<string,int>ump;
        for(auto str : wordDict) ump[str]++;
        vector<int> find(n, 0);
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = i; j >= 0; j--){
                str = s[j] + str;
                if(j >= 1){
                    if(ump.find(str) != ump.end() && find[j-1] == 1){
                        find[i] = 1;
                        break;
                    }
                }
                else if(ump.find(str) != ump.end()){
                    find[i] = 1;
                    break;
                }
            }
        }
        return find[n-1];
    }
};
