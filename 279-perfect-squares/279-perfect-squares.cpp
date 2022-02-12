class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
    
        int i = 0;
        while(i * i <= n){
            sq.push_back(i*i);
            i++;
        }
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < sq.size(); j++){
                if(i < sq[j])
                    break;
                dp[i] = min(dp[i], dp[i - sq[j]]+1);
            }
        }
        
        return dp[n];
        
    }
};