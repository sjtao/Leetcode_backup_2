class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<int, int> mask;
        
        for(int i = 0; i < n; i++){
            int len = words[i].length();
            int bit = 0;
            for(char c : words[i])
                bit |= 1 << (c - 'a');
            
            for(auto it : mask){
                if((it.first & bit) == 0)
                    ans = max(ans, it.second * len);
            }
            mask[bit] = max(len, mask[bit]);
        }
        
        return ans;
    }
};