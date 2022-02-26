class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        /*
        //if don't distinguish duplicates
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
        */
        //if distinguish duplicates
        unordered_map<int,vector<int>> mp;
        int n = nums1.size();
        for(int j = 0; j < n; ++j){
            mp[nums2[j]].push_back(j);
        }
        vector<int> map(n, 0);
        for(int i = 0; i < n; i++){
            map[i] = mp[nums1[i]].front();
            mp[nums1[i]].erase(mp[nums1[i]].begin());
        }
        return map;
    }
};