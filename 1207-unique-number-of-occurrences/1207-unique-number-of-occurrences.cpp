class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a : arr)
            mp[a]++;
        set<int> st;
        for(auto it : mp){
            if(st.count(it.second) != 0)
                return false;
            st.insert(it.second);
        }
        return true;
    }
};