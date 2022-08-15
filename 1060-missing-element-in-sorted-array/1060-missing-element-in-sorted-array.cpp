class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        for(; i < n-1; i++){
            int m = (nums[i+1]-nums[i]-1);
            if(k <= m) break;
            else k -= m;
        }
        return nums[i] + k;
    }
};