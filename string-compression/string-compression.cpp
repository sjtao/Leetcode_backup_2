class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1)  return n;
        
        int j = 1;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(chars[i] == chars[i-1])
                count++;
            else{
                if(count != 1){
                    string cnt = to_string(count);
                    for(char c :cnt)
                        chars[j++] = c;
                }
                    
                chars[j++] = chars[i];
                count = 1;
            }
        }
        
        if(count != 1){
            string cnt = to_string(count);
            for(char c :cnt)
                chars[j++] = c;
        }

        
        return j;        
    }
};