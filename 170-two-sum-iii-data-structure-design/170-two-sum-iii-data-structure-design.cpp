class TwoSum {
    
public:
    unordered_map<int,int> mp;
    TwoSum() {
        mp.clear();
    }
    
    void add(int number) {
        mp[number]++;
    }
    
    bool find(int value) {
        for(auto it:mp){
            int i = it.first;
            if((value == INT_MIN && i > 0) || (value == INT_MAX && i < 0))
                continue;
            int j = value - it.first;
            if((i == j && it.second > 1) || (i != j && mp.find(j) != mp.end()))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */