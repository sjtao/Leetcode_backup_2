//Runtime: 8 ms, faster than 72.34% of C++ online submissions for Shuffle String.
//Memory Usage: 15.2 MB, less than 75.20% of C++ online submissions for Shuffle String.

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string ans;
        ans = s;
        for(int i = 0; i < s.length(); i++){
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};
