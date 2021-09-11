/*
Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 
Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation.
'-' could be used as a unary operation but it has to be inside parentheses.
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0, sign = 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])){
                int val = 0;
                while(i < s.length() && isdigit(s[i])){
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                res += (val * sign);
                i--;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '('){
                stk.push(res);
                stk.push(sign);            
                res = 0;
                sign = 1;
            }
            else{
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
            }
        }
        
        return res;
    }
};
