class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans;
        for(int n : nums){
            mp[n] += 1;
        }
        for(int n : nums){
            if(mp[n] == 1){
                ans = n;
                break;
            }
        }
        return ans;
    }
};