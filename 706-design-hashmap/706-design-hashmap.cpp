class MyHashMap {
public:
    vector<pair<int,int>> mp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto& it:mp){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        mp.push_back({key, value});
        return;
    }
    
    int get(int key) {
        for(auto& it:mp){
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        if(mp.size() == 0) return;
        
        int i = 0;
        for(; i < mp.size(); i++){
            if(mp[i].first == key)
                break;
        }
        if(i != mp.size())
            mp.erase(mp.begin()+i);
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */