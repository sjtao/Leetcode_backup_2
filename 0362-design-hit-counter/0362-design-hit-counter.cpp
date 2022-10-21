class HitCounter {
public:
    unordered_map<int, int> mp; //time, hit
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        mp[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int res = 0;
        for(int i = timestamp; i > timestamp - 300 && i > 0; i--){
            if(mp.find(i) != mp.end()){
                res += mp[i];
            }
        }
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */