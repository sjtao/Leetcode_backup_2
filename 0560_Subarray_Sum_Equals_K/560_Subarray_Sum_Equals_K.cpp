/**
Runtime: 149 ms, faster than 7.27% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 36.2 MB
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[sum]++;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.count(sum-k)>0)
                count += mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
