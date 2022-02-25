class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int m;
        int ans = arr.size();
        while(l <= r){
            m = l + (r-l)/2;
            if(arr[m] == m){
                ans = min(ans, m);
                r = m-1;
            }
            else if(arr[m] > m){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans == arr.size() ? -1 : ans;
    }
};