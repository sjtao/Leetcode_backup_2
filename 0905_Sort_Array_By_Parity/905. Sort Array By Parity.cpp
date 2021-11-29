/**
Runtime: 8 ms, faster than 82.29% of C++ online submissions for Sort Array By Parity.
Memory Usage: 16.3 MB, less than 51.92% of C++ online submissions for Sort Array By Parity.
*/

class Solution {
public:
    void swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums;
        int l = 0;
        int r = len-1;
        while(l <= r){
            int ls = nums[l] % 2; //0, 1
            int rs = nums[r] % 2; //0, 1
            
            if(ls == 0){
                l++;
                if(rs == 1){
                    r--;
                }
            }
            else if(ls == 1){
                if(rs == 0){
                    swap(nums[l], nums[r]);
                    l++;
                }
                r--;
            }      
        }
        
        return nums;
    }
};
