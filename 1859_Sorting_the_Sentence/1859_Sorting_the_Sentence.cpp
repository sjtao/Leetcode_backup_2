//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sorting the Sentence.
//Memory Usage: 6.3 MB, less than 71.88% of C++ online submissions for Sorting the Sentence.

class Solution {
public:
    string sortSentence(string s) {
        vector<string> sentence(10);
        string temp_s = "";
        int i = 0;
        int count = 1;
        while(i < s.length()){
            if(s[i] == ' '){
                i++;
            }
            else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                sentence[s[i]-'0'] = temp_s;
                temp_s = "";
                count ++;
                i++;
            }
            else{
                temp_s += s[i];
                i++;
            }
        }
        string ans = "";
        for(int i = 1; i < count-1; i++){           
            ans += sentence[i];
            ans += ' ';
        }
        ans += sentence[count-1];
        return ans;
    }
};
