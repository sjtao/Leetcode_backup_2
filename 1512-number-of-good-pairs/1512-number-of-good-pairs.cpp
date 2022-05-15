class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pair = 0;
        unordered_map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }
        
        for(auto m : mp){
            if(m.second > 1){
                pair += (m.second - 1) * m.second / 2;
            }
        }
        return pair;
    }
};