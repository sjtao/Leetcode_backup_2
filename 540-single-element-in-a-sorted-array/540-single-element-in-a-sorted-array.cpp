class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1])
                cnt++;
            else{
                if(cnt == 1)
                    return nums[i-1];
                else{
                    cnt = 1;
                }
            }
        }
        return cnt == 1 ? nums[n-1] : -1;
    }
};