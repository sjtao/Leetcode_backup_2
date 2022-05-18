class Solution {
public:

    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> sum(n+1,0);
        for(int i = 1; i < n+1; i++)
            sum[i] = sum[i-1] + arr[i-1];
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n+1; j+=2){
                ans += (sum[j] - sum[i]);
            }
        }
        
        return ans;
    }
};