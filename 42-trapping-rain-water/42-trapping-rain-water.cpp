class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        
        int lm = height[0];
        for(int i = 1; i < n; i++){
            lm = max(lm, height[i]);
            left[i] = lm - height[i];
        }
        
        int rm = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rm = max(rm, height[i]);
            right[i] = rm - height[i];
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(left[i], right[i]);
        }
        
        return res;
    }
};