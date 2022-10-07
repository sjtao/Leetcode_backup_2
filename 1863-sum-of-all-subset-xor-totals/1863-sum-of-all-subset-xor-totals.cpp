class Solution {
public:
    int res = 0;
    int n;
    void setXOR(vector<int>& nums, int d, int cur){
        if(d == n){
            res += cur;
            return;
        }
        
        setXOR(nums, d+1, cur);
        setXOR(nums, d+1, cur^nums[d]);
        
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();

        setXOR(nums, 0, 0);
        return res;
    }
};