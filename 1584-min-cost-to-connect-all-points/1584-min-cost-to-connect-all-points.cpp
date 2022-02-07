class Edge{
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost): point1(point1), point2(point2), cost(cost){}
};

bool operator<(const Edge& edge1, const Edge& edge2){
    return edge1.cost > edge2.cost;
}

class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's algorithm
        int sz = points.size();
        if(sz == 0)
            return 0;
        
        priority_queue<Edge> pq;

        for(int i = 1; i < sz; i++){
            int cost = abs(points[i][0] -points[0][0]) + 
                abs(points[i][1] -points[0][1]);
            Edge edge(0, i, cost);
            pq.push(edge);
        }
        
        vector<bool> visited(sz);
        visited[0] = true;
        
        int result = 0;
        int count = sz - 1;
        while(!pq.empty() && count>0){
            Edge edge = pq.top();
            pq.pop();
            int p1 = edge.point1;
            int p2 = edge.point2;
            int cost = edge.cost;
            if(!visited[p2]){
                result += cost;
                visited[p2] = true;
                for(int j = 0; j < sz; j++){
                    if(!visited[j]){
                        int cost = abs(points[j][0] -points[p2][0]) + 
                            abs(points[j][1] -points[p2][1]);
                        Edge edge(p2, j, cost);
                        pq.push(edge);
                    }
                }
                count--;
            }
        }
        return result;
    }
};