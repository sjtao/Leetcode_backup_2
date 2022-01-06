class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //Kadane's Algorithm
        // |___|___max______|_____|
        // total_sum = max_subarray + min_rest
        // circular array 
        int minbest = INT_MAX, maxbest = INT_MIN;
        int mincur = 0, maxcur = 0, sum = 0;
        for(int n: nums){
            sum += n;
            mincur = min(mincur+n, n);
            minbest = min(minbest, mincur);
            maxcur = max(maxcur+n, n);
            maxbest = max(maxbest, maxcur);
        }
        
        return maxbest > 0 ? max(sum-minbest, maxbest) : maxbest;
    }
};