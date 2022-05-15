class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuf(2*n);
        int j = 0;
        for(int i = 0; i < n; i++){
            shuf[j++] = nums[i];
            shuf[j++] = nums[i+n];
        }
        return shuf;
    }
};