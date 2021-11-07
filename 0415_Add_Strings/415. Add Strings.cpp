//Runtime: 12 ms, faster than 36.89% of C++ online submissions for Add Strings.
//Memory Usage: 56.1 MB, less than 9.58% of C++ online submissions for Add Strings.

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length() - 1;
        int n2 = num2.length() - 1;
        string ans = "\0";
        
        int carry = 0;
        int d1, d2, s;
        char t;
        while(n1 >= 0 || n2 >= 0){
            if(n1 < 0){
                d1 = 0;
            }
            else{
                d1 = num1[n1] - '0';
            }
            
            if(n2 < 0){
                d2 = 0;
            }
            else{
                d2 = num2[n2] - '0';
            }
            
            s = d1 + d2 + carry;
            t = s % 10 + '0';
            ans = t + ans;
            carry = s / 10;
            
            n1 --;
            n2 --;
        }
        
        if(carry){
            t = carry + '0';
            ans = t + ans;
        }
         
        return ans;
    }
};

//Runtime: 4 ms, faster than 79.93% of C++ online submissions for Add Strings.
//Memory Usage: 6.6 MB, less than 98.14% of C++ online submissions for Add Strings.
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length() - 1;
        int n2 = num2.length() - 1;
        string ans;
        ans.reserve(max(n1,n2)+2);
        
        int carry = 0;
        int d1, d2, s;
        while(n1 >= 0 || n2 >= 0){
            if(n1 < 0){
                d1 = 0;
            }
            else{
                d1 = num1[n1] - '0';
            }
            
            if(n2 < 0){
                d2 = 0;
            }
            else{
                d2 = num2[n2] - '0';
            }
            
            s = d1 + d2 + carry;
            ans.push_back(s % 10 + '0');
            carry = s / 10;
            
            n1 --;
            n2 --;
        }
        
        if(carry){
            ans.push_back(carry+'0');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
