class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx = -1;
        for(int i = 0, j = n-1; i < j;){
            mx = max(mx, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }
        return mx;
    }
};