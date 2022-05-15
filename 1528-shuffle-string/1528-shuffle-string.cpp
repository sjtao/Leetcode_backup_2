class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        string r = s;
        
        for(int i = 0; i < n; i++){
            r[indices[i]] = s[i];
        }
        
        return r;
    }
};