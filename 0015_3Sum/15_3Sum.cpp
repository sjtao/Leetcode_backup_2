/**
Runtime: 48 ms, faster than 98.15% of C++ online submissions for 3Sum.
Memory Usage: 20.3 MB, less than 52.64% of C++ online submissions for 3Sum.
*/

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
           
            vector<int> temp(3, 0);
            temp[0] = nums[i];
            
            int j = i+1;
            int k = n-1;
            int target = -nums[i];
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    temp[1] =  nums[j];   
                    temp[2] =  nums[k]; 
                    ans.push_back(temp);
                    while(j < k && nums[j] == temp[1]) j++;
                    while(j < k && nums[k] == temp[2]) k--;     
                }
            }
        }
        return ans;
    }
};
