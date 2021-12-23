/**
Runtime: 4 ms, faster than 94.38% of C++ online submissions for Triangle.
Memory Usage: 8.5 MB, less than 98.66% of C++ online submissions for Triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(triangle[m-1]);
        int r = m-2;
        while(r >= 0){
            for(int i = 0; i < triangle[r].size(); i++){
                dp[i] = min(dp[i], dp[i+1]) + triangle[r][i];
            }
            r--;
        }
        return dp[0];
        
    }
};
