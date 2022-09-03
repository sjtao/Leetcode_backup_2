class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        int start = intervals[0][0];
        int end   = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] > end){
                res.push_back({start, end});
                start = intervals[i][0];
                end   = intervals[i][1];
            }
            else if(intervals[i][0] <= end){
                start = min(start, intervals[i][0]);
                end   = max(end, intervals[i][1]);
            }
        }
        
        res.push_back({start, end});
        return res;
    }
};