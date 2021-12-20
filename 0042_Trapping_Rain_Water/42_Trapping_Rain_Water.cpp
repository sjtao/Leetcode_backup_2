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

/**
Runtime: 8 ms, faster than 80.06% of C++ online submissions for Trapping Rain Water.
Memory Usage: 16 MB, less than 30.70% of C++ online submissions for Trapping Rain Water.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        
        int water = 0;
        vector<int> leftmax(n, 0), rightmax(n,0);
        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        for(int i = n-2; i>= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        for(int i = 0; i < n; i++){
            water += (min(rightmax[i], leftmax[i]) - height[i]);
        }
        
        return water;
        
    }
};
