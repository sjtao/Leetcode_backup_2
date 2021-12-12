/**
Runtime: 16 ms
Memory Usage: 12.3 MB
85.6%
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //sort the intervals by starting time
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto v:intervals){
            if(!pq.empty() && pq.top() <= v[0]){
                pq.pop();
            }
            pq.push(v[1]);
        }
        
        return pq.size();
        
    }
};
