/*
 Letter Case Permutation
 Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        result.emplace_back(S);
        for(int i = 0; i < S.length(); i++){
            int n = result.size();
            if((S[i] > 64 && S[i] < 91) || (S[i] > 96 && S[i] < 123)){
                for(int j = 0; j < n; j++){
                    string str = result[j];
                    if(S[i] > 64 && S[i] < 91){
                        str[i] = S[i] + 32;
                        result.emplace_back(str);
                    }
                    else{
                        str[i] = S[i] - 32;
                        result.emplace_back(str);
                    }
                }
            }
        }
        return result;
    }
};
