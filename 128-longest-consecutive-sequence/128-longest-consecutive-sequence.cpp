class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        sort(nums.begin(), nums.end());
        int len = 1;
        int cur = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == 1 + nums[i-1])
                    cur ++;
                else
                    cur = 1;
                len = max(cur, len);
            }
        }
        
        return len;
    }
};