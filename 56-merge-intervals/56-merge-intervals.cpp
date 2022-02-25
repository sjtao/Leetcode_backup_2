class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        auto t = intervals[0];
        for(int i = 1; i < n; ++i){
            if(t[1] < intervals[i][0]){
                ans.push_back(t);
                t = intervals[i];
            }
            else{
                t[1] = max(t[1], intervals[i][1]);
            }
        }
        ans.push_back(t);
        return ans;
    }
};