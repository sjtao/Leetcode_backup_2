class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        
        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + nums[i-1];
        
        int pivot = 1;
        while(pivot <= n){
            if(sum[pivot-1] != sum[n] - sum[pivot])
                pivot++;
            else
                return pivot-1;
        }
        
        return -1;
    }
};