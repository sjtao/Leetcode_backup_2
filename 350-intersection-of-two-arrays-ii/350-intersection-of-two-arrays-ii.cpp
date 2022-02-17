class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 > n1) 
            return intersect(nums2, nums1);
        
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int n : nums1)
            mp[n]++;
        
        for(int n : nums2){
            if(mp.find(n)!=mp.end() && mp[n] != 0){
                ans.push_back(n);
                mp[n]--;
            }
        }
        
        return ans;
    }
};