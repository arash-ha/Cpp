/*
First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

Constraints:

1 <= s.length <= 10^5
s consists of only lowercase English letters.
*/

// Solution I
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++) map[s[i]]++;
        for(int j = 0; j < s.length(); j++)  {
            if(map[s[j]] == 1){
                return j;
                break;
            }
        }
        return -1;
    }
};

// Solution II
class Solution{
public:	
	bool isUniqueChars(string str){
		
		if(str.length() > 256) return false;
		
		bool char_set[256] = {false};
		
		for(int i = 0; i < str.length(); i++){
			int val = str[i];
			if(char_set[val]) return false;
			char_set[val] = true;
		}
		return true;
	}
};

// Solution III
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(auto i : s)
            freq[i - 'a']++;
        
        for(auto i : s)
            if(freq[i - 'a'] == 1){
                int c = s.find(i);
                return c;
            }
        return -1;
    }
};
