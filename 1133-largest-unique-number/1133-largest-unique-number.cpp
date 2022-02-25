class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int n:nums)
            mp[n]++;
        
        int ans = -1;
        for(auto it:mp){
            if(it.second > 1)
                continue;
            ans = max(ans, it.first);
        }
        
        return ans;
    }
};