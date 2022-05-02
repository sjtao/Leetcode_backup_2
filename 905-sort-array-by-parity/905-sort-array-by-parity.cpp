class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        int odd = n-1;
        for(int i = 0; i < n-1; i++){
            while(i < odd && nums[i] % 2 == 1){
                swap(nums[i], nums[odd--]);
            }
            if(i >= odd)
                break;
        }
        
        return nums;
    }
};