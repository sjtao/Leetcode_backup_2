class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(int& a : arr){
            if(st.count(2*a) || (a%2==0 && st.count(a/2)))
                return true;
            st.insert(a);
        }
        
        return false;
    }
};