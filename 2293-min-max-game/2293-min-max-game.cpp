class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return min(nums[0], nums[1]);
        
        vector<int> newnums;
        for(int i = 0; i < n; i+= 4){
            newnums.push_back(min(nums[i], nums[i+1]));
            newnums.push_back(max(nums[i+2], nums[i+3]));
        }
        
        return minMaxGame(newnums);
    }
};