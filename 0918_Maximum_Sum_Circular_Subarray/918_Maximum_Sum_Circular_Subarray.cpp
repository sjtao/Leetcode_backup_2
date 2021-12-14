/**
Runtime: 56 ms, faster than 89.81% of C++ online submissions for Maximum Sum Circular Subarray.
Memory Usage: 39.8 MB, less than 93.81% of C++ online submissions for Maximum Sum Circular Subarray.
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //Kadane's Algorithm
        int minSum = 0, maxSum = 0;
        int bestMIN = INT_MAX, bestMAX = INT_MIN;
        int total = 0;
        for(int n : nums){
            maxSum = max(maxSum + n, n);
            bestMAX = max(bestMAX, maxSum);
            minSum = min(minSum + n, n);
            bestMIN = min(bestMIN, minSum);
            total += n;
        }
        return bestMAX > 0 ? max(bestMAX, total-bestMIN) : bestMAX;
    }
};
