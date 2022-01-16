class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> missnum(n, 0);
        int i;
        for(i = 1; i < n; ++i){
            missnum[i] = missnum[i-1] + nums[i] - nums[i-1] - 1;
        }
        
        for(i = 0; i < n-1; ++i){
            if(missnum[i] <= k && k <= missnum[i+1])
                break;
        }
        
        int ans = nums[i] + k - missnum[i];

        return ans;
        
    }
};