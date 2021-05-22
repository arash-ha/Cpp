/*
Find and Replace Pattern

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 
Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,int> ump;
        string ps;
        for(int i = 0; i < pattern.size(); i++){
            if(ump.find(pattern[i]) == ump.end()){
                ump[pattern[i]] = i;
                ps += to_string(i);
            }
            else
                ps += to_string(ump[pattern[i]]);
        }
        ump.clear();
        vector<string> res;
        for(auto s : words){
            string ws;
            for(int j = 0; j < s.size();j++){
                if(ump.find(s[j]) == ump.end()){
                    ump[s[j]] = j;
                    ws += to_string(j);
                }
                else
                    ws += to_string(ump[s[j]]);
            }
            ump.clear();
            if(ws == ps)
                res.emplace_back(s);
        }
        return res;
    }    
};
