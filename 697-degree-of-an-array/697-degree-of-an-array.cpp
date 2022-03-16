class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, pair<int, int>> pos;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            mp[nums[i]] ++;
            if(mp[nums[i]] == 1){
                pos[nums[i]].first = i;
                pos[nums[i]].second = i;
            }    
            else
                pos[nums[i]].second = i;
        }
        
        int degree = 0;
        for(auto it : mp)
            degree = max(degree, it.second);
        
        int length = n;
        for(auto it : mp){
            if(it.second == degree){
                int len = pos[it.first].second - pos[it.first].first + 1;
                length = min(length, len);
            }
        }
        return length;        
    }
};