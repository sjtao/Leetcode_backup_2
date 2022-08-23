class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int r = target - nums[i];
            if(mp.find(r) == mp.end())
                mp[nums[i]] = i;
            else
                return {i, mp[r]};
        }
        return {};
    }
};