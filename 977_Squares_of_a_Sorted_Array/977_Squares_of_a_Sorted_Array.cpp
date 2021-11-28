/**
Runtime: 52 ms, faster than 20.06% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 25.9 MB, less than 81.66% of C++ online submissions for Squares of a Sorted Array.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

/**
Runtime: 46 ms, faster than 25.62% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 25.7 MB, less than 95.48% of C++ online submissions for Squares of a Sorted Array.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        
        int l = 0;
        int r = len - 1;
        int c = r;
        while(l <= r){
            if(abs(nums[l]) > abs(nums[r])){
                ans[c] = nums[l]*nums[l];
                l++;
            }
            else{
                ans[c] = nums[r]*nums[r];
                r--;
            }
            c--;
        }
        return ans;
    }
};
