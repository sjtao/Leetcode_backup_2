class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        vector<int> ans;
        while(i >= 0){
            int sum = digits[i] + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
            i--;
        }
        if(carry)
            ans.push_back(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};