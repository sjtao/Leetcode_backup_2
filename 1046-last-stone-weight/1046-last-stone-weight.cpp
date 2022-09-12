class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> q;
        for(int n : stones)
            q.push(n);
        
        while(q.size() > 1){
            int y = q.top(); q.pop();
            int x = q.top(); q.pop();
            if(y != x)
                q.push(y-x);
        }
        
        return q.empty() ? 0 : q.top();        
    }
};