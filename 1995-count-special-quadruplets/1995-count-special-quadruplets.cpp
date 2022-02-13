class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        int n = nums.size();
        mp[nums[n-1]-nums[n-2]]++;
        
        for(int b = n-3; b >= 1; b--){
            for(int a = 0; a < b; a++){
                int sum = nums[a] + nums[b];
                if(mp.find(sum) != mp.end())
                    ans+=mp[sum];
            }
            for(int c = n-1; c > b; c--)
                mp[nums[c] - nums[b]]++;
        }
        return ans;
    }
};