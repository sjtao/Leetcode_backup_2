class Solution {
public:
    int numTrees(int n) {
        //root val : i, 1~i-1 go to left tree, i+1~n go to right tree
        //dp(i) = dp(i-1) * dp(n-i)
        //dp(n) = sum_i dp(i)
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int k = 2; k < n+1; k++){
            for(int i = 1; i <= k; i++){
                dp[k] += (dp[i-1] * dp[k-i]);
            }
        }
        
        return dp[n];
    }
};