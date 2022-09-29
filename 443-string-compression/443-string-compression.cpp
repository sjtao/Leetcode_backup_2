class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
         
        int cnt = 1;
        int i, j;
        for(i = 1, j = 1; j < n; j++){
            if(chars[j] != chars[j-1]){
                if(cnt > 1){
                    string s = to_string(cnt);
                    for(char c : s)
                        chars[i++] = c;
                }
                
                chars[i++] = chars[j];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        
        if(cnt > 1){
            string s = to_string(cnt);
                for(char c : s)
                    chars[i++] = c;
        }
        
        
        return i;
    }
};