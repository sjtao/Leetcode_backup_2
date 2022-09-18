class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int res = 0;
        int lm = 0, rm = 0;
        while(l < r){
            if(height[l] < height[r]){
                lm = max(lm, height[l]);
                res += (lm - height[l]);
                l++;
            }
            else{
                rm = max(rm, height[r]);
                res += (rm - height[r]);
                r--;
            }
        }
        
        return res;
    }
};