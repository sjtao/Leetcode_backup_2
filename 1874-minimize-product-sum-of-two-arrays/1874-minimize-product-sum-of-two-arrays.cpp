class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
       //counting sort
        vector<int> count1(101,0), count2(101,0);
        for(int n : nums1)
            count1[n]++;
        for(int n : nums2)
            count2[n]++;
        
        int p1 = 0, p2 = 100, sum = 0;
        while(p1 < 101 && p2 > 0){
            while(p1 < 101 && count1[p1] == 0)
                p1++;
            while(p2 > 0 && count2[p2] == 0)
                p2--;
            if(p1 == 101 || p2 == 0)
                break;
            
            int r = min(count1[p1], count2[p2]);
            sum += r * (p1 * p2);
            count1[p1] -= r;
            count2[p2] -= r;
        }

        return sum;
    }
};