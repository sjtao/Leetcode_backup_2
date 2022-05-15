class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        //n = a0 + a1 * 26 + a2 * 26^2 + ...
        int n = columnNumber;
        while(n > 0){
            n -= 1;
            int a = n % 26;
            char c = a + 'A';
            ans = c + ans;
            n /= 26;
        }
        
        
        return ans;
    }
};