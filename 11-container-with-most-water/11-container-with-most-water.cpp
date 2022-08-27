class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        
        int left, right, cur;
        int water = 0;
        while(l < r){
            left = height[l];
            right = height[r];
            if(left < right){
                cur = left * (r - l);
                l++;
            }
            else{
                cur = right * (r - l);
                r--;
            }
            water = max(water, cur);                
        }
        return water;
    }
};