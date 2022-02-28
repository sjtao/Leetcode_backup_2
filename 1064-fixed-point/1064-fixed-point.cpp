class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int m;
        int ans = n+1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(m > arr[m])
                l = m+1;
            else if(m < arr[m])
                r = m-1;
            else{
                ans = min(ans, m);
                r = m-1;
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};