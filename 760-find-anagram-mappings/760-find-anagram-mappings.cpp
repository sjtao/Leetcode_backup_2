class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums1.size();
        for(int j = 0; j < n; ++j){
            mp[nums2[j]] = j;
        }
        vector<int> map(n, 0);
        for(int i = 0; i < n; i++){
            map[i] = mp[nums1[i]];
        }
        return map;
    }
};