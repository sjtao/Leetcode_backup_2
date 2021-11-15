//Runtime: 60 ms, faster than 60.57% of C++ online submissions for Count the Number of Consistent Strings.
//Memory Usage: 30.3 MB, less than 26.55% of C++ online submissions for Count the Number of Consistent Strings.

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> alw_set;
        
        for(char s: allowed){
            alw_set.insert(s);
        }
        
        int number = 0;
        bool find;
        for(auto s: words){
            find = 1;
            for(auto a: s){
                if(alw_set.count(a)==0){
                    find = 0;
                    break;
                }
            }
            if(find)
                number += 1;
        }
        
        return number;
    }
};

//Runtime: 36 ms, faster than 99.44% of C++ online submissions for Count the Number of Consistent Strings.
//Memory Usage: 30.2 MB, less than 62.02% of C++ online submissions for Count the Number of Consistent Strings.
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int> alw(26,0);
        for(int i = 0; i < allowed.length(); i++){
            alw[allowed[i]-'a'] = 1;
        }
        
        int number = 0;
        bool find;
        for(int i = 0; i < words.size(); i++){
            find = 1;
            for(int j = 0; j < words[i].length(); j++){
                if(alw[words[i][j]-'a']==0){
                    find = 0;
                    break;
                }
            }
            if(find)
                number += 1;
        }
        
        return number;
    }
};
