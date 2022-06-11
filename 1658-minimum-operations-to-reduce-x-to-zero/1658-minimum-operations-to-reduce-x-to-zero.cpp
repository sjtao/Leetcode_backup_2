class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int oper = INT_MAX;
        
        int sum = 0;
        for(int a : nums)
            sum += a;
        
        int left = 0;
        for(int right = 0; right < n; right++){
            sum -= nums[right];
            while(sum < x && left <= right){
                sum += nums[left++];
            }
            if(sum == x)
                oper = min(oper, n - (right - left + 1));
        }
        
        return oper == INT_MAX ? -1 : oper;
    }
};