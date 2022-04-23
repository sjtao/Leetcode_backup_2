class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int na = a.length();
        int nb = b.length();
        int n = max(na, nb);
        
        string ans = "";
        int carry = 0;
        for(int i = 0; i < n; i++){
            int v1 = i >= na ? 0 : a[i]-'0';
            int v2 = i >= nb ? 0 : b[i]-'0';
            int s = v1 + v2 + carry;
            ans += to_string(s%2);
            carry = s / 2;
        }
        if(carry)
            ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};