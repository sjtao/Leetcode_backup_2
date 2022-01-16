class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> missnum(n, 0);
       
        for(int i = 1; i < n; ++i){
            missnum[i] = missnum[i-1] + nums[i] - nums[i-1] - 1;
        }
        
        int ans;
        
        if(k > missnum[n-1]) 
            ans = nums[n-1] + k - missnum[n-1];
        else{
            int l = 0, r = n-1, m;
            while(l < r){
                m = l + (r - l)/2;
                if(missnum[m] < k) l = m+1;
                else r = m;
            }
            ans = nums[l-1] + k - missnum[l-1];
        }
        
        
        return ans;
        
    }
};