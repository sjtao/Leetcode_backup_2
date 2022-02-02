class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 == 0 || n2 == 0) return 0;
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                dp[i+1][j+1] = nums1[i] == nums2[j] ? dp[i][j]+1 : max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[n1][n2];
    }
};