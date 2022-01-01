/**
Runtime: 4 ms, faster than 90.57% of C++ online submissions for Multiply Strings.
Memory Usage: 6.8 MB, less than 62.21% of C++ online submissions for Multiply Strings.
*/

class Solution {
public:
    

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.length();
        int n2 = num2.length();
        if(n1 < n2) return multiply(num2, num1);
        
        vector<int> sum(n1+n2, 0);
        int k, t;
        for(int i = n1-1; i >= 0; i--){
            k = n2 + i;
            for(int j = n2-1; j >= 0; j--){
                t = sum[k] + (num1[i] - '0') * (num2[j] - '0');
                sum[k--] = t % 10;
                sum[k] += t / 10;
            }
        }
        
        int nz = 0;
        while(sum[nz] == 0) nz++;
        string ans = "";
        char c;
        for(int i = nz; i < n1+n2; i++){
            c = sum[i] + '0';
            ans += c;
        }
        return ans;
    }
};
