class Solution {
public:
    string pushDominoes(string d) {
        d = "L" + d + "R";
        int n = d.size();
        
        string res = "";
        for(int i = 0, j = 1; j < n; j++){
            if(d[j] == '.')
                continue;
            
            if(i > 0)
                res += d[i];
            
            int m = j-i-1;
            if(d[i] == d[j]){
                res += string(m, d[i]);
            }
            else if(d[i] == 'L' && d[j] == 'R'){
                res += string(m, '.');
            }
            else{
                res += string(m/2, 'R') + string(m%2, '.') + string(m/2, 'L');
            }
            
            i = j;
        }
        
        return res;
    }
};