/*
Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?
*/

// Solution I
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(i == 0){
                    s.erase(i, 1);
                    i--;
                }
                else{
                    s.erase(i - 1, 2);
                    i -= 2;
                }
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(i == 0){
                    t.erase(i, 1);
                    i--;
                }
                else{
                    t.erase(i - 1, 2);
                    i -= 2;
                }
            }
        }
        return s == t;
    }
};

// Solution II
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
    }
    string helper(const string str){
        stack<char> stk;
        for(auto c : str){
            if(c == '#' && !stk.empty())
                stk.pop();
            else
                if(c != '#')
                    stk.push(c);
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
