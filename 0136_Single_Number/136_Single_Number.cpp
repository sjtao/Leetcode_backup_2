//Runtime: 16 ms, faster than 87.89% of C++ online submissions for Single Number.
//Memory Usage: 16.8 MB, less than 99.20% of C++ online submissions for Single Number.
//sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < nums.size()-1){
            if(nums[i] == nums[i+1]){
                i += 2;
            }
            else{
                return nums[i];
            }
        }
        
        return nums[i];
    }
};

//Runtime: 12 ms, faster than 97.69% of C++ online submissions for Single Number.
//Memory Usage: 17 MB, less than 49.30% of C++ online submissions for Single Number.
//bitwise operation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
