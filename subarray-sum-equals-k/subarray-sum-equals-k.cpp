class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum]++;
        int res = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int r = sum - k;
            if(mp.find(r) != mp.end())
                res += mp[r];
            mp[sum]++;
        }
        return res;
    }
};