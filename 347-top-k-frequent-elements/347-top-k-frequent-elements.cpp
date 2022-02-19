class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) return nums;
        unordered_map<int,int> mp;
        
        //max_heap
        priority_queue<pair<int,int>> pq;
        
        for(int n : nums){
            mp[n]++;
        }
        
        for(auto t : mp){
            pq.push({t.second, t.first});
        }
        
        vector<int> ans(k);
        int i = 0;
        while(i < k){
            ans[i++] = pq.top().second;
            pq.pop();
        }
        
        
        return ans;
    }
};