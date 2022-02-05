class Solution {
public:
    unordered_map<string, pair<string, double>> root;
    string find(string x, double& a){
        if(root.find(x) == root.end()){
            root[x] = make_pair(x, 1.0);
            return x;
        }else{
            string y = root[x].first;
            if(y == x)
                return y;
            else{
                a *= root[x].second;
                return find(y, a);
            }    
        }
    }
    
    void unionset(string x, string y, double a){
        double xv = 1.0, yv = 1.0;
        string ux = find(x, xv);
        string uy = find(y, yv);
        if(ux != uy){
            root[ux].first = uy;
            root[ux].second = yv * a / xv;
        } 
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int qn = queries.size();
        vector<double> ans(qn);
        
        //union-find with weights
        int en = equations.size();
        for(int i = 0; i < en; i++){
            unionset(equations[i][0], equations[i][1], values[i]);
        }
        
        for(int i = 0; i < qn; i++){
            if(root.find(queries[i][0]) == root.end() || root.find(queries[i][1]) == root.end()){
                ans[i] = -1;
            }
            else{
                double xv = 1.0, yv = 1.0;
                string x = find(queries[i][0], xv);
                string y = find(queries[i][1], yv);
                if(x != y)
                    ans[i] = -1;
                else
                    ans[i] = xv / yv;
            }
        }
        
        return ans;
        
    }
};