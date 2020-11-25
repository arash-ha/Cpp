/*
Basic Calculator II


Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int a, res = 0;
        istringstream iss(s);
        char op = '+';
        while(iss >> a){
            if(op == '+' || op == '-')
                st.push(op == '+' ? a : -a);
            else{
                int last = st.top();
                st.pop();
                if(op == '*')
                    last *= a;
                else
                    last /= a;
                st.push(last);
            }
            iss >> op;
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
