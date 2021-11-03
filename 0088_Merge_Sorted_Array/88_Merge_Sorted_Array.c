//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
//Memory Usage: 9.2 MB, less than 30.61% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        
        for(int i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
        return;
    }
};
