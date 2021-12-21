/**
Runtime: 8 ms, faster than 87.02% of C++ online submissions for Keys and Rooms.
Memory Usage: 10.5 MB, less than 37.04% of C++ online submissions for Keys and Rooms.
*/
//Depth-First Search
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size(); // number of rooms
        vector<int> visited(m, 0);
        stack<int> key;
        
        //room 0 is unlocked
        for(int j = 0; j < rooms[0].size(); j++){
            key.push(rooms[0][j]);
        }
        visited[0] = 1;
        
        while(!key.empty()){
            int r = key.top(); key.pop();
            if(visited[r]) continue;
            for(int j = 0; j < rooms[r].size(); j++){
                key.push(rooms[r][j]);
            }
            visited[r] = 1;
        }
        
        return find(visited.begin(), visited.end(), 0) == visited.end();
    }
};
