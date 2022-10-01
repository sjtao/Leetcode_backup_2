class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums)
            mp[i]++;
        
        for(auto& t : mp){
            if(t.second != 3)
                return t.first;
        }
        
        return INT_MIN;
    }
};