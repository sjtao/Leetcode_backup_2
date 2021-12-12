/**
Runtime: 68 ms, faster than 91.57% of C++ online submissions for Minimum Cost to Connect Sticks.
Memory Usage: 24.2 MB, less than 57.18% of C++ online submissions for Minimum Cost to Connect Sticks.
*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // add all sticks to the min heap.
        for (int i = 0; i < sticks.size(); i++) {
            pq.push(sticks[i]);
        }
        
        while(pq.size()>1){
            int c1 = pq.top(); pq.pop();
            int c2 = pq.top(); pq.pop();
            cost += (c1 + c2);
            pq.push(c1+c2);
        }
        return cost;
    }
};
