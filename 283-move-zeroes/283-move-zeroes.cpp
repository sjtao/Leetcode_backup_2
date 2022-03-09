class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0;
        int f = 0;
        int n = nums.size();
        while(f < n){
            if(nums[f] != 0){
                nums[s] = nums[f];
                s++;
            }
            f++;
        }
        while(s < n){
            nums[s] = 0;
            s++;
        }
        return;
    }
};