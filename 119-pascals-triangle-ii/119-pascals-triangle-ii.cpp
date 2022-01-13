class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
        int r = 2;
        while(r <= rowIndex){
            for(int i = r-1; i > 0; i--)
                dp[i] += dp[i-1];
            r++;
        }
        return dp;
    }
};