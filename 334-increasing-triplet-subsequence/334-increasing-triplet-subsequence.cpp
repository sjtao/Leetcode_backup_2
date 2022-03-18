class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = INT_MAX;
        right[n-1] = INT_MIN;
        for(int i = 1; i < n-1; i++){
            left[i] = min(left[i-1], nums[i-1]);
            right[n-1-i] = max(right[n-i], nums[n-i]);
        }
        for(int i = 0; i < n; i++){
            if(left[i] < nums[i] && nums[i] < right[i])
                return true;
        }
        return false;
    }
};