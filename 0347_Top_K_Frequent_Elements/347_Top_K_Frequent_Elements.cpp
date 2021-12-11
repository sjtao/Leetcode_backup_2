/**
Runtime: 12 ms, faster than 92.58% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.6 MB, less than 70.29% of C++ online submissions for Top K Frequent Elements.
*/
class Solution {
private:
    typedef pair<int, int> pi;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int s = nums.size();
        if (k == s) return nums;
        
        //find frequency
        map<int, int> count_map;
        for (int n : nums) {
            count_map[n] += 1;
        }
        
        //save map to a min heap
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for(auto c = count_map.begin(); c != count_map.end(); c++){
            pq.push(make_pair(c->second, c->first));
            if(pq.size() > k) pq.pop();
        }
        
        //output array
        vector<int> topK(k);
        for(int i = k-1; i>=0; i--){
            topK[i] = pq.top().second;
            pq.pop();
        }
        
        return topK;
        
    }
};
