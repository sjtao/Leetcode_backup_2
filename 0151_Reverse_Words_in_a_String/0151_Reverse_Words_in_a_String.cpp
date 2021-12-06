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


/**
Runtime: 4 ms, faster than 82.98% of C++ online submissions for Reverse Words in a String.
Memory Usage: 8.4 MB, less than 28.76% of C++ online submissions for Reverse Words in a String.
*/

class Solution {
public:
    
    vector<string> parseString(string s){
        vector<string> par;
        int n = s.length();
        int i = 0;
        string t = "";
        while(i < n){
            if(s[i] != ' '){
                t += s[i];
            }
            else{
                if(t!= ""){
                    par.push_back(t);
                    t = "";
                }
            }
            i++; 
        }
        
        if(t!= "")
            par.push_back(t);
            
        return par;
    }
    
    string reverseWords(string s) {
        string ans = "";  
        vector<string> par = parseString(s);
        int n = par.size();
        int i;
        for(i = n-1; i>=0; i--){
            ans += par[i] + ' ';
        }
        ans = ans.substr(0, ans.length()-1);
        return ans;
    }
};
