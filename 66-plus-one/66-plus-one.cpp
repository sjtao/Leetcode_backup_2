class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0 && carry > 0; --i){
            int s = digits[i] + carry;
            digits[i] = s % 10;
            carry = s / 10;
        }
        if(carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};