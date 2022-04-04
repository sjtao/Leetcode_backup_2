class AuthenticationManager {
private:
    unordered_map<string, int> mp;
    int limit;
public:
    AuthenticationManager(int timeToLive) {
        limit = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + limit;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end() || mp[tokenId] <= currentTime)
            return;
        else
            mp[tokenId] = limit + currentTime;
        
        return;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto i : mp){
            if(i.second > currentTime)
                cnt++;
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */