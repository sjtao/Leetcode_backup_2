class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dn(n,0); //max length of negtive products ends
        vector<int> dp(n,0); //max length of positive products ends
        
        if(nums[0] > 0) dp[0] = 1;
        if(nums[0] < 0) dn[0] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == 0){
                dp[i] = 0;
                dn[i] = 0;
            }
            else if(nums[i] > 0){ //sign unchanged
                dp[i] = dp[i-1] + 1;
                dn[i] = dn[i-1] == 0 ? 0 : dn[i-1] + 1;
            }
            else{//sign changed
                dp[i] = dn[i-1] == 0 ? 0 : dn[i-1] + 1;
                dn[i] = dp[i-1] + 1;
            }      
        }
        int ans = dp[0];
        for(int p : dp)
            ans = max(ans, p);
        
        return ans;
    }
};