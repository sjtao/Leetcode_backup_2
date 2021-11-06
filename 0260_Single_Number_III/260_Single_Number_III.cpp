
//Runtime: 12 ms, faster than 42.79% of C++ online submissions for Single Number III.
//Memory Usage: 10.3 MB, less than 27.03% of C++ online submissions for Single Number III.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                count[i] ++;
                count[i+1] ++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(count[i] == 0){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
        
    }
};

//Runtime: 12 ms, faster than 42.79% of C++ online submissions for Single Number III.
//Memory Usage: 9.8 MB, less than 93.24% of C++ online submissions for Single Number III.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-1){
            if(nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
                //find += 1;
                i+=1;
            }
            else
            {
                i+=2;
            }
        }
 
        if (i == nums.size()-1) ans.push_back(nums[i]);
        return ans;
    }
};


//Runtime: 8 ms, faster than 85.25% of C++ online submissions for Single Number III.
//Memory Usage: 9.8 MB, less than 99.94% of C++ online submissions for Single Number III.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int find = 0;
        while(i < nums.size()-1){
            if(nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
                find += 1;
                i+=1;
            }
            else
            {
                i+=2;
            }
        }
        if (find == 1) ans.push_back(nums[i]);
        return ans;
    }
};

