class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 1;
        for(int n : nums){
            if(n == 0)
                return 0;
            else if(n < 0)
                neg *= -1;
        }
  
        return neg;
    }
};