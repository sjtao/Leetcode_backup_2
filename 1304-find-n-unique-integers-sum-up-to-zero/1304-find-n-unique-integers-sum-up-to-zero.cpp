class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int l = 0, r = n-1;
        int num = 1;
        while(l < r){
            ans[l++] = num;
            ans[r--] = -num;
            num++;
        }
        if(l == r) ans[l] = 0;
        return ans;
    }
};