class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n:nums){
            if(mp.find(n) != mp.end()) //already existed in the map
                return true;
            mp[n]++;
        }

        return false;
    }
};