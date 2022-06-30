class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int mid; //middle number
        if(n % 2 == 0)
            mid = (nums[n/2] + nums[n/2-1]) / 2;
        else
            mid = nums[n/2];
        
        int move = 0;
        for(int i : nums)
            move += abs(mid - i);
        
        return move;
        
    }
};