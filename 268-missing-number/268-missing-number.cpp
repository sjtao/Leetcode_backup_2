class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n+1, 1);
        for(int n:nums)
            d[n]--;
        int ans;
        for(int i = 0; i < n+1; i++){
            if(d[i] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};