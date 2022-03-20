class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;
        int s;
        for(int i = n-1; i >= 0; --i){
            s = num[i] + carry + k % 10;
            k /= 10;
            num[i] = s % 10;
            carry = s / 10;
        }
        
        while(k || carry){
            s = carry + k % 10;
            k /= 10;
            carry = s/10;
            num.insert(num.begin(), s%10);
        }

        return num; 
    }
};