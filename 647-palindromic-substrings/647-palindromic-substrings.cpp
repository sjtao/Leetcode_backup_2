class Solution {
public:
    bool palin(string s, int start, int end){
        if(start > end)
            return false;
        int i = start, j = end;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        int num = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(palin(s, i, j))
                    num ++;
            }
        }
        return num;
    }
};