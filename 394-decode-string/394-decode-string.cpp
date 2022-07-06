class Solution {
public:
    string decode(string& s, int& index){
        string result;
        while(index < s.length() && s[index] != ']'){
            if(!isdigit(s[index]))
                result += s[index++];
            else{
                int k = 0;
                while(index < s.length() && isdigit(s[index]))
                    k = k * 10 + (s[index++] - '0');
                index++; //ignore '['
                string d = decode(s, index);
                index++; //ignore ']'
                while(k > 0){
                    result += d;
                    k--;
                }
            }
        }
        return result;
    }
    
    string decodeString(string s) {
        int index = 0;
        return decode(s, index);
    }
};