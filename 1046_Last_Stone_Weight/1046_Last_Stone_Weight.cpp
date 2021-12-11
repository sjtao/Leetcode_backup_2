/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 7.7 MB, less than 34.81% of C++ online submissions for Last Stone Weight.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones[0];
        
        //max heap
        priority_queue <int> pq;
        for(int s : stones){
            pq.push(s);
        }
        int x, y, r;
        while(pq.size()>1){
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();
            r = abs(y - x);
            if(r != 0) pq.push(r);
        }
        
        return pq.size() == 0 ? 0 : pq.top();
    }
};
