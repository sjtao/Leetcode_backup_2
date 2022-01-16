class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int presum = 0;
        int len = 0;
        unordered_map<int, int> indice;
        
        for(int i = 0; i < n; i++){
            presum += nums[i];
            if(presum == k)
                len = i+1;

            if(indice.find(presum - k) != indice.end())
                len = max(len, i - indice[presum-k]);

            if(indice.find(presum) == indice.end())
               indice[presum] = i;
        }
        
        return len;       
    }
};