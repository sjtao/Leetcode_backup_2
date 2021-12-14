/**
Runtime: 4 ms, faster than 88.09% of C++ online submissions for Intersection of Two Arrays II.
Memory Usage: 10.4 MB, less than 51.81% of C++ online submissions for Intersection of Two Arrays II.
*/

class Solution {

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> mp;
        vector<int> r;
        
        for(int n : nums1)
            mp[n]++;
        
        for(auto n: nums2){
            if(mp.find(n) != mp.end()){
                if(mp[n] > 0){
                    mp[n]--;
                    r.push_back(n);
                }
            }
        }
        
        return r;
    }
};
