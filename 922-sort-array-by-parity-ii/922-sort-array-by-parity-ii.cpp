class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> parity(n);
        int even = 0;
        int odd = 1;
        
        for(int i = 0; i < n; i ++){
            if(nums[i] % 2 == 0){
                parity[even] = nums[i];
                even += 2;
            }
            else{
                parity[odd] = nums[i];
                odd += 2;
            }
        }
            
        
        return parity;
    }
};