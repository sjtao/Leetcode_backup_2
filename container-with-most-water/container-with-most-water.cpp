class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int cur;
        int left = 0, right = n-1, m;
        while(left < right){
            m = min(height[left], height[right]);
            cur = (right - left) * m;
            if(m == height[left]) left++;
            if(m == height[right]) right--;
            area = max(area, cur);
        }
        return area;
    }
};