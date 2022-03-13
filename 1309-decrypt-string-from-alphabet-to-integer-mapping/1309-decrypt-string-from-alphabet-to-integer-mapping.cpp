class Solution {
public:
    string freqAlphabets(string s) {
        vector<int> num;
        int n = s.length();
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '#'){
                num.push_back((s[i-2]-'0')*10+(s[i-1] -'0'));
                i = i-2;
            }
            else{
                num.push_back(s[i]-'0');
            }
        }
        
        string a = "";
        for(int i = num.size()-1; i >= 0; i--){
            a += (num[i]-1+'a');
        }
        
        return a;
    }
};