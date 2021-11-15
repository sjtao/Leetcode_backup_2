//Runtime: 4 ms, faster than 89.57% of C++ online submissions for Richest Customer Wealth.
//Memory Usage: 7.8 MB, less than 87.21% of C++ online submissions for Richest Customer Wealth.

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = -1;
        
        int customer = accounts.size();
        for(int i = 0; i < customer; i++){
            int sum = 0;
            for(int j = 0; j < accounts[i].size(); j++){
                sum += accounts[i][j];
            }
            max = (max > sum) ? max : sum;
        }
        
        return max;
    }
};
