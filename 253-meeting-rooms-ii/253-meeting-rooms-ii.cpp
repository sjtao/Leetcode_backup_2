class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(intervals[0][1]);
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= q.top())
                q.pop();
            q.push(intervals[i][1]);
        }
        
        return q.size();
    }
};