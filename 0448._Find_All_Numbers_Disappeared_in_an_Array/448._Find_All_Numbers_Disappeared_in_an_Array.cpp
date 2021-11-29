/**
Runtime: 96 ms, faster than 20.43% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 44.8 MB, less than 14.37% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> missed;
        for(int n: nums){
            mp[n]++;
        }
        int i = 1;
        while(i <= nums.size()){
            if(mp.find(i) == mp.end()){
                missed.push_back(i);
            }
            i++;
        }
        return missed;        
    }
};

/**
Runtime: 48 ms, faster than 79.26% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 33.8 MB, less than 34.51% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> missed;
        for(int i = 0; i < len; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }
        for(int i = 1; i <= len; i++){
            if(nums[i-1] > 0){
                missed.push_back(i);
            }
        }

        return missed;        
    }
};
