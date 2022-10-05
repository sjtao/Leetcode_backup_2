class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            int a = nums[i];
            for(int j = 0; j < n; j++){
                if(copy[j] < a)
                    res[i]++;
            }
        }
        return res;
    }
};