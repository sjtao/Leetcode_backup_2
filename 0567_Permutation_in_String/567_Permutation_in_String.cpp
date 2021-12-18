/**
Runtime: 8 ms, faster than 79.25% of C++ online submissions for Permutation in String.
Memory Usage: 7.4 MB, less than 44.57% of C++ online submissions for Permutation in String.
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2) return false;
        
        //window slide (n1)
        //find a window contains same chars with same freq
        vector<int> sv1(26,0), sv2(26,0);
        for(int i = 0; i < n1; i++){
            sv1[s1[i]-'a']++;
            sv2[s2[i]-'a']++;
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(sv1[i] == sv2[i])
                count++;
        }
        
        for(int i = 0; i < n2-n1; i++){
            int r = s2[i+n1] - 'a'; //in window
            int l = s2[i] - 'a';    //out window
            
            if(count == 26) return true;
            
            sv2[r]++;
            if(sv2[r] == sv1[r])
                count++;
            else if (sv2[r] == sv1[r] + 1)
                count--;
            
            sv2[l]--;
            if(sv2[l] == sv1[l])
                count++;
            else if(sv2[l] == sv1[l] - 1)
                count--;
        }
        
        return count == 26;
    }
};
