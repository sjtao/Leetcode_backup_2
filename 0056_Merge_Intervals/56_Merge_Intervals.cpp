/**
Runtime: 16 ms, faster than 87.55% of C++ online submissions for Merge Intervals.
Memory Usage: 14.2 MB, less than 52.30% of C++ online submissions for Merge Intervals.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int a = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > ans[a][1]){
                ans.push_back(intervals[i]);
                a++;
            }
            else{
                ans[a][1] = max(ans[a][1], intervals[i][1]);
            }
        }
        return ans;
    }
};
