class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> show(n+1, 1);
        for(int a : nums)
            show[a] = 0;
        for(int i = 0; i < n+1; i++){
            if(show[i] == 1)
                return i;
        }
        return -1;
    }
};