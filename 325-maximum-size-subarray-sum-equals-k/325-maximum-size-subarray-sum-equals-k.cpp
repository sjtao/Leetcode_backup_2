class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        long long int sum = 0;
        int len = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k)
                len = i+1;
            
            if(mp.find(sum-k) != mp.end())
                len = max(len, i-mp[sum-k]);
            
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        
        return len;        
    }
};