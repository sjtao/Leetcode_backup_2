/**
Runtime: 4 ms, faster than 55.11% of C++ online submissions for Largest Number At Least Twice of Others.
Memory Usage: 10.9 MB, less than 25.04% of C++ online submissions for Largest Number At Least Twice of Others.
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int s = nums.size();
        if(s==1) return 0;
        
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int idx = -1;
        for(int i = 0; i < s; i++){
            int n = nums[i];
            if(n == mx1 || n == mx2) 
                continue;
            
            if(n > mx1){
                mx2 = mx1;
                mx1 = n;
                idx = i;
            }
            else if(n > mx2){
                mx2 = n;
            }
        }
        
        if(2 * mx2 <= mx1){
            return idx;
        }
        else{
            return -1;
        }

    }
};
