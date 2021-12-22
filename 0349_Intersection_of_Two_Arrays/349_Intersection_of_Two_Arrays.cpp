/**
Runtime: 4 ms, faster than 89.58% of C++ online submissions for Intersection of Two Arrays.
Memory Usage: 10.4 MB, less than 52.21% of C++ online submissions for Intersection of Two Arrays.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int n : nums1)
            st.insert(n);
        
        vector<int> ans;
        for(int n : nums2){
            if(st.count(n) > 0 && find(ans.begin(), ans.end(), n) == ans.end())
                ans.push_back(n);
        }
        
        return ans;
    }
};
