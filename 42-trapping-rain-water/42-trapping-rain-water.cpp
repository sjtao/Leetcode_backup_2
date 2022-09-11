class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int left = 0, right = 0;
        int res = 0;
        while(l < r){
            if(height[l] < height[r]){
                left = max(left, height[l]);
                res += (left - height[l]);
                l++;
            }
            else{
                right = max(right, height[r]);
                res += (right - height[r]);
                r--;
            }
        }
        return res;
    }
};