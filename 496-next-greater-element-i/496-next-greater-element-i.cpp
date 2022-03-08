class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1, 0);
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n2; ++i)
            mp[nums2[i]] = i;
        
        for(int i = 0; i < n1; ++i){
            if(mp.find(nums1[i]) == mp.end())
                ans[i] = -1;
            
            int j = mp[nums1[i]] + 1;
            for(; j < n2; ++j){
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
            
            if(j == n2)
                ans[i] = -1;
        }
        
        return ans;
    }
};