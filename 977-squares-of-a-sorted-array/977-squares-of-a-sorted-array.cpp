class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq(n);
        int left = 0, right = n-1;
        for(int i = n-1; i >= 0; i--){
            //nums: non-decreasing order
            int a;
            if(abs(nums[right]) >= abs(nums[left])){
                a = nums[right];
                right--;
            }
            else{
                a = nums[left];
                left++;
            }
            sq[i] = a * a;
        }
        return sq;
    }
};