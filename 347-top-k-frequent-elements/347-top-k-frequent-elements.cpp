class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        //count frequency
        unordered_map<int,int> mp;
        for(int& n : nums)
            mp[n]++;
        
        //sort freqency
        priority_queue<pair<int,int>> pq;
        for(auto& it : mp)
            pq.push({it.second, it.first});
        
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
        
    }
};