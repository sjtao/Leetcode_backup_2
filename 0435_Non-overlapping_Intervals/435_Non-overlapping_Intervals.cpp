/**
Runtime: 424 ms, faster than 40.89% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 89.9 MB, less than 22.07% of C++ online submissions for Non-overlapping Intervals.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n == 1) return 0;
        
        int i = 0, j = 1;
        int c = 0;
        while(j < n){
            if(intervals[j][0] < intervals[i][1]){
                if(intervals[j][1] < intervals[i][1]){
                    i = j;
                }
                c++;
                j++;
            }else{
                i = j;
                j ++;
            }    
        }
        
        return c;
    }
};
