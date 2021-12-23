/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.3 MB, less than 91.37% of C++ online submissions for Pascal's Triangle II.
*/
//math
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for(int i = 1; i<rowIndex+1; i++){
            ans.push_back((int)(ans.back() * (long long)(rowIndex+1-i)/i));
        }
        return ans;
    }
};

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.4 MB, less than 78.90% of C++ online submissions for Pascal's Triangle II.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
        int r = 2;
        while(r <= rowIndex){
            for(int i = r-1; i > 0; i--){
                dp[i] += dp[i-1];
            }
            r++;
        }
        return dp;
    }
};
