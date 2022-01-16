class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        //count the frequency of each number showing in an odd-length array
        int sum = 0;
        for(int k = 0; k < n; ++k){
            sum += ((n-k)*(k+1) + 1) / 2 * arr[k];
        }
        return sum;
    }
};