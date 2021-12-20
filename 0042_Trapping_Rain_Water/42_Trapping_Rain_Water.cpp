/**
Runtime: 8 ms, faster than 80.06% of C++ online submissions for Trapping Rain Water.
Memory Usage: 15.7 MB, less than 61.19% of C++ online submissions for Trapping Rain Water.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        int water = 0;
        int leftmax = 0, rightmax = 0;
        int left = 0, right = n-1;
        while(left <= right){
            if(height[left] < height[right]){ 
                leftmax = max(leftmax, height[left]);
                water += (leftmax - height[left]);
                left++;
            }
            else{
                rightmax = max(rightmax, height[right]);
                water += (rightmax - height[right]);
                right--;
            }
        }
        return water;
        
    }
};
