class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        //no-descending heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int w : weight)
            pq.push(w);
        
        int sum = 0;
        int apple = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
            if(sum > 5000){
                break;
            }
            apple++;
        }
        return apple;
    }
};