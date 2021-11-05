//Runtime: 4 ms, faster than 60.45% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.
//Memory Usage: 8.3 MB, less than 91.33% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.

class Solution {
public:
    bool xGreaterHelper(vector<int>& nums, int x){
        int s = nums.size();
        bool xx = 0;
        int d = 0;
        for(int i = 0; i < s; i++){
            if(nums[i] >= x){
                d++;
            }
        }
        if(x == d) xx = 1;
        
        return xx;
    }
    
    int specialArray(vector<int>& nums) {
        int s = nums.size();
        bool find = 0;
        while(s >= 0){
            if(xGreaterHelper(nums, s)){
                find = 1;
                break;
            }
            else
            {
                s--;
            }
        }
        if(!find) s = -1;
        return s;
    }
};
