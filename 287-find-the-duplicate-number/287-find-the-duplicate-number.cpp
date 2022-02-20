class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        for(int i = 0; i < n; i++){
            int idx = abs(nums[i]);
            nums[idx] *= -1;
            if(nums[idx] > 0){
                ans = idx;
                break;
            }   
        }
        return ans;
    }
};