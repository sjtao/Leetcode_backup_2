class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        vector<int> minarray(n);
        minarray[0] = nums[0];
        //0-i min element
        for(int i = 1; i < n; ++i){
            minarray[i] = min(minarray[i-1], nums[i]);
        }
        
        stack<int> s;
        for(int i = n-1; i>=0; --i){
            if(nums[i] <= minarray[i])
                continue;
            
            while(!s.empty() && s.top() <= minarray[i]){
                s.pop();
            } //find 13
            if(!s.empty() && s.top() < nums[i]){
                return true;
            } //find 2
            s.push(nums[i]);
        }
        return false;
    }
};