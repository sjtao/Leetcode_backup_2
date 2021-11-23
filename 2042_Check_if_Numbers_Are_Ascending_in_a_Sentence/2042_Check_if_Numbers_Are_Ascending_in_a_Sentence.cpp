//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.
//Memory Usage: 6.4 MB, less than 39.91% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.

class Solution {
public:
    bool isNumber(string a){
        int i = 0;
        while(i < a.length()){
            int temp = a[i] - '0';
            if(temp >= 0 && temp <= 9){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int StringToNumber(string a){
        int num = 0;
        int i = 0;
        while(i < a.length()){
            num = 10 *num + (a[i] - '0');
            i++;
        }
        return num;
    }
    
    bool areNumbersAscending(string s) {
        s.push_back(' ');
        int max = -1;
        int i = 0;
        string as = "";
        while(i < s.length()){
            if(s[i] == ' '){
                if(isNumber(as)){
                    int num = StringToNumber(as);
                    if(max < num)
                        max = num;
                    else
                        return false;
                }
                as = "";
                i++;
            }
            else{
                as += s[i];
                i++;
            }
        }
        
        return true;
    }
};
