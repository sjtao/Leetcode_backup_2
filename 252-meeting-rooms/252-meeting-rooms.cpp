class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
        
        sort(intervals.begin(), intervals.end());
        int t = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < t)
                return false;
            else{
                t = intervals[i][1];
            }
        }
        
        return true;
    }
};