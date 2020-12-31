/*
Largest Rectangle in Histogram


Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        const int size = heights.size();
        stack<int> stk;
        int i = 0, maxArea = 0;
        while(i < size){
            if(stk.empty() || heights[i] >= heights[stk.top()])
                stk.push(i++);
            else{
                int h = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[h] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};
