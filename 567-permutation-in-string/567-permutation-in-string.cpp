class Solution {
public:    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2 < n1) return false;
        
        //sliding window
        bool ans = false;
        vector<int> v1(26,0), v2(26,0);
        
        for(int i = 0; i < n1; i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(v1[i] == v2[i])
                count ++;
        }
        
        for(int i = 0; i < n2 - n1; i++){
            if(count == 26)
                return true;
            int l = s2[i] - 'a';
            int r = s2[n1+i] - 'a';
            v2[r]++;
            if(v2[r] == v1[r])
                count++;
            else if(v2[r] == v1[r]+1)
                count--;
            
            v2[l]--;
            if(v2[l] == v1[l])
                count++;
            else if(v2[l] == v1[l]-1)
                count--;
        }
        
        return count == 26;
        
        
        
    }
};