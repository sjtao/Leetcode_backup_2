class Solution {
public:
    int MN = 1000001;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1. brutal O(m+n)
        int m = nums1.size();
        int n = nums2.size();
        vector<int> num(m+n);
        int i = 0, j = 0, k = 0;
        while(k < m+n){
            int a = i == m ? MN : nums1[i];
            int b = j == n ? MN : nums2[j];
            if(a < b){
                num[k] = a;
                i++;
            }
            else{
                num[k] = b;
                j++;
            }
            k++;
        }
        double ans = 0;
        if((m+n) % 2){
            ans += num[(m+n)/2];
        }
        else{
            ans += 0.5 * (num[(m+n)/2] + num[(m+n)/2-1]);
        }
        
        return ans;
    }
};