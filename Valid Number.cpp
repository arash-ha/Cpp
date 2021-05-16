/*
Valid Number

A valid number can be split up into these components (in order):
A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):
(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):
(Optional) A sign character (either '+' or '-').
At least one digit.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
Given a string s, return true if s is a valid number.

Example 1:

Input: s = "0"
Output: true

Example 2:

Input: s = "e"
Output: false

Example 3:

Input: s = "."
Output: false

Example 4:

Input: s = ".1"
Output: true
 
Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/

class Solution {
public:
    bool isNumber(string s) {
        while(!s.empty() && s[0] == ' ')
            s.erase(s.begin());
        while (!s.empty() && s[s.size()-1] == ' ')
            s.erase(s.end()-1);
        if(s.empty())
            return false;
        
        int state = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '-' || s[i] == '+'){
                if(state == 0 || state == 3)
                    state ++;
                else
                    return false;
            }
            else if(s[i] == '.')
            {
                if( state == 2)   
                    state = 7;
                else if(state == 0|| state == 1)
                    state = 6;
                else
                    return false;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(state == 1 || state == 4 || state == 6)
                    state ++;
                else if(state == 0 || state == 3)
                    state = state+2;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(state == 2 ||  state == 7)
                    state = 3;
                else
                    return false;
            }
            else
                return false;
        }
        
        if(state == 2|| state == 7 || state == 5)
            return true;
        
        return false;
    }
};
