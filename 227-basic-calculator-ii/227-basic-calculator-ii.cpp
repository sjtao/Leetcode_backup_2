class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n == 0) return 0;
        
        int last = 0, res = 0;
        int i = 0;
        char sign = '+'; //plus, minus, multiply, divide
        while(i < n){
            if(isspace(s[i])){
                while(isspace(s[i]))
                    i++;
            }
            
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                sign = s[i++];
            
            else if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if(sign == '+' || sign == '-'){
                    res += last;
                    last = sign == '+' ? num : -num;
                }
                else if(sign == '*')
                    last *= num;
                else if(sign == '/')
                    last /= num;
            }
        }
        
       res += last;
        return res;
    }
};