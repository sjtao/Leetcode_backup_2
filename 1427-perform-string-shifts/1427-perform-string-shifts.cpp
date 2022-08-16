class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int id = 0;
        for(auto& p : shift){
            if(p[0] == 0)
                id -= p[1];
            else if(p[0] == 1)
                id += p[1];
            
            if(id < 0) id = id % n + n;
            else if(id >= n) id %= n;
        }
        
        string ans = s;
        for(int i = 0; i < n; i++)
            ans[(id + i)%n] = s[i];
        
        return ans;
    }
};