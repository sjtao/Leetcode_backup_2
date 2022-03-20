class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length();
        int nb = b.length();
        int carry = 0;
        int p1 = na-1, p2 = nb-1;
        string ans = "";
        while(p1 >= 0 || p2 >= 0 || carry > 0){
            int aa = p1 >= 0 ? a[p1--]-'0' : 0;
            int bb = p2 >= 0 ? b[p2--]-'0' : 0;
            int s = aa ^ bb ^ carry;
            carry = (aa & bb) | (aa & carry) | (bb & carry);
            ans = (char)(s+'0') + ans;
        }
        return ans;
    }
};