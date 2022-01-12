class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> open;
        queue<int> qe;
        
        open.insert(0);
        for(int i = 0; i < rooms[0].size(); i++)
            qe.push(rooms[0][i]);
        
        while(!qe.empty()){
            int key = qe.front(); qe.pop();
            if(open.find(key) == open.end()){
                open.insert(key);
                for(int i = 0; i < rooms[key].size(); i++)
                    qe.push(rooms[key][i]);
            }
        }
        
        return open.size() == n;
        
    }
};