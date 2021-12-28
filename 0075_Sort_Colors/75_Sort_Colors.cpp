/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 21.25% of C++ online submissions for Sort Colors.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 0, h = n-1;
        while(m <= h){
            if(nums[m] == 0)
                swap(nums[m++], nums[l++]);
            else if(nums[m] == 1)
                m++;
            else
                swap(nums[m], nums[h--]);
        }
        return;
        
    }
};
