class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n : nums){
            mp[n]++;
            if(mp[n] > 1)
                return true;
        }
        return false;
    }
};