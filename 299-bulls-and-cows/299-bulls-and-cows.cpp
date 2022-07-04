class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char, int> mp;
        int n = secret.length();
        for(int i = 0; i < n; i++)
            mp[secret[i]]++;
        
        int bulls = 0, cows = 0;
        
        for(int i = 0; i < n; i++){
            if (mp.find(guess[i]) != mp.end()){
                if(secret[i] == guess[i]){
                    bulls ++;
                    if(mp[guess[i]] <= 0)
                        cows--;
                }
                else{
                    if( mp[guess[i]] > 0){
                        cows++;
                    }
                }
                mp[guess[i]]--;
            }
            
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};