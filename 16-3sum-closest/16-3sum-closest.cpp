class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        int sum, ans;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                for(int k = j+1; k < n; ++k){
                    sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum - target) < diff){
                        diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};