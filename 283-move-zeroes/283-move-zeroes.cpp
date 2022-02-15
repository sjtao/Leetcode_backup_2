class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int s = 0, f = 0;
        while(f < n){
            if(nums[f] != 0){
                nums[s] = nums[f];
                s++;
            }
            f++;
        }
        if(s > 0){
            while(s < n){
                nums[s] = 0;
                s++;
            }
        }
        return;   
    }
};