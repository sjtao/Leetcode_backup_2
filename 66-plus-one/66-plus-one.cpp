class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        digits[n-1] += 1;
        if(digits[n-1] < 10)
            return digits;
        
        int carry = digits[n-1] / 10;
        digits[n-1] %= 10;
        
        for(int i = n-2; i >= 0; i--){
            digits[i] += carry;
            carry = digits[i] / 10;
            if(carry == 0)
                return digits;
            digits[i] %= 10;
        }
        
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};