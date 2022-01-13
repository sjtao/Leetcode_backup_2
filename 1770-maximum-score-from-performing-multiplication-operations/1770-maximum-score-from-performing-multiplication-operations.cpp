class Solution {
public:
    int n, m;
    int score[1001][1001] = {0};
    int helper(vector<int>& nums, vector<int>& multipliers, int l, int r, int a){
        if(a == m) return 0;
        if (score[a][l] == 0){
            int left = nums[l] * multipliers[a] + helper(nums, multipliers, l+1, r, a+1);
            int right = nums[r] * multipliers[a] + helper(nums, multipliers, l, r-1, a+1);
            score[a][l] = max(left, right);
        }
        return score[a][l];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = multipliers.size();
        n = nums.size();
        
        return helper(nums, multipliers, 0, n-1, 0);
    }
};