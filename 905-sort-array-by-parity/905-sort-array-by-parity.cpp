class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;
        
        vector<int> ans(n);
        int odd = n-1, even = 0;
        for(int a : nums){
            if(a % 2 == 1)
                ans[odd--] = a;
            else
                ans[even++] = a;
        }
        
        return ans;
    }
};