class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string a = "";
        int n1 = word1.length();
        int n2 = word2.length();
        if(n2 == 0) return word1;
        if(n1 == 0) return word2;
        
        int i = 0;
        while(i < min(n1, n2)){
            a += word1[i];
            a += word2[i];
            i++;
        }
        
        if(n1 > n2){
            for(; i < n1; i++)
                a += word1[i];
        }
        else{
            for(; i < n2; i++)
                a += word2[i];
        }
        
        return a;
    }
};