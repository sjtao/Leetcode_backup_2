class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        if(n == 1) return s;

        for(auto h: shift){
            int p = h[1]%n;
            if(h[0] == 0){ //left
                s = s.substr(p, n-p) + s.substr(0, p);
            }
            else{
                s = s.substr(n-p, p) + s.substr(0, n-p);
            }
        }
        
        
        return s;
        
    }
};