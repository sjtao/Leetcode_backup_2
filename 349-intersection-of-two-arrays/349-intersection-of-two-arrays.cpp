class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1, st2;
        for(int n : nums1)
            st1.insert(n);
        
        for(int n : nums2){
            st2.insert(n);
        }
        
        vector<int> ans;
        
        for (auto itr = st1.begin(); itr != st1.end(); itr++){
            if(st2.find(*itr) != st2.end())
                ans.push_back(*itr);
        } 
        
        return ans;
    }
};