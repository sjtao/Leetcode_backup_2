/**
Runtime: 328 ms, faster than 10.81% of C++ online submissions for Design HashMap.
Memory Usage: 50.4 MB, less than 98.67% of C++ online submissions for Design HashMap.
*/

class MyHashMap {
private:
    vector<pair<int, int>> map;
public:
    MyHashMap() {
        map.clear();
    }
    
    void put(int key, int value) {
        if(map.size() == 0){
            map.push_back({key, value});
        }
        else{
            int i;
            for(i = 0; i < map.size(); i++){
                if(map[i].first == key){
                    map[i].second = value;
                    break;
                }
            }
            if(i == map.size())
                map.push_back({key, value});
        }
    }
    
    int get(int key) {
        for(int i = 0; i < map.size(); i++){
            if(map[i].first == key){
                return map[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i;
        for(i = 0; i < map.size(); i++){
            if(map[i].first == key){
                break;
            }
        }
        if(i == map.size()) return;
        else{
            while(i < map.size()-1){
                map[i].first = map[i+1].first;
                map[i].second = map[i+1].second;
                i++;
            }
            map.resize(map.size()-1);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
