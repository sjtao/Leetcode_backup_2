/**
Runtime: 12 ms, faster than 96.21% of C++ online submissions for Paint House II.
Memory Usage: 10.8 MB, less than 91.32% of C++ online submissions for Paint House II.
*/
//O(nkk)
class Solution {
public:
    int mincolorbutk(vector<int>& cost, int k){
        int mi = INT_MAX;
        for(int i = 0; i < cost.size(); i++){
            if(i != k)
                mi = min(mi, cost[i]);
        }
        return mi;
    }
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                costs[i][j] += mincolorbutk(costs[i-1], j);
            }
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};

//O(nk)
/**
Runtime: 16 ms, faster than 78.55% of C++ online submissions for Paint House II.
Memory Usage: 10.9 MB, less than 91.32% of C++ online submissions for Paint House II.
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        for(int i = 1; i < n; i++){
            
            //find the min and second min of i-1 row
            int mi = -1, mis = -1;
            for(int j = 0; j < k; j++){  
                int c = costs[i-1][j];
                if(mi == -1 || c < costs[i-1][mi]){
                    mis = mi;
                    mi = j;
                }
                else if(mis == -1 || c < costs[i-1][mis]){
                    mis = j;
                }
            }
            
            int mi_pre = costs[i-1][mi], mis_pre = costs[i-1][mis];
            for(int j = 0; j < k; j++){
                if(j != mi) costs[i][j] += mi_pre;
                else              costs[i][j] += mis_pre;
            }
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};
