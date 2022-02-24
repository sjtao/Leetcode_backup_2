class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        bool f = st.count(val) == 0;
        st.insert(val);
        return f;
    }
    
    bool remove(int val) {
        auto it = st.find(val);
        if(it == st.end())
            return false;

        st.erase(val);
        return true;
    }
    
    int getRandom() {

        return *next(st.begin(),rand() % st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */