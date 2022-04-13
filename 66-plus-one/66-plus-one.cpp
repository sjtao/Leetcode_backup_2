class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int s = 0;
        int n = digits.size();
        vector<int> sum;
        for(int i = n-1; i >= 0; i--){
            s = carry + digits[i];
            sum.push_back(s % 10);
            carry = s / 10;
        }
        if(carry)
            sum.push_back(carry);
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};