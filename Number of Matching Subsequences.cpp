/*
Number of Matching Subsequences

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2 

Constraints:

1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> vec(26);
		for(int i = 0; i < s.size (); ++i)
            vec[s[i] - 'a'].push_back (i);
		int res = 0;
		for(const auto& word : words){
			int x = -1;
			bool found = true;
			for(char c : word){
				auto it = upper_bound(vec[c - 'a'].begin (), vec[c - 'a'].end (), x);
				if(it == vec[c - 'a'].end ())
                    found = false;
				else
                    x = *it;
			}
			if (found)
                res++;
		}
		return res;
    }
};
