class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int d = (arr[n-1] - arr[0])/n;
        if (d == 0) return arr[0];
        int l = 0;
        int r = n-1;
        int m;
        while(l < r){
            m = l + (r-l)/2;
            if(arr[m]==arr[0]+m*d)
                l = m+1;
            else
                r = m;
      }
        return arr[0] + l * d;
    }
};