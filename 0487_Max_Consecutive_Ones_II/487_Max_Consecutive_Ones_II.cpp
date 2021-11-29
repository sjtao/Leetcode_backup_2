/**
Runtime: 40 ms, faster than 53.12% of C++ online submissions for Max Consecutive Ones II.
Memory Usage: 37 MB, less than 11.19% of C++ online submissions for Max Consecutive Ones II.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        if(nums.size() == 1) return 1;
        
        int one = 0;
        vector<int> one_seg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                one_seg.push_back(one);
                one = 0;
            }
            else{
                one ++;
            }
        }
        one_seg.push_back(one);
        
        int mx = -1;
        if(one_seg.size() == 1){
            mx = one_seg[0];
        }
        else{
            for(int i = 0; i < one_seg.size()-1; i++){
                mx = max(one_seg[i]+one_seg[i+1]+1, mx);
            }
        }
 
        return mx;
    }
};
