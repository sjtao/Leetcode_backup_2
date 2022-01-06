class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp, first;
        int n = nums.size();
        int ans = n+1;
        int degree = -1;
        
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i])==mp.end())
                first[nums[i]] = i;
            mp[nums[i]]++;
            if(mp[nums[i]] > degree){
                degree = mp[nums[i]];
                ans = i - first[nums[i]] + 1;
            }
            else if(mp[nums[i]] == degree){
                ans = min(ans, i - first[nums[i]]+1);
            }
        }

        
        return ans;
        
    }
};