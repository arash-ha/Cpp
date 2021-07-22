/*
Decode Ways II

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.
Given a string s containing digits and the '*' character, return the number of ways to decode it.
Since the answer may be very large, return it modulo 109 + 7. 

Example 1:

Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".

Example 2:

Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".

Example 3:

Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
 
Constraints:

1 <= s.length <= 105
s[i] is a digit or '*'.
*/


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), p = 1000000007;
        // f2 is the answer to sub string ending at position i; Initially i = 0.
        long f1 = 1, f2 = helper(s.substr(0,1));
        // DP to get f2 for sub string ending at position n-1;
        for(int i = 1; i < n; i++){
            long f3 = (f2 * helper(s.substr(i, 1))) + (f1 * helper(s.substr(i - 1, 2)));
            f1 = f2;
            f2 = f3%p;
        }
        return f2;
    }
    int helper(string s) {
        if(s.size() == 1) {
            if(s[0] == '*')
                return 9;
            return
                s[0] == '0' ? 0 : 1;
        }
        if(s == "**")  // 11-26, except 20 because '*' is 1-9
            return 15;
        else if (s[1] =='*'){
            if(s[0] =='1')
                return 9;
            return s[0] == '2' ? 6 : 0;
        }
        else if(s[0] == '*') 
            return s[1] <= '6'? 2 : 1;
        else
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; // if two digits, it has to be in [10 26]; no leading 0
    }
};
