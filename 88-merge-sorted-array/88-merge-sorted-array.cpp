class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){ nums1 = nums2; return;}
        if(n == 0) return;
            
        int p1 = m-1;
        int p2 = n-1;
        int i = m+n-1;
        while(i>=0){
            int a = p1 >= 0 ? nums1[p1] : INT_MIN;
            int b = p2 >= 0 ? nums2[p2] : INT_MIN;
            
            if(a < b){
                nums1[i] = b;
                p2--;
            }
            else{
                nums1[i] = a;
                p1--;
            }
            i--;
        }

        return;
    }
};