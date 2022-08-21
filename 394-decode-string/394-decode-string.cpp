class Solution {
public:
    string decode(string&s, int& idx){
        string r = "";
        while(idx < s.length() && s[idx] != ']'){
            if(!isdigit(s[idx]))
                r += s[idx++];
            else{
                int k = 0;
                while(idx < s.length() && isdigit(s[idx]))
                    k = k * 10 + (s[idx++] - '0');
                idx++;//skip '['
                string d = decode(s, idx); 
                idx++;//skip ']'
                while(k > 0){
                    r += d;
                    k--;
                }
            }
        }
        return r;
    }
    string decodeString(string s) {
        int id = 0;
        return decode(s, id);
    }
};