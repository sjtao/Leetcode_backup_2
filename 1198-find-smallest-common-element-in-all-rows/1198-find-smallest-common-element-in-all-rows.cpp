class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> count(10001,0);
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count[mat[i][j]]++;
            }
        }
        for(int i = 0; i < 10001; i++){
            if(count[i] == m)
                return i;
        }
        return -1;
    }
};