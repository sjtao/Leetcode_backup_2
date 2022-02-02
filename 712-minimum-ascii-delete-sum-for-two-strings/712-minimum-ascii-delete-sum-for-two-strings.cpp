class Solution {
public:
    int ascii_sum(string s){
        int sum = 0;
        int i = 0;
        while(i < s.length()){
            sum += s[i];
            i++;
        }
        return sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        //find the longest common substring
        //calculate ascii sum
        int n1 = s1.length();
        int n2 = s2.length();
        int sum = ascii_sum(s1) + ascii_sum(s2);
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j] + s1[i];
                else
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return sum - 2 * dp[n1][n2];
        
    }
};