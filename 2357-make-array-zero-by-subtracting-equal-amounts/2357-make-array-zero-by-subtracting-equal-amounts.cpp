class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int a = nums[i];
                for(int j = i; j < n; j++){
                    nums[j] -= a;
                }
                res++;
            }
        }
        return res;
    }
};