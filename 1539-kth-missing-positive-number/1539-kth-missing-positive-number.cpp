class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int d = arr[n-1] - n;
        if(k > d)
            return arr[n-1] + k - d;
        
        for(int i = 0; i < n; i++){
            int m = i == 0 ? arr[i] - 1 : (arr[i] - arr[i-1] - 1);
            if(k <= m)
                return i == 0 ? k : arr[i-1] + k;
            k -= m;
        }
        return -1;
    }
};