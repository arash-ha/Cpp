/*
Minimum Domino Rotations For Equal Row

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6
*/

class Solution {
    int DominoRotations(vector<int> A, vector<int> B){
        int minRotation = INT_MAX;
        for(int j = 1; j <= 6; j++){
            int swap = 0, i = 0;
            for(; i < A.size(); i++){
                if(A[i] == j) continue;
                else if(B[i] == j) swap++;
                else break;
            }
            if(i == A.size() & minRotation > swap)
                minRotation = swap;
        }
        return minRotation == INT_MAX ? -1 : minRotation;
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int AB = DominoRotations(A, B);
        int BA = DominoRotations(B, A);
        return AB == -1 ? BA : BA == -1 ? AB : min(AB, BA);
    }
};
