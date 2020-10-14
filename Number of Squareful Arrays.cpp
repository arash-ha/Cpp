/*
Number of Squareful Arrays
Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

 

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
 

Note:

1 <= A.length <= 12
0 <= A[i] <= 1e9
*/
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int res = 0;
        sort(A.begin(), A.end());
        backtrack(A, 0, res);
        return res;
    }
    
    bool isSquare(int n){
            int root = sqrt(n);
            return root * root == n;
    }
    
    void backtrack(vector<int> A, int start, int& res){
        if(start >= A.size()) res++;
        unordered_set<int> visited;
        for(int i = start; i < A.size(); i++){
            if(visited.find(A[i]) != visited.end()) continue;
            visited.insert(A[i]);
            swap(A[i], A[start]);
            if((start == 0) || (start > 0 && isSquare(A[start] + A[start-1]))){
                backtrack(A, start + 1, res);
            }
            swap(A[i], A[start]);
        } 
    }
};
