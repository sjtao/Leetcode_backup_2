class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1, 1);
        for(int a : nums)
            arr[a] -= 1;
        
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            if(arr[i] == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};