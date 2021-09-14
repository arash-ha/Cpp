/*
Reverse Only Letters

Given a string s, reverse the string according to the following rules:
All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"

Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 
Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int p1 = 0, p2 = s.length() - 1;
        while(p1 < p2){
            while(p1 < p2 && !isalpha(s[p1]))
                p1++;
            while(p1 < p2 && !isalpha(s[p2]))
                p2--;
            swap(s[p1++], s[p2--]);
        }
        return s;
    }
};
