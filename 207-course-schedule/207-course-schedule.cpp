class Solution {
public:
/*
Build a graph of course's with a list of postreqs. Then traverse graph with a DFS. A cycle is detected when a DFS leads to a node currently in the recursion stack. course nodes can be in 1 of 3 states:
"white" or 0 == unvisited.
"gray" or 1 == in recursion stack (being visited).
"black" or 2 == done being visited.
All course nodes start as unvisited. If the DFS leads to a "black" node, it means the "black" course has more than 1 prerequisite that lead to it, but does not indicate a cycle. If the DFS leads to a "gray" node, then somehow there is a cycle in the graph and it is not possible to take all courses.
*/
    bool iscycle(vector<vector<int>>& course, vector<int>& visited, int s){
        //visited this node, checking its connected nodes
        visited[s] = 1;
        for(int i : course[s]){
            if(visited[i] == 1) return true;
            if(visited[i] == 0 && iscycle(course, visited, i)) return true;
        }
        visited[s] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if cycle in the dga
        int n = numCourses;
        vector<vector<int>> course(n);
        for(auto p : prerequisites){
            course[p[0]].push_back(p[1]);
        }
        
        vector<int> visited(n, 0);
        for(int i = 0; i < n; ++i){
            if(visited[i] == 0 && iscycle(course, visited, i))
                return false;
        }
        
        return true;
        
    }
};