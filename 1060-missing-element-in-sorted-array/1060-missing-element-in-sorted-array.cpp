class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int d = nums[n-1] - nums[0] + 1 - n;
        if(k > d){
            return nums[n-1] + k - d;
        }
        
        int i = 1;
        int a = nums[0];
        while(k > 0){
            a++;
            if(a < nums[i])
                k--;
            else if(a == nums[i])
                i++;
        }
        
        return a;
    }
};