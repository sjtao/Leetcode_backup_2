/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.3 MB, less than 91.37% of C++ online submissions for Pascal's Triangle II.
*/
//math
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for(int i = 1; i<rowIndex+1; i++){
            ans.push_back((int)(ans.back() * (long long)(rowIndex+1-i)/i));
        }
        return ans;
    }
};
