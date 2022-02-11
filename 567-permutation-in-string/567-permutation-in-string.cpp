class Solution {
public:
    
    bool permutation(string s1, string s2, int n){
        vector<int> v1(26,0), v2(26,0);
        
        for(int i = 0; i < n; i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2 < n1) return false;
        
        //sliding window
        bool ans = false;
        for(int i = 0; i <= n2 - n1; i++){
            bool p = permutation(s1, s2.substr(i, i+n1), n1);
            ans = ans || p;
        }
        
        return ans;
        
        
        
    }
};