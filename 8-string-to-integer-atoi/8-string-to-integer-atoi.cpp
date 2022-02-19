class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int n = s.length();
        string r = "";
        for(int i = 0; i < n; i++){
            if(r.length() == 0){
                if(s[i] == ' ')
                    continue;
                else if(s[i] == '+' || s[i] == '-' || isdigit(s[i]))
                    r += s[i];
                else if(!isdigit(s[i]))
                    break;
            }
            else if(r.length() > 0){
                if(isdigit(s[i]))
                    r += s[i];
                else
                    break;
            }    
        }
        
        int sign = 1;
        for(int i = 0; i < r.length(); i++){
            if(i == 0 && r[i] == '-')
                sign = -1;
            else if(i == 0 && r[i] == '+')
                continue;
            else{
                int d = r[i] - '0';
                if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 &&  d > INT_MAX % 10))
                    return sign == 1 ? INT_MAX : INT_MIN;
                
                ans = ans * 10 + d;
            }
        }     
        return sign*ans;
    }
};