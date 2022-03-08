class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int> ans(n1, 0);
        unordered_map<int,int> mp;
        stack<int> s;
        s.push(nums2[0]);
        for(int i = 1; i < n2; ++i){
           while(!s.empty() && nums2[i] > s.top()){
               mp[s.top()] = nums2[i];
               s.pop();
           }
            s.push(nums2[i]);
        }
        
        while(!s.empty()){
            mp[s.top()] = -1;
            s.pop();
        }
        
        for(int i = 0; i < n1; ++i){
            ans[i] = mp[nums1[i]];
        }
        
        return ans;
    }
};