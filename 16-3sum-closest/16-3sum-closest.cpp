class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int sum, dn, diff = INT_MAX;
        
        for(int i = 0; i < n; ++i){
            int l = i+1;
            int r = n-1;
            while(l < r){
                sum = nums[l] + nums[r] + nums[i];
                dn = target-sum;
                if(dn > 0) l++;
                else if(dn == 0) return sum;
                else  r--;
                if(abs(diff) > abs(dn)){
                    diff = dn;
                }
            }
        }
        
        return target-diff;
    }
};