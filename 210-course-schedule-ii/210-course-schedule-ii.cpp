class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int> res;
        vector<int> take = vector<int>(numCourses, 0);
        
        for(auto& p : prerequisites){
            //[0, 1]: 1 is pre of 0
            mp[p[1]].push_back(p[0]);
            take[p[0]]++;
        }
        
        queue<int> q;
        
        //course have no pre
        for(int i = 0; i < numCourses; i++){
            if(take[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int b = q.front();
            q.pop();
            res.push_back(b);
            //course has b as pre
            for(int i : mp[b]){
                take[i]--;
                if(take[i] == 0)
                    q.push(i);
            }
        }
        
        if(res.size() != numCourses)
            res = {};
        
        return res;
    }
};