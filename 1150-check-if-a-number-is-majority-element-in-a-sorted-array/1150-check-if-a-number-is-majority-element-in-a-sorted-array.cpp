class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int r = 0;
        for(int a : nums){
            if(a == target)
                r++;
        }
        return r > n/2;
    }
};