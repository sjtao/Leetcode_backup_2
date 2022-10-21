class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //naive
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                for(int j : mp[nums[i]]){
                    if(abs(i-j) <= k)
                        return true;
                }
            }
            mp[nums[i]].push_back(i);
        }
        
        return false;
    }
};