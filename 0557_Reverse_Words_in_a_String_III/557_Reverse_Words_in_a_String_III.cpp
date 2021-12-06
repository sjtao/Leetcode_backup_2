//Runtime: 92 ms, faster than 5.60% of C++ online submissions for Reverse Words in a String III.
//Memory Usage: 364.9 MB, less than 5.11% of C++ online submissions for Reverse Words in a String III.

class Solution {
public:
    string reverseWords(string s) {
        string r, temp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                reverse(temp.begin(), temp.end());
                r = r + temp;
                r = r + s[i];
                temp.clear();
            }
        }
        reverse(temp.begin(), temp.end());
        r = r + temp;
        return r;
    }
};


//Runtime: 8 ms, faster than 99.18% of C++ online submissions for Reverse Words in a String III.
//Memory Usage: 9.8 MB, less than 46.11% of C++ online submissions for Reverse Words in a String III.

class Solution {
public:
    string reverseWords(string s) {
        int st = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+st, s.begin()+i);
                st = i+1;
            }
        }
        reverse(s.begin()+st, s.end());
        return s;
    }
};

/**
Runtime: 24 ms, faster than 23.01% of C++ online submissions for Reverse Words in a String III.
Memory Usage: 16.2 MB, less than 10.79% of C++ online submissions for Reverse Words in a String III.
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
                    reverse(t.begin(), t.end());
                    par.push_back(t);
                    t = "";
                }
            }
            i++; 
        }
        
        if(t!= "")
            reverse(t.begin(), t.end());
            par.push_back(t);
            
        return par;
    }
    
    string reverseWords(string s) {
        string ans = "";  
        vector<string> par = parseString(s);
        int n = par.size();
        int i;
        for(i = 0; i<n; i++){
            ans += par[i] + ' ';
        }
        ans = ans.substr(0, ans.length()-1);
        return ans;
    }
};
