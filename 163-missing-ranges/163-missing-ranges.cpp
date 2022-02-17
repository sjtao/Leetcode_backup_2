class Solution {
public:
    void compare(int n1, int n2, vector<string>& ans){
        int d = n2 - n1;
        string s;
        if(d <= 1)
            return;
        else if (d == 2)
            s = to_string(n2-1);
        else if(d > 2){
            s = to_string(n1+1) + "->" + to_string(n2-1);
        }
        ans.push_back(s);
        return;
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = nums.size();
        
        if(n == 0){
            if(lower == upper)
                ans.push_back(to_string(lower));
            else
                ans.push_back(to_string(lower) + "->" + to_string(upper));
            return ans;
        }
        
        if(lower < nums[0]){
            if(lower == nums[0]-1)
                ans.push_back(to_string(lower));
            else
                ans.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
            
        
        for(int i = 1; i < n; i++)
            compare(nums[i-1], nums[i], ans);
        
        if(nums[n-1] < upper){
            if(nums[n-1]+1 == upper)
                ans.push_back(to_string(upper));
            else
                ans.push_back(to_string(nums[n-1]+1) + "->" + to_string(upper));
        }
            
        return ans;
    }
};