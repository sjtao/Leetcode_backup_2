class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int d = (arr[n-1] - arr[0])/n;
        if (d == 0) return arr[0];
        int e;
        for(int i = 1; i < n; i++){
            e = arr[i-1] + d;
            if(e != arr[i])
                break;
        }
        return e;
    }
};