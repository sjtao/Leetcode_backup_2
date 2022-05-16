class MyHashSet {
public:
    list<int> set;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))
            set.push_back(key);
    }
    
    void remove(int key) {
        set.remove(key);
    }
    
    bool contains(int key) {
        for(auto i = set.begin(); i != set.end(); i++){
            if(*i == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */