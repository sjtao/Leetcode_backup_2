class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<int, char>> st;        
        for(int i = 0; i < n; i++){
            if(i == 0 || st.empty() || s[i] != st.back().second)
                st.push_back({1, s[i]});
            else{
                st.back().first ++;
                if(st.back().first == k){
                    st.pop_back();
                }
            }
        }
        
        string ans = "";
        for(auto a : st){
            int r = a.first;
            char c = a.second;
            while(r > 0){
                ans += c;
                r--;
            }
        }
        
        return ans;
    }
};