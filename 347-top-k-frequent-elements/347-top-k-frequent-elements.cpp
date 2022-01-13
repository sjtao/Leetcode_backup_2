class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        
        map<int,int> mp; //sorted according to the value ascendingly
        for(int n : nums)
            mp[n]++;
        
        // Creates a min heap
        priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minq;
        for(auto it : mp){
            minq.push({it.second, it.first});
            if(minq.size() > k)
                minq.pop();
        }
        
        vector<int> ans(k);
        int i = 0;
        while(!minq.empty()){
            ans[i++] = minq.top().second;
            minq.pop();
        }
        
        return ans;
    }
};