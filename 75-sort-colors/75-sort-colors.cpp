class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        
        int zero = 0;
        int two = n-1;
        
        for(int i = 0; i < n; ++i){
            if(i == 0 && nums[i] == 0){
                zero++;
                continue;
            }
            if(nums[i] == 0){
                nums[i] = nums[zero];
                nums[zero] = 0;
                zero++;
            }
        }
        
        for(int i = n-1; i >= zero; --i){
            if(i == n-1 && nums[i] == 2){
                two--;
                continue;
            }
            if(nums[i] == 2){
                nums[i] = nums[two];
                nums[two] = 2;
                two--;
            }
        }
        
        //for(int i = zero; i <= two; i++)
        //    nums[i] = 1;
        
        return;
    }
};