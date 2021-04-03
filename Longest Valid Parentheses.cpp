/*
Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0
 
Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxL = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    maxL = max(maxL, i - st.top());
            }
        }
        return maxL;
    }
};
