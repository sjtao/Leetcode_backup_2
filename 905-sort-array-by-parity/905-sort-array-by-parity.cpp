class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        int odd = n-1;
        for(int i = 0; i < odd; i++){
            while(i < odd && nums[i] % 2 == 1){
                swap(nums[i], nums[odd--]);
            }
        }
        
        return nums;
    }
};