class Solution {
public:
    int bitnum(char c){
        return (c - 'a');
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> len(n), mask(n);
        
        for(int i = 0; i < n; i++){
            len[i] = words[i].length();
            int bit = 0;
            for(char c : words[i])
                bit |= 1 << bitnum(c);
            mask[i] = bit;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((mask[i] & mask[j]) == 0){
                    ans = max(ans, len[i]*len[j]); 
                }    
            }
        }
        return ans;
    }
};