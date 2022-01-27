class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++){
            int r = target - nums[i];
            if(mp.count(r)>0){
                ans[0] = i;
                ans[1] = mp[r];
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};