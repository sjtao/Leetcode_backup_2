//Runtime: 744 ms, faster than 6.89% of C++ online submissions for Two Sum.
//Memory Usage: 10.1 MB, less than 80.30% of C++ online submissions for Two Sum.
//O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        bool find = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if((i != j) && (nums[i] + nums[j] == target)){
                    index.push_back(i);
                    index.push_back(j);
                    find = 1;
                    break;
                }    
            }
            if (find) break;
        }
        return index;
    }
};



//Runtime: 4 ms, faster than 99.54% of C++ online submissions for Two Sum.
//Memory Usage: 10.5 MB, less than 61.39% of C++ online submissions for Two Sum.
//O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> s, ind, ans;
        s = nums;
     
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            if(nums[l] + nums[r] == target){
                ind.push_back(nums[l]);
                ind.push_back(nums[r]);
                break;
            }
            else if(nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(s[i] == ind[0] || s[i] == ind[1]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
