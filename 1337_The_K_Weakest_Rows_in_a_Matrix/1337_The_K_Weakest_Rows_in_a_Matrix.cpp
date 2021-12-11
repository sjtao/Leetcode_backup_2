/**
Runtime: 16 ms, faster than 23.25% of C++ online submissions for The K Weakest Rows in a Matrix.
Memory Usage: 10.7 MB, less than 21.46% of C++ online submissions for The K Weakest Rows in a Matrix.
*/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //find # of 1 in each row
        int row = mat.size();
        map<int, int> fm;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0) break;
                fm[i]++;
            }
        }
        //save to max heap
        priority_queue<pair<int, int>> pq;
        int p = 0;
        while(p < row){
            pq.push(make_pair(fm[p], p));
            p++;
            if(pq.size()>k) pq.pop();           
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
