/**
Runtime: 4 ms, faster than 67.21% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.3 MB, less than 48.30% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/

class Solution {
public:
         int solveDP1(vector<int> &prices){ 
        
         int dp[prices.size() + 2][2];
        
        for(int day = (int)prices.size() + 1;day >= 0;day--){
            for(int buy = 0;buy <= 1;buy++){
                
                int &ans = dp[day][buy];
                
                if(day >= prices.size()){
                    ans = 0;
                }
                else{
                    
                    // First Choice: no transaction this say
                    int ans1 = dp[day + 1][buy]; 
         
                    // Second Choice: doing the required transaction this day
                    int ans2 = 0;
                    if(buy){
                        ans2 = -prices[day] + dp[day + 1][0];
                    }
                    else{
                        ans2 = prices[day] + dp[day + 2][1];
                    }
                    
                    ans = max(ans1, ans2);
                    
                }
            }
        }
        
        return dp[0][1];       
    }
    
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        ans = solveDP1(prices);
        return ans;
    }
};
