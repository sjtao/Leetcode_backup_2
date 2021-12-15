//Time Limit Exceeded

class Solution {
public:
    int last;
    bool JumpHelper(vector<int>& nums, int pos){
        
        if(pos == last)
            return true;
        
        int next = min(pos + nums[pos], last);
        for(int i = pos+1; i <= next; i++){
            if(JumpHelper(nums, i)){
                return true;
            }
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        //Backtracking
        last = nums.size()-1;
        return JumpHelper(nums, 0);
    }
};

/**
Runtime: 244 ms, faster than 18.55% of C++ online submissions for Jump Game.
Memory Usage: 48.7 MB, less than 14.67% of C++ online submissions for Jump Game.
*/

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        //DP
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;
        for(int i = n-1; i> 0; i--){
            int next = i-1 + nums[i-1];
            if(next >= i){
                for(int j = i; j <= next; j++){
                    if (dp[j] == true){
                        dp[i-1] = true;
                        break;
                    }
                        
                }
            }
        }
        return dp[0];
    }
};
