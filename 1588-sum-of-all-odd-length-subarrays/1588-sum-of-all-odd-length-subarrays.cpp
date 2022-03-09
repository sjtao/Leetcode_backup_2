class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int l = 1;
        int sum = 0;
        while(l <= n){
            for(int i = 0; i <= n-l; i++){
                for(int j = 0; j < l; j++){
                    sum += arr[i+j];
                }
            }
            l += 2;
        }
        return sum;
    }
};