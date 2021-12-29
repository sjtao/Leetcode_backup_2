/**
Runtime: 92 ms, faster than 33.84% of C++ online submissions for Container With Most Water.
Memory Usage: 59.1 MB, less than 36.70% of C++ online submissions for Container With Most Water.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int mx = 0, h;
        while(l < r){
            h = min(height[l], height[r]);
            mx = max(mx, (r-l)*h);
            if(h == height[l]) l++;
            if(h == height[r]) r--;
        }
        return mx;
    }
};
