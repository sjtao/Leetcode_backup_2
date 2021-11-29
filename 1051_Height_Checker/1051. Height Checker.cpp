/**
Runtime: 4 ms, faster than 57.08% of C++ online submissions for Height Checker.
Memory Usage: 8.1 MB, less than 71.83% of C++ online submissions for Height Checker.
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int len = heights.size();
        if(len == 1) return 0;
        vector<int> ord_h;
        ord_h = heights;
        sort(ord_h.begin(), ord_h.end());
        int diff = 0;
        for(int i = 0; i < len; i++){
            if(heights[i] != ord_h[i]){
                diff ++;
            }
        }
        return diff;
    }
};
