class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //method 1: Brutal Force
        //method 2: hashmap
        unordered_map<int,int> mp;
        vector<int> ans(2); //Only one valid answer exists
        
        mp[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans[0] = i;
                ans[1] = mp[target-nums[i]];
                break;
            }
            mp[nums[i]] = i;
        }
        
        return ans;
    }
};