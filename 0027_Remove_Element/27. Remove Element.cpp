/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
Memory Usage: 8.6 MB, less than 92.62% of C++ online submissions for Remove Element.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //two pointers from the same direction
        // j is always ahead of i
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
Memory Usage: 8.7 MB, less than 92.62% of C++ online submissions for Remove Element.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //two pointers from the different direction
        int len = nums.size();
        int l = 0;
        int r = len-1;
        int cnt = 0;
        while(l <= r){
            if(nums[r] == val){
                cnt ++;
                r--;
            }
            else{
                if(nums[l] == val){
                    nums[l] = nums[r];
                    nums[r] = nums[l];
                    cnt++;
                    r--;
                    l++;
                }
                else{
                    l++;
                }
            }
        }
       
        return len-cnt;
    }
};
