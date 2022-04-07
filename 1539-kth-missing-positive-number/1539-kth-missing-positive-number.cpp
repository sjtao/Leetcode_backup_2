class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int d = arr[n-1] - n;
        if(k > d)
            return arr[n-1] + k - d;
        
        int l = 0, r = n-1, m; 
        while(l < r){
            m = l + (r-l)/2;
            if(arr[m] - m - 1 >= k)
                r = m;
            else
                l = m+1;
        }
        return l+k;
    }
};