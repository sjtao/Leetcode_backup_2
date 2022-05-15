class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq(n);
        int left = 0, right = n-1;
        for(int i = n-1; i >= 0; i--){
            //nums: non-decreasing order
            if(abs(nums[right]) >= abs(nums[left])){
                sq[i] = nums[right] * nums[right];
                right--;
            }
            else{
                sq[i] = nums[left] * nums[left];
                left++;
            }
        }
        return sq;
    }
};