class Solution {
public:
    int findmx(vector<int> m){
        int mx = -1, mi;
        for(int i = 0; i < m.size(); i++){
            if(mx < m[i]){
                mx = m[i];
                mi = i;
            }
        }
        return mi;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> id(2,-1);
        
        int row = mat.size();
        int col = mat[0].size();
        int lr = 0, rr = row - 1, mr;
        while(lr <= rr){
            mr = lr + (rr - lr) / 2;
            //find max in mr row
            int mi = findmx(mat[mr]);
            //compare to top and bottom numbers
            bool top = mr-1 >= lr && mat[mr-1][mi] > mat[mr][mi];
            bool bot = mr+1 <= rr && mat[mr+1][mi] > mat[mr][mi];
            if(!top && !bot){
                id[0] = mr; id[1] = mi; return id;
            }
            else if(bot)
                lr = mr + 1;
            else
                rr = mr - 1;
        }
        
        return id;
    }
};