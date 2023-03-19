/*
Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
Constraints:

1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0]){
                int i1 = i + 1;
                int j = 1;
                while(haystack[i1] && needle[j]){
                    if(haystack[i1] != needle[j])
                        break;
                    i1++;
                    j++;
                }
                if (j == needle.length())
                    return i;
            }
        }
        return -1;  
    }
};
