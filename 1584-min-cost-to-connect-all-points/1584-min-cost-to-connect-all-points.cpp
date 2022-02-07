class Solution {
public:
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<array<int, 3>> arr;
        vector<int> ds(n, -1);
        
        int d;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                arr.push_back({d, i, j});
            }
        }
        make_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
        
        int result = 0;
        while(!arr.empty()){
            pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
            auto [d, i, j] = arr.back();
            arr.pop_back();
            i = find(ds, i);
            j = find(ds, j);
            if(i != j){
                result += d;
                ds[i] += ds[j];
                ds[j] = i;
                if(ds[i] == -n)
                    break;
            }
        }
        
        return result;
    }
};