class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int answer = 0;
        int n = costs.size();
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){return a[0] - a[1] > b[0] - b[1];});
        for(int i = 0; i < n/2; i++){
            answer += costs[i][1];
            answer += costs[n/2+i][0];
        }
        return answer;
    }
};