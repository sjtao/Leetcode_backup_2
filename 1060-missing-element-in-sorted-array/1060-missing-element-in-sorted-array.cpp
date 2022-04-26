class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int d = 0; 
        for(int i = 1; i < n; i++){
            d += nums[i] - nums[i-1] - 1;
            if(d >= k){
                return nums[i] - (d-k) - 1;
            }
        }
         return nums[n-1] + (k-d);
    }
};