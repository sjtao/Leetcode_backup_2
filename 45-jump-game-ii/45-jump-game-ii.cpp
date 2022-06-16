class Solution {
public:

    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, cur = 0, far = 0;
        for(int i = 0; i < n-1; i++){
            far = max(far, i + nums[i]);
            if(i == cur){
                jump++;
                cur = far;
            }
        }
        return jump;
    }
};