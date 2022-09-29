class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n+1, 0);
        
        for(int i = 0; i < n; i++)
            left[i+1] = left[i] + nums[i];
        
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < n+1; i++){
            int r = left[i] - k;
            if(mp.find(r) != mp.end()){
                res += mp[r];
            }
            
            mp[left[i]]++;
        }
        
        return res;
    }
};