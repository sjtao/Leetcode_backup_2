class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /**
        //TLE error
        int n = nums.size();
        if(n <= k) return n;
        
        int i = 0, j = 0;
        int zero;
        int longest = 0;
        while(i < n && j < n){
            zero = 0;
            for(j = i; j < n; j++){
                if(nums[j] == 0)
                    zero ++;
                if(zero > k) break;
            }
            longest = max(longest, j-i);
            i++;            
        }
       return longest;
       */
        //slide window
        int n = nums.size();
        int left = 0, right;
        for(right = 0; right < n; right++){
            if(nums[right]==0)
                k--;
            if(k < 0){
                k += (1-nums[left]); //nums[left] = 1, k not changed, left++, else k -> 0
                left++;
            }
        }
        return right - left;
    }
};