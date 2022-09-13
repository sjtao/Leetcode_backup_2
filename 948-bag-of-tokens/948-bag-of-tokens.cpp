class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int maxscore = 0, cur = 0;
        int l = 0, r = n-1;
        while(l <= r && (power >= tokens[l] || cur > 0)){
            while(l <= r && power >= tokens[l]){
                power -= tokens[l++];
                cur++;
            }
            maxscore = max(maxscore, cur);
            if(l <= r && cur > 0){
                power += tokens[r--];
                cur--;
            }
        }
        
        return maxscore;
    }
};