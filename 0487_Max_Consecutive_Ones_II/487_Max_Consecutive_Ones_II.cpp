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

//Follow up question
/**
Runtime: 36 ms, faster than 70.91% of C++ online submissions for Max Consecutive Ones II.
Memory Usage: 36.2 MB, less than 26.97% of C++ online submissions for Max Consecutive Ones II.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        if(nums.size() == 1) return 1;
        
        int one = 0;
        int one_zero = 0;
        int mx = -1;
        for(int i : nums){
            if(i == 1){
                one ++;
                one_zero ++;
            }
            else{
                one_zero = one + 1;
                one = 0;
            }
            mx = max(mx, one_zero);
        }
 
        return mx;
    }
};
