/**
Runtime: 24 ms, faster than 50.18% of C++ online submissions for Jump Game II.
Memory Usage: 16.3 MB, less than 70.95% of C++ online submissions for Jump Game II.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int step = 1;
        int i = 0;
        int far;
        while(i < n-1){
            far = i + nums[i];
            if(far >= n-1)
                break;
            
            //find the max number in [i+1, far]
            int mx = -1;
            int id;
            for(int j = i+1; j <= far; j++){
                if(mx <= j+nums[j]){
                    mx = j+nums[j];
                    id = j;
                }
            }
            i = id;
            step ++;
        }
        
        return step;
    }
};
