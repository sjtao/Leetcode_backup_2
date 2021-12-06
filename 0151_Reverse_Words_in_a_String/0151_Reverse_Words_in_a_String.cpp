class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i = 0;
        string t = "";
        while(i < n){
            if(s[i] != ' '){
                t += s[i];
            }
            else{
                if(t!= ""){
                    if(ans == "")
                        ans = t;
                    else
                        ans = t + " " + ans;
                    t = "";
                }
            }
            i++; 
        }
        
        if(t!= ""){
            if(ans == "")
                ans = t;
            else
                ans = t + " " + ans;
        }
            
        return ans;
    }
};
