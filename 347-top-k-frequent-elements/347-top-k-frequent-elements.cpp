class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() <= k) return nums;
        unordered_map<int,int> mp;
        for(int n : nums)
            mp[n]++;
        
        priority_queue<pair<int,int>> q;
        for(auto it : mp){
            q.push({it.second, it.first});
        }
        
        vector<int> ans(k);
        int i = 0;
        while(i < k){
            ans[i] = q.top().second;
            q.pop();
            i++;
        }
        
        return ans;
    }
};