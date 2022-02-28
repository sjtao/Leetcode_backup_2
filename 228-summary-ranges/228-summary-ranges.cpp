class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0) return ans;
        //no duplicates
        int start = nums[0], end = start;
        string s = "";
        for(int i = 1; i < n; i++){
            if(nums[i] >  nums[i-1] + 1){
                if(end == start)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(end));
                
                start = nums[i];
                end = start;
            }
            else if(nums[i] == nums[i-1] +1){
                end = nums[i];
            }
        }
        
        end = nums[n-1];
        if(end == start)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(end));
        
        return ans;
    }
};