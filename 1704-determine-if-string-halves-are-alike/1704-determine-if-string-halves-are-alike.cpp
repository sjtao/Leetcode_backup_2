class Solution {
public:
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    bool halvesAreAlike(string s) {
        int n = s.length() / 2;
        int first = 0;
        for(int i = 0; i < n; i++){
            if(st.find(s[i]) != st.end())
                first++;
            if(st.find(s[i+n]) != st.end())
                first--;
        }
        return first == 0;
    }
};