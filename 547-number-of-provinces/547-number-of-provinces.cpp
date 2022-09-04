class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int k){
        for(int j = 0; j < n; j++){
            if(isConnected[k][j] && visited[j] == 0){
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<int> visited(n, 0);
        int province = 0;
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                dfs(isConnected, visited, i);
                province++;
            }
        }
        
        return province;
    }
};