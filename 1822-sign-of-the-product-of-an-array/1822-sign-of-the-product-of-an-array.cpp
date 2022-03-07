class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(int n : nums){
            if(n == 0)
                return 0;
            else if(n < 0)
                neg++;
        }
        if(neg % 2 == 1) return -1; 
        return 1;
    }
};