class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> head(n + 1, vector<double>(target + 1, 0));
        head[0][0] = 1;
      
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if (j == 0) head[i][j] = head[i-1][j] * (1 - prob[i-1]);
                else head[i][j] = head[i-1][j] * (1 - prob[i-1]) + head[i-1][j-1] * prob[i-1];
            }
        }
        
        return head[n][target];
    }
};