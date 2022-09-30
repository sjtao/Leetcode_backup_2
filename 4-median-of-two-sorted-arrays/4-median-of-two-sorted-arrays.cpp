class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int t = (m+n)/2;
        int r = (m+n)%2;
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < m; i++)
            q.push(nums1[i]);
        for(int i = 0; i < n; i++)
            q.push(nums2[i]);
        
        int k = 0;
        while(k < t-1+r){
            q.pop();
            k++;
        }
        
        int a = q.top();
        q.pop();
        int b = a;
        if(r==0){
            b = q.top();
            q.pop();
        }
        
        return (a + b) / 2.0;
    }
};