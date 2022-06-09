class Solution {
public:
    vector<int> ans;
    
    void binary(vector<int>& nums, int target, int l, int r){
        if(l > r) return;
        
        int m = l + (r - l) / 2;
        if(nums[m] == target){
            binary(nums, target, l, m-1);
            ans.push_back(m);
            binary(nums, target, m+1, r);
        }
        else if(nums[m] > target)
            binary(nums, target, l, m-1);
        else
            binary(nums, target, m+1, r);
        
        return;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end()); //O(nlogn)
        binary(nums, target, 0, n-1);
        return ans;
    }
};