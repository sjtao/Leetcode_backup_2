class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int province = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                q.push(i);
                while(!q.empty()){
                    int s = q.front();
                    q.pop();
                    visited[s] = 1;
                    for(int j = 0; j < n; j++){
                        if(isConnected[s][j] && visited[j] == 0)
                            q.push(j);
                    }
                }
                province++;
            }
        }
        return province;
    }
};