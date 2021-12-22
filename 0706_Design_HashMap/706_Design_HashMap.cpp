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

/**
Runtime: 116 ms
Memory Usage: 208.3 MB
*/
class MyHashMap {
private:
    int map[1000001];
public:
    MyHashMap() {
        fill(map, map+1000001, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};

/**
Runtime: 100 ms, faster than 93.59% of C++ online submissions for Design HashMap.
Memory Usage: 55.7 MB, less than 59.65% of C++ online submissions for Design HashMap.
*/
class MyHashMap {
public:
    const static int size = 1000;
    vector<vector<int>> map;
    
    MyHashMap() {
        map.resize(size+1, vector<int>());
    }
    
    void put(int key, int value) {
        //hashing
        int h = key / size;
        int r = key % size;
        if(map[h].size() == 0)
            map[h].resize(size, -1);
        map[h][r] = value;
    }
    
    int get(int key) {
        int h = key / size;
        int r = key % size;
        if(map[h].size() == 0) return -1;
        return map[h][r];
    }
    
    void remove(int key) {
        int h = key / size;
        int r = key % size;
        if(map[h].size() == 0) return;
        map[h][r] = -1;
    }
};
