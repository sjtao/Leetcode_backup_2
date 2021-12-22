/**
Runtime: 204 ms, faster than 18.70% of C++ online submissions for Design HashSet.
Memory Usage: 39.2 MB, less than 99.25% of C++ online submissions for Design HashSet.
*/

class MyHashSet {
private:
    vector<int> set;
public:
    MyHashSet() {
        set.clear();
    }
    
    void add(int key) {
        if(!contains(key)){
            set.push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            set.erase(find(set.begin(), set.end(), key));
        }
    }
    
    bool contains(int key) {
        if(find(set.begin(), set.end(), key) == set.end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
