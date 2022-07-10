class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        //words[i].length == 2
        unordered_map<string, int> st;
        int len = 0;
        for(string t : words){
            string rev = t;
            reverse(rev.begin(), rev.end());
            if(st.find(rev) == st.end() || st[rev] == 0){
                st[t]++;
            }
            else{
                st[rev]--;
                len += 4;
            }
        }
        
        int r = 0;
        for(auto it : st){
            if(it.second > 0 && it.first[0] == it.first[1])
                r++;
        }
        
        if(r > 0) len += 2;
        
        return len;
        
    }
};