/**
Runtime: 8 ms, faster than 97.90% of C++ online submissions for Relative Ranks.
Memory Usage: 10.3 MB, less than 48.82% of C++ online submissions for Relative Ranks.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        //max-heap
        priority_queue<pair<int,int> > pq;
        for(int i = 0; i < n; i++){
            pq.push(make_pair(score[i], i));
        }
        
        vector<string> ans(n);
        int i = 0;
        while(i < n){
            if (i == 0) {
                ans[pq.top().second] = "Gold Medal";
            }
            else if (i == 1) {
                ans[pq.top().second] = "Silver Medal";
            }
            else if (i == 2) {
                ans[pq.top().second] = "Bronze Medal";
            }
            else{
                ans[pq.top().second] = to_string(i+1);
            }
            pq.pop();
            i++;
        }
        
        return ans;
        
        
    }
};
