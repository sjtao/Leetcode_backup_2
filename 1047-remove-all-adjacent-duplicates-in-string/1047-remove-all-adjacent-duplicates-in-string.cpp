class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for(int i = 0; i < s.size(); i++) {
            if(!stk.empty() && s[i] == stk.back())
                stk.pop_back();
            else
                stk.push_back(s[i]);
        }
        return stk;
    }
};