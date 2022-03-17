/*
Score of Parentheses

Given a balanced parentheses string S, compute the score of the string based on the following rule:
() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 
Example 1:

Input: "()"
Output: 1

Example 2:

Input: "(())"
Output: 2

Example 3:

Input: "()()"
Output: 2

Example 4:

Input: "(()(()))"
Output: 6
 
Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
*/
// Solution I
class Solution {
public:
    int scoreOfParentheses(string S) {
        int a = 0, res = 0;
        for(int i = 0; i < S.length() - 1; i++){
            if(S[i] == '('){
                if(S[i + 1] == ')')
                    res += 1 << a;
                a++;
            }
            else
                a--;
        }
        return res;
    }
};

// Solution II

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack < int > st;
        st.push(0);
        for(char c: s){
            if(c == ')'){
                int top = st.top();
                st.pop();
                int val = (top > 0) ? top * 2 : 1;                
                st.top() += val;
            }
            else
                st.push(0);
        }
        return st.top();
    }
};
