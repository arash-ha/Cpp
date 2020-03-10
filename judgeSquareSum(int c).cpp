/*
Given a non-negative integer c, your task is to
decide whether there're two integers a and b 
such that a2 + b2 = c.
*/

// Solution 1
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        long i, j;
        long max = sqrt(c);
        for(int i = 0; j = max; i <= j){
            if(pow(i,2) + pow(j,2) == c) return true;
            else if (pow(i,2) + pow(j,2) > c) j--;
            else i++;
        } 
        return false;
    }
};

// Solution 2

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for (long i = 0; pow(i,2) < c; i++){
            double j = sqrt(c - pow(i,2));
            if (j == (int) j) return true;
        }
        return false;
    }
};
