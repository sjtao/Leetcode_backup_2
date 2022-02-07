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

class UnionFind{
private:
    vector<int> root, rank;
    
public:
    UnionFind(int sz): root(sz), rank(sz){
        for(int i = 0; i < sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else{
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        if(sz == 0)
            return 0;
        
        priority_queue<Edge> pq;
        UnionFind uf(sz);
        
        for(int i = 0; i < sz; i++){
            for(int j = i+1; j < sz; j++){
                int cost = abs(points[i][0] -points[j][0]) + 
                    abs(points[i][1] -points[j][1]);
                Edge edge(i, j, cost);
                pq.push(edge);
            }
        }
        
        int result = 0;
        int count = sz - 1;
        while(!pq.empty() && count>0){
            Edge edge = pq.top();
            pq.pop();
            if(!uf.connected(edge.point1, edge.point2)){
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};