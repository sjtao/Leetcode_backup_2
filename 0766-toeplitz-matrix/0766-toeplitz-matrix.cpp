class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int d = i-j;
                if(mp.find(d) == mp.end())
                    mp[d] = matrix[i][j];
                else{
                    if(matrix[i][j] != mp[d])
                        return false;
                }
            }
        }
        
        return true;
    }
};