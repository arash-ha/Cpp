/*
Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]

Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Example 3:

Input: ")("
Output: [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(s);
        bool validStringFound = false;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            if(visited[cur])
                continue;
            visited[cur] = true;
            if(isValid(cur)){
                res.emplace_back(cur);
                validStringFound = true;
            }
            if(validStringFound)
                continue;
            for(int i = 0; i < cur.length(); i++){
                if(cur[i] != '(' && cur[i] != ')')
                    continue;
                string nextStr = cur.substr(0, i) + cur.substr(i + 1);
                q.push(nextStr);
            }
        }
        return res;
    }
    
    bool isValid(string str){
        int cnt = 0;
        for(char c : str){
            if(c == '(')
                cnt++;
            else if(c == ')')
                cnt--;
            if(cnt < 0)
                return false;
        }
        return cnt == 0 ? true : false;
    }
};
