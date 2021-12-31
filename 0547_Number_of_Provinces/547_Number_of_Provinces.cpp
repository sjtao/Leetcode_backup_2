/**
Runtime: 39 ms, faster than 14.53% of C++ online submissions for Number of Provinces.
Memory Usage: 13.8 MB, less than 41.02% of C++ online submissions for Number of Provinces.
*/

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected,  vector<int>& visited, int x){
        for(int j = 0; j < n; j++){
            if(isConnected[x][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<int> visited(n,0);
        int province = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){ 
                dfs(isConnected, visited, i);
                province++;
            }
        }
        return province;
    }
};
