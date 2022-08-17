class Solution {
public:
    vector<string> mos = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(string w : words){
            string a = "";
            for(char c : w)
                a += mos[c-'a'];
            st.insert(a);
        }
        return st.size();
    }
};