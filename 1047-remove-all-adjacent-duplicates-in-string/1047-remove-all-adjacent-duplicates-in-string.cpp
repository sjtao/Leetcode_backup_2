class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(!res.empty() && s[i] == res.back())
                res.pop_back();
            else
                res.push_back(s[i]);
        }     
        return res;
    }
};