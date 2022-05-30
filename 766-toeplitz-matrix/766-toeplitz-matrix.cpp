class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int,int> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int k = i - j;
                if(mp.find(k) != mp.end() && mp[k] != matrix[i][j])
                    return false;
                else
                    mp[k] = matrix[i][j];
            }
        }
        return true;        
    }
};