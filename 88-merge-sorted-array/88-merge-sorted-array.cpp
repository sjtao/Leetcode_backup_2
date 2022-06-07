class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int k = m+n-1;
        while(k >= 0){
            int a = p1 >= 0 ? nums1[p1] : INT_MIN;
            int b = p2 >= 0 ? nums2[p2] : INT_MIN;
            if(a >= b){
                nums1[k] = a;
                p1--;
            }
            else{
                nums1[k] = b;
                p2--;
            }
            k--;
        }
        return;
    }
};