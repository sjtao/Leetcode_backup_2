class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flip = 0, unflip = 0;
        int mx = 0;
        for(int n : nums){
            flip = n == 1 ? flip+1 : unflip+1;
            unflip = n == 1 ? unflip + 1 : 0;
            mx = max(mx, max(flip, unflip));
        }
        return mx;
    }
};