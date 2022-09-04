class Solution {
private:
    int n;
    vector<vector<int>> res;
public:
    void permhelper(vector<int>& nums, int d){
        if(d == n){
            res.push_back(nums);
            return;
        }

        for(int i = d; i < n; i++){
            swap(nums[d], nums[i]);
            permhelper(nums, d+1);
            swap(nums[i], nums[d]);
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();     
        permhelper(nums,  0);
        
        return res;
    }
};