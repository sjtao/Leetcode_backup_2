/**
Runtime: 24 ms, faster than 98.46% of C++ online submissions for Interval List Intersections.
Memory Usage: 18.7 MB, less than 43.26% of C++ online submissions for Interval List Intersections.
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int f = firstList.size();
        int s = secondList.size();
        if(f == 0) return firstList;
        if(s == 0) return secondList;
        
        int a = 0, b = 0;
        vector<vector<int>> ans;
        vector<int> temp(2, 0);
        while(a < f && b < s){    
            temp[0] = max(firstList[a][0], secondList[b][0]);
            temp[1] = min(firstList[a][1], secondList[b][1]);
            if (temp[0] <= temp[1]) ans.push_back(temp);
            if(temp[1] == firstList[a][1]) a++;
            else b++;
        }
        
        return ans;
    }
};
