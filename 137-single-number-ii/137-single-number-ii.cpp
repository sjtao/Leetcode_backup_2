class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        
        long tot = 0;
        for(int i : nums){
            tot += i;
            st.insert(i);
        }
        
        long sum = 0;
        for(auto i = st.begin(); i != st.end(); i++)
            sum += *i;
        
        return (3 * sum - tot) / 2;
    }
};