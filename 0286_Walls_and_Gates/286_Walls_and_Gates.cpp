/**
Runtime: 28 ms, faster than 90.72% of C++ online submissions for Walls and Gates.
Memory Usage: 14.5 MB, less than 68.43% of C++ online submissions for Walls and Gates.
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        int inf = 2147483647;
        
        queue<pair<int, int>> gate; //gate coordinates
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // four directions for each reachable
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    gate.push(make_pair(i, j));
                }
            }
        }
        
        while(!gate.empty()){
            int gx = gate.front().first;
            int gy = gate.front().second;
            gate.pop();
            for(auto dir : dirs){
                int x = gx + dir.first;
                int y = gy + dir.second;
                if(x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != inf)
                    continue;
                rooms[x][y] = rooms[gx][gy] + 1;
                gate.push(make_pair(x, y));
            }
        }
        
        return;
    }
};
