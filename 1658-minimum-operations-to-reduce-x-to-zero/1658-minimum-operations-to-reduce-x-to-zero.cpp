class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> pre, suf;
        int sum = 0;
        int oper = INT_MAX;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            pre[sum] = i;
            if(sum == x)
                oper = min(oper, i+1);
        }
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            sum += nums[i];
            suf[sum] = i;
            if(sum == x)
                oper = min(oper, n-i);
        }
        
        for(auto it : pre){
            if(suf.find(x-it.first) != suf.end() && suf[x-it.first] > it.second){
                oper = min(oper, n - suf[x-it.first] + it.second + 1);
            }
        }
        return oper == INT_MAX ? -1 : oper;
    }
};