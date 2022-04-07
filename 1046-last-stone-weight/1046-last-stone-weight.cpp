class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        priority_queue<int, vector<int>> q(stones.begin(), stones.end());
        while(q.size() > 1){
            int y = q.top(); q.pop();
            int x = q.top(); q.pop();
            if(y > x)
                q.push(y-x);
        }
        return q.empty() ? 0 : q.top();
    }
};