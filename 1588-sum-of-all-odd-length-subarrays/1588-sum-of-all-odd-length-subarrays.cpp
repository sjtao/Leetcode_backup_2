class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> sum(n+1, 0);
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + arr[i];
        int s = sum[n];
        int k = 3;
        while(k <= n){
            for(int i = 0; i+k <= n; i++){
                s += (sum[i+k] - sum[i]);
            }
            k+=2;
        }
        
        return s;
    }
};