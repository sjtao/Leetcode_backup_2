class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int rest = target - nums[i];
            if(mp.find(rest) == mp.end())
                mp[nums[i]] = i;
            else{
                ans.push_back(i);
                ans.push_back(mp[rest]);
                break;
            }
        }
        return ans;
    }
};