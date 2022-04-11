class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mx = 0;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(i <= j){
                if(nums1[i] <= nums2[j]){
                    mx = max(mx, j-i);
                    j++;
                }
                else{
                    i++;
                }
            }
            else
                j++;
        }
        return mx;
    }
};