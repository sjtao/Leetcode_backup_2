/**
Runtime: 12 ms, faster than 27.82% of C++ online submissions for Reverse Words in a String.
Memory Usage: 20.7 MB, less than 23.31% of C++ online submissions for Reverse Words in a String.
*/

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
