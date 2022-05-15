class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int pair = 0;
        for(int j = 1; j < n; j++){
            for(int i = 0; i < j; i++){
                if(nums[i] == nums[j]){
                    pair++;
                }
            }
        }
        return pair;
    }
};