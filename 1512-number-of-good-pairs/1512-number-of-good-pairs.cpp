class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pair = 0;
        unordered_map<int,int> mp;
        for(int n : nums){
            pair += mp[n]++;
        }

        return pair;
    }
};