class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = m-1;
        while(i < n && j >= 0){
            if(grid[j][i] < 0){
                j--;
                cnt += (n-i);
            }
            else
                i++;
        }
        return cnt;
    }
};