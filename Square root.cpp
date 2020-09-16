/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        else if (x == 0) return 0;
        long mid, low = 0, high = x;
        while(low <= high){
        mid = (low + high)/2;
        if(mid * mid == x || (mid * mid < x && (mid + 1)*(mid + 1) > x)) return mid;
        else if (mid * mid < x && (mid + 1)*(mid + 1) <= x)  low = mid + 1;   
        else high = mid - 1;
        }
        return mid;
    }
};
