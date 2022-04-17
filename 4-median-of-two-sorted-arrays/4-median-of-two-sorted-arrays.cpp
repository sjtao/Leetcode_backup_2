class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums;
        for(int p : nums1)
            nums.push_back(p);
        for(int p : nums2)
            nums.push_back(p);
        
        sort(nums.begin(), nums.end());
        return (m+n)%2 == 0 ? (nums[(m+n)/2-1]+nums[(m+n)/2])/2.0 : nums[(m+n)/2]*1.0;
    }
};