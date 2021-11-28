/**
Runtime: 55 ms, faster than 19.72% of C++ online submissions for Max Consecutive Ones.
Memory Usage: 36.3 MB, less than 21.82% of C++ online submissions for Max Consecutive Ones.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int len = nums.size();
        int ans  = 0;
        int cons = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 1){//consecutive 1's in the array
                cons ++;
            }
            else{
                ans = max(ans, cons);
                cons = 0;
            }
        }
        return max(ans, cons);
    }
};
